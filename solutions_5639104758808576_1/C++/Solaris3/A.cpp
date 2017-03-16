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

char s[MAXN];
void solve() {
	int n;
	scanf("%d%s",&n,s);
	int ile=0,sum=0;
	fru(i,n+1)
	{
		ile+=max(0,i-sum);
		sum=max(sum,i);
		sum+=s[i]-'0';
	}
	printf("%d\n",ile);
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

