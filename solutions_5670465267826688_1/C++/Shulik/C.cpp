#include <iostream>
#include <string>

#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

// 1 = 1, i = 2, j = 3, k = 4


int s[12345];
int l;
long long x;

int multt[4][4] = {
	{1, 2, 3, 4},
	{2, -1, 4, -3},
	{3, -4, -1, 2},
	{4, 3, -2, -1}
};

int mult(int a, int b){
	int un = 1;
	if(a < 0){
		a*=-1; un*=-1;
	}
	if(b < 0){
		b*=-1; un*=-1;
	}
	return un*multt[a-1][b-1];
}

int trans(char c){
	return c == 'i' ? 2 : c == 'j' ? 3 : 4;
}

int period(){
	int r = 1;
	int cnt = 0;
	do{
		REP(i, l)r = mult(r, s[i]);
		cnt++;
	}while(r!=1);
	return cnt;
}

bool look_for(int needle, int &i, int &pers){ //našel / nenašel
	int formi = i;
	int r = 1;
	int check = 0;
	while(r!=needle){
		r = mult(r, s[i]);
		i++;
		if(i == l){
			i = 0;
			pers++;
		}
		if(i == formi && ++check == 4)return false;
		//cout << needle << " " << r << " " << i << " " << pers <<endl;
	}
	//cout << "lf "<< needle << " " << i << " "<< pers << endl;
	return true;
}

void go_on(int testNum, bool ok, string str=""){
	cout << "Case #" << testNum+1 <<": " << (ok ? "YES" : "NO") << endl;
}

int main(){
	int tests;
	cin >> tests;
	REP(t, tests){
		string ss;
		cin >> l >> x;
		cin >> ss;
		REP(i, l){
			s[i] = trans(ss[i]);
		}
		
		int i = 0, pers = 0;
		
		//cout << period() <<endl;

		if(!look_for(2, i, pers) || !look_for(3, i, pers) || !look_for(4, i, pers)){
			go_on(t, false, "prvni");
			continue;
		}
		
		int r = 1;
		int check = 0;
		if(i != 0){
			do{
				while(i < l){
					r = mult(r, s[i]);
					i++;
				}
				i = 0;
				pers++;
				if(++check == 4)break;
			}while(r!=1);
		}
		if(r!=1){
			go_on(t, false, "druhy");
			continue;
		}
		if(pers > x){
			go_on(t, false, "treti");
			continue;
		} 
		if(((x-pers) % period()) != 0){
			go_on(t, false, "ctvrty");
			continue;
		}

		go_on(t, true);


	}

	return 0;

}
