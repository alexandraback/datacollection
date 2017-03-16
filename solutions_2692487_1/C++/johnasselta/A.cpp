#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#define MAXN 100
#define INF 100000000
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

int test,a,n,poz,result,stan;
int tab[MAXN];

int main(){	
	scanf("%d",&test);
	FOR(g,1,test) {
		scanf("%d%d",&a,&n);
		REP(i,n) scanf("%d",&tab[i]);
		if (a == 1) {
			printf("Case #%d: %d\n",g,n);
		}
		else {
			sort(tab,tab+n);
			poz = 0;
			stan = 0;
			result = INF;
			while (poz < n) {
				if (tab[poz] < a) {
					a += tab[poz];
					++poz;
				}
				else {
					result = min(result,stan+n-poz);
					a = a+a-1;
					++stan;
				}
			}
			printf("Case #%d: %d\n",g,min(stan,result));
		}
	}
	return 0;
}
