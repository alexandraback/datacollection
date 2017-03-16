#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
#include<assert.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define REP(i,n) FOR(i,0,(n)-1)
#define RI(i,n) FOR(i,1,n)
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 300;

int testy, k, cel, dl;
int ile[nax], pref[nax];
ld prawd[nax][nax][nax];
char klawka[nax], slowo[nax];

int main(int argc, char * argv[]) {
	debug = argc > 1;
	scanf("%d",&testy);
	FOR(g,1,testy) {
		scanf("%d%d%d",&k,&cel,&dl);
		scanf(" %s %s",klawka,slowo);
		
		REP(i,26) ile[i] = 0;
		REP(i,k)
			++ile[klawka[i] - 'A'];
		
		bool dasie = (ile[slowo[0] - 'A'] != 0);
		int t = 0;
		pref[0] = 0;
		slowo[cel] = '#';
		FOR(i,1,cel-1) {
			if (ile[slowo[i] - 'A'] == 0)
				dasie = false;
				
			while (slowo[i] != slowo[t] && t)
				t = pref[t-1];
			
			if (slowo[i] == slowo[t]) ++t;
			pref[i] = t;
		}
		
		if (!dasie) {
			printf("Case #%d: %.10lf\n",g,0.);
			continue;
		}
		
		ld res = 1 + (dl-cel)/(cel - pref[cel-1]);
		
		FOR(i,0,dl) FOR(j,0,dl) FOR(kk,0,dl) prawd[i][j][kk] = 0.0;
		prawd[0][0][0] = 1.0;
		FOR(poz,0,dl-1) FOR(wyn,0,poz) FOR(pre, 0, min(poz,cel)) {
			//if (prawd[poz][wyn][pre] > 1e-5)
			//	printf("szansa ze na dlugosci %d bedzie wynik %d oraz prefiks o dlugosci %d to %.10Lf\n",poz,wyn,pre,prawd[poz][wyn][pre]);
			REP(i,26) {
				t = pre;
				while ('A' + i != slowo[t] && t != 0)
					t = pref[t-1];
				
				if ('A' + i == slowo[t])
					++t;
				
				if (t == cel)
					prawd[poz+1][wyn+1][t] += (prawd[poz][wyn][pre] * (ld)ile[i])/(ld)(k);
				else
					prawd[poz+1][wyn][t] += (prawd[poz][wyn][pre] * (ld)ile[i])/(ld)(k);	
			}
		}
		
		FOR(wyn,0,dl) FOR(pre, 0, cel)
			res -= prawd[dl][wyn][pre] * (ld)wyn;
		printf("Case #%d: %.10Lf\n",g,res);
	}
	return 0;
}
