#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#define MAXN
#define PB push_back
#define MP make_pair
#define ST first
#define ND second

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(a,b,c) for(int a=b;a<=(c);a++)
#define FORD(a,b,c) for (int a=b;a>=(c);a--)
#define VAR(v,n) __typeof(n) v=(n)
#define ALL(c) c.begin(),c.end()
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();i++)

using namespace std;

typedef long long LL;  

int test;
double c,f,x,v,res,czas;

int main(){
	scanf("%d",&test);
	FOR(g,1,test) {
		printf("Case #%d: ",g);
		scanf("%lf%lf%lf",&c,&f,&x);
		v = 2.0;
		res = x/v;
		czas = 0.0;
		while (czas + c/v < res) {
			czas += c/v;
			v += f;
			res = min(res,czas + x/v);
		}
		printf("%.7lf\n",res);
	}
	return 0;
}
