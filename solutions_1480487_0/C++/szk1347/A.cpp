#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
int T,N;
int s[201];
double y[201];
int sum;

int main(){
	freopen("A_in.txt","r",stdin);
	freopen("A_out.txt","w",stdout);
	cin >> T;
	for(int cas = 1;cas <= T;++cas){
		memset(s,0,sizeof(s));
		cin >> N;
		sum = 0;
		for(int i = 1;i <= N;++i){
			cin >> s[i];
			sum += s[i];
		}
		for(int i = 1;i <= N;++i){
			y[i] = 1e-9 +
				(double(2*sum - N*s[i])/double(N*sum));
			if(y[i] < 0)
				y[i] = 0;
			y[i] *= 100;
		}
		printf("Case #%d: ",cas);
		for(int i = 1;i <= N - 1;++i)
			printf("%lf ",y[i]);
		printf("%lf\n",y[N]);
	}
	return 0;
}

