#include "headers.h"

char x[20], y[20], cx[20], cy[20];
int n;

void copy(){
	REP(i,n){
		cx[i] = x[i];
		cy[i] = y[i];
	}
}

void equalize(int pos, int end){
	if(pos < 0) pos = 0;
	FOR(i, pos, end){
		if(cx[i] == '?' && cy[i] == '?') cx[i] = cy[i] = '0';
		else if(cx[i] != '?' && cy[i] == '?') cy[i] = cx[i];
		else if(cx[i] == '?' && cy[i] != '?') cx[i] = cy[i];
	}
}

void maximize(int pos){
	if(pos < 0) pos = 0;
	FOR(i, pos, n-1){
		if(cx[i] == '?') cx[i] = '9';
		if(cy[i] == '?') cy[i] = '0';
	}
}

void minimize(int pos){
	if(pos < 0) pos = 0;
	FOR(i, pos, n-1){
		if(cx[i] == '?') cx[i] = '0';
		if(cy[i] == '?') cy[i] = '9';
	}
}

unsigned long long getVal(char *t){
	unsigned long long res = 0;
	REP(i, n){
		res *= 10;
		res += (t[i] - '0');
	}
	return res;
}
unsigned long long bestDif, bestX, bestY;

void compareSolution(char *p, char *q){
	unsigned long long vx = getVal(p);
	unsigned long long vy = getVal(q);
	unsigned long long dif;
	if(vx > vy){
		dif = vx - vy;
	}
	else{
		dif = vy - vx;
	}

	if(dif < bestDif){
		bestDif = dif;
		bestX = vx;
		bestY = vy;
	}
	else if(dif == bestDif){
		if(vx < bestX){
			bestDif = dif;
			bestX = vx;
			bestY = vy;
		}
	}
}

int main(){
	int T;
	string a, b;
	cin >> T;
	REP(t, T){
		cin >> a >> b;
		n = a.size();
		int firstDif = -1;
		REP(i, n){
			x[i] = a[i];
			y[i] = b[i];
			if(a[i] != '?' && b[i] != '?' && a[i] != b[i] && firstDif == -1){
				firstDif = i;
			}
		}
		copy();

		bool maxX = true;
		if(firstDif == -1){
			equalize(0, n-1);
			bestX = getVal(cx);
			bestY = getVal(cy);
		}
		else{
			int fd = firstDif;
			copy();
			equalize(0,fd - 1);
			if(cx[fd] > cy[fd] ){
				minimize(fd + 1);
				bestX = getVal(cx);
				bestY = getVal(cy);
				bestDif = bestX - bestY;
			}
			else{
				maximize(fd+1);
				bestX = getVal(cx);
				bestY = getVal(cy);
				bestDif = bestY - bestX;
			}

			copy();
			equalize(0,fd - 1);
			FORD(i, fd-1 , 0){
				if(cx[fd] > cy[fd] && cx[i] < '9'){
					cx[i]++;
					break;
				}
				if(cx[fd] < cy[fd] && cy[i] < '9'){
					cy[i]++;
					break;
				}
			}
			if(cx[fd] > cy[fd]){
					maximize(fd+1);
					compareSolution(cx, cy);
			}
			else{	
					minimize(fd+1);
					compareSolution(cx, cy);
			}
		}
		
		cout << "Case #" << t+1 << ": ";
		int c1 = 0;
		int c2 = 0;
		unsigned long long tmp1 = bestX;
		unsigned long long tmp2 = bestY;
		while(tmp1){
			c1++;
			tmp1/=10;
		}
		while(tmp2){
			c2++;
			tmp2/=10;
		}
		REP(i,n-c1) cout << "0";
		if(bestX != 0)cout << bestX;
		cout << " ";
		REP(i,n-c2) cout << "0";
		if(bestY != 0)cout << bestY;
		cout << endl;
	}
}
