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

LL mianownik = (1LL<<40);
LL p,q;
int testy,res,dl;
char s[1000];

LL nwd(LL a, LL b) {
	return a ? nwd(b%a,a) : b;
}

LL magic(LL x) {
	return x-(x&(x-1));
}

int main(){
	scanf("%d",&testy);
	FOR(g,1,testy) {
		printf("Case #%d: ",g);
		scanf(" %s",s);
		dl = strlen(s);
		p = q = 0;
		int wsk = 0;
		while (s[wsk] != '/') {
			p = p*10LL + s[wsk]-'0';
			++wsk;
		}
		
		++wsk;
		while (wsk < dl) {
			q = q*10LL + s[wsk]-'0';
			++wsk;
		}
			
		LL pom = nwd(p,q);
		p /= pom; q /= pom;
		
		if (magic(q) != q) 
			puts("impossible");
		else {
			p *= (mianownik/q);
			res = 41;
			while (p) {
				p /= 2;
				--res;
			}
			printf("%d\n",res);
		}
	}
	return 0;
}
