#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#define MAXN
#define INF
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
typedef long double LD;

int test;
int n,x,y,ile,ilosc,poziom,ile_dziel;
LD wynik,pom;

bool jest(int x, int y, int poz) {
	int suma = y;
	if (x > 0) suma += x; else suma -= x;
	suma /= 2;
	return suma <= poz-1;
}

int main() {
	scanf("%d",&test);
	FOR(g,1,test) {
		printf("Case #%d: ",g);
		scanf("%d%d%d",&n,&x,&y);
		ile = 1;
		poziom = 0;
		while (ile <= n) {
			++poziom;
			n -= ile;
			ile += 4;
		}
		if (jest(x,y,poziom)) puts("1.0");
		 else if (!jest(x,y,poziom+1)) puts("0.0");
			else if (x == 0) puts("0.0");
				else {
					ilosc = y+1;
					if (ilosc > n) puts("0.0");
						else {
								if (n >= 2*poziom+ilosc) puts("1.0");
								else { 
									wynik = 0.0;
									FOR(i,ilosc,n) {
										pom = 1.0;
										ile_dziel = n;
									
										FOR(j,i+1,n) {
											pom *= LD(j);
											while (ile_dziel && pom > 1.0) {
												pom /= 2.0;
												--ile_dziel;
											}
										}
										FOR(j,1,n-i) pom /= LD(j);
										while (ile_dziel) {
											pom /= 2.0;
											--ile_dziel;
										}
										wynik += pom;
									}
									
									printf("%.10Lf\n",wynik);
								}
							}
				}
	}
	return 0;
}
