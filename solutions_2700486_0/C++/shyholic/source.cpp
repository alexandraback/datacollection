#include<cstdio>
#include<cmath>

int N, X, Y;
int idx[800];

double process(){
	int xy = (abs(X) + abs(Y)) / 2;

	if(xy > 707){
		return 0.0;
	}

	if(N <= idx[xy-1]) return 0.0;

	if(N >= idx[xy]) return 1.0;

	if(X == 0 && N < idx[xy]) return 0.0;

	int res = N - idx[xy-1];
	int osn = xy * 2;

	int s = res-osn > 0 ? res-osn : 0;
	if(s >= Y+1) return 1.0;

	int rres = res - s - s;
	int rY = Y+1 - s;

	double sol = 0;
	
	for(int si=0;si<=rres;si++){
		if(rres - si < rY) break;
		
		double p = pow(0.5, rres);
		int c = rres - si > si ? rres-si : si;

		if(si != 0){
			for(int i=c+1;i<=rres;i++){
				p = p * (double)i;
			}
			for(int i=1;i<=rres-c;i++){
				p = p / (double)i;
			}
		}

		sol = sol + p;
	}

	return sol;
}

void init(){
	int diff = 5;
	int ddiff = 4;
	int cnt = 0;
	int num = 1;
	while(true){
		idx[cnt] = num;
		num = num + diff;
		diff = diff + ddiff;
		cnt = cnt + 1;

		if(num >= pow(10.0, 6)){
			idx[cnt] = num;
			break;
		}
	}
}

int main(void){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);

	init();

	for(int i=0;i<T;i++){
		scanf("%d %d %d",&N, &X, &Y);
		double ans = process();
		printf("Case #%d: %lf\n",i+1, ans);
	}
	return 0;
}