#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

typedef long long ll;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int inft = 1000000009;
const int MAXN = 1000006;//10^6

void solve() {
	int n,maxi=0;
	scanf("%d",&n);
	vi V;	
	fru(i,n)
	{
		int a;
		scanf("%d",&a);
		V.pb(a);
		maxi=max(maxi,a);
	}
	int ans=maxi;
	fru(i,maxi+1)if(i)
	{
		int ile=0;
		fru(j,n)ile+=(V[j]-1)/i;
		ans=min(ans,ile+i);
	}
	printf("%d\n",ans);
}

int main(){
	int t=1;scanf("%d",&t);
	fru(i,t)
	{
		printf("Case #%d: ",i+1);
		solve();
	}
	return 0;
}

