#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
//#define tr(it,v) for(auto it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

#if 1
	#define DEB printf
#else
	#define DEB(...)
#endif

typedef long long ll;
typedef long long LL;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int inft = 1000000009;
const int mod = 1000000007;
const int MAXN = 1000006;

map<char,int> M;
char s[MAXN];
int ile[10];
void solve() {
	scanf("%s",s);
	int n=strlen(s);
	M.clear();
	fru(i,n)M[s[i]]++;
	ile[0]=M['Z'];
	ile[6]=M['X'];
	ile[8]=M['G'];
	ile[2]=M['W'];
	ile[3]=M['H']-ile[8];
	ile[4]=M['R']-ile[3]-ile[0];
	ile[1]=M['O']-ile[0]-ile[4]-ile[2];
	ile[7]=M['S']-ile[6];
	ile[5]=M['V']-ile[7];
	ile[9]=M['I']-ile[5]-ile[6]-ile[8];
	fru(i,10)fru(j,ile[i])printf("%d",i);puts("");
}

int main() {
	int te = 1;
	scanf("%d",&te);
	fru(ti,te) {
		printf("Case #%d: ",ti+1);
		solve();
	}
	return 0;
}
