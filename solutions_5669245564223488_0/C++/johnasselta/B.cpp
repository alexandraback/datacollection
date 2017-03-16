#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#define MAXN 107
#define MOD 1000000007LL
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

int testy,n,ile_blokow;
int dl[MAXN],next[MAXN],pop[MAXN];
char s[MAXN][MAXN];
bool bylo[MAXN];
LL res;

LL silnia(int il) {
	LL result = 1;
	FOR(i,1,il) result = (result*LL(i))%MOD;
	return result;
}

int ogarnij(int kt, char znak) {
	int ileznak = 0, lznak = -1, pznak; 
	REP(i,dl[kt]) {
		if (s[kt][i] == znak) {
			++ileznak; 
			pznak = i;
			if (lznak == -1) lznak = i;
		}
	}
	
	if (ileznak == 0) return 3;
	if (pznak - lznak != ileznak - 1) return 2;
	if (ileznak == dl[kt]) return 1;
	if (pznak == dl[kt]-1) return 0;
	if (!lznak) return -1;
	return -2; 
}

void check(char znak) {
	int pref, suf, caly;
	int ile_pref = 0, ile_suf = 0, ile_srod = 0, ilosc_calych = 0;
	FOR(i,1,n) {
		int pom = ogarnij(i,znak);
		if (pom == -2) ++ile_srod;
		if (pom == -1) {
			++ile_pref;
			pref = i;
		}
		if (pom == 0) {
			++ile_suf;
			suf = i;
		}
		if (pom == 1) {
			++ilosc_calych;
			caly = i;
		}
		if (pom == 2) res = 0;
	}
	
	if (ile_pref > 1 || ile_suf > 1 || ile_srod > 1 || (ile_srod && ile_pref+ile_suf)) res = 0;
	if (ile_pref == 1 && ile_suf == 1) {
		next[suf] = pref;
		pop[pref] = suf;
	}
	if (ile_pref == 1 && ile_suf == 0 && ilosc_calych) {
		next[caly] = pref;
		pop[pref] = caly;
	}
	if (ile_suf == 1 && ile_pref == 0 && ilosc_calych) {
		next[suf] = caly;
		pop[caly] = suf;
	}
	if (ile_suf == 0 && ile_pref == 0 && ilosc_calych) ++ile_blokow;
	res = (res*silnia(ilosc_calych))%MOD;
}

int main(){
	scanf("%d",&testy);
	FOR(g,1,testy) {
		printf("Case #%d: ",g);
	
		res = 1LL;
		scanf("%d",&n);
		ile_blokow = 0;
		FOR(i,1,n) scanf(" %s",s[i]);
		FOR(i,1,n) dl[i] = strlen(s[i]);
		FOR(i,1,n) next[i] = pop[i] = -1, bylo[i] = false;
	    
	
		FOR(i,'a','z') {
			check(i);
			//FOR(i,1,n) printf("%d %d\n",next[i],pop[i]);
		}
		
		FOR(i,1,n) if (!bylo[i] && pop[i] == -1) {
			++ile_blokow;
			int wsk = i;
			bylo[wsk] = true;
			if (next[wsk] == -1 && ogarnij(i,s[wsk][0]) == 1) --ile_blokow;
			while (next[wsk] != -1) {
				wsk = next[wsk];
				bylo[wsk] = true;
			}
		}
		res = (res*silnia(ile_blokow))%MOD;
		FOR(i,1,n) if (!bylo[i]) res = 0;
		printf("%lld\n",res);	
	}	
	return 0;
}
