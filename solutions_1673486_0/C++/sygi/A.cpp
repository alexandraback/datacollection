//Jakub Sygnowski
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<sstream>
//#include<gmp.h> // http://gmplib.org/
//#include<gmpxx.h>
using namespace std;
#define FOR(I,A,B) for(int I=(A);I<=(B);I++)
#define REP(I,N) for(int I=0;I<(N);I++)
#define ALL(X) (X).begin(),(X).end()
#define ST first
#define ND second
#define INF 1000000007
#define PB push_back
#define MP make_pair
typedef pair<int,int> PII;
typedef long long LL;

int t;
double p[1000007], res;
int a, b;
int main(){
	scanf("%d",&t);
	REP(nr,t){
		printf("Case #%d: ",nr+1);
		scanf("%d%d",&a,&b);
		REP(i, a){ scanf("%lf",&p[i]); }
		for(int i = 1 ; i < a; i++) p[i] *= p[i-1];
		res = min(b+2.0, p[a-1] * (b-a+1) + (1-p[a-1]) * (b-a + 1 + b+1));
		for(int c = 1; c <= a; c++){
			res = min(res, (c + b-a +c +1) * p[a-1-c] + (1-p[a-1-c])* (c+b-a+c+1+b+1));
		}
		printf("%lf\n",res);
	}
}
