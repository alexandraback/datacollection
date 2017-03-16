#include<bits/stdc++.h>
#define LOCAL
#define DEBUG
#define si(n) scanf("%d",&n)
#define sl(n) cin>>n
#define sf(n) scanf("%f",&n)
#define pn(n) printf("%d\n",n)
#define ps(n) printf("%d ",n)
#define pln(n) cout<<n<<endl
#define pnl() printf("\n")
#define pls(n) cout<<n<<" "
#define pl(n) cout<<n
#define FOR(i,j,n) for(i=j;i<=n;i++)
#define FORR(i,j,n) for(i=j;i>=n;i--)
#define SORT(n) std::sort(n.begin(),n.end())
#define FILL(n,a) std::fill(n.begin(),n.end(),a)
#define ALL(n) n.begin(),n.end()
#define rsz resize
#define pb push_back
#define MAXINT std::numeric_limits<int>::max()
#define MININT std::numeric_limits<int>::min()
#define getchar gc
#define putchar pc
#define iOS std::ios_base::sync_with_stdio(false)
#define endl "\n"
#ifdef DEBUG
    #define debug(x) cout << #x << " = " << x << endl
#else
    #define debug(x)
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvl;
typedef pair<int,int> pii;
 
/**************** TEMPLATE ENDS HERE *************************/
const int MAXC=26;
const int MAXD=10;
int cnt[MAXC];
int ans[MAXD];
void getAns() {
	int ind=0;
	while(ind<10) {
		while(ans[ind]>0) {
			printf("%d",ind);
			ans[ind]--;
		}
		ind++;
	}
	pnl();
}
int main() {
	int t,tt,i;si(t);
	string s;
	FOR(tt,1,t) {
		cin>>s;
		int n=s.size();
		memset(cnt,0,sizeof(cnt));
		FOR(i,0,n-1) cnt[s[i]-'A']++;
		//FOR(i,0,MAXC-1) cout<<cnt[i]<<" ";
		//pnl();
		memset(ans,0,sizeof(ans));
		ans[6]=cnt['X'-'A'];
		cnt['X'-'A']-=ans[6];
		cnt['S'-'A']-=ans[6];
		cnt['I'-'A']-=ans[6];
		ans[0]=cnt['Z'-'A'];
		cnt['Z'-'A']-=ans[0];
		cnt['E'-'A']-=ans[0];
		cnt['R'-'A']-=ans[0];
		cnt['O'-'A']-=ans[0];
		ans[2]=cnt['W'-'A'];
		cnt['W'-'A']-=ans[2];
		cnt['T'-'A']-=ans[2];
		cnt['O'-'A']-=ans[2];
		ans[8]=cnt['G'-'A'];
		cnt['G'-'A']-=ans[8];
		cnt['E'-'A']-=ans[8];
		cnt['I'-'A']-=ans[8];
		cnt['H'-'A']-=ans[8];
		cnt['T'-'A']-=ans[8];
		ans[7]=cnt['S'-'A'];
		cnt['S'-'A']-=ans[7];
		cnt['E'-'A']-=ans[7];
		cnt['V'-'A']-=ans[7];
		cnt['E'-'A']-=ans[7];
		cnt['N'-'A']-=ans[7];
		ans[5]=cnt['V'-'A'];
		cnt['V'-'A']-=ans[5];
		cnt['F'-'A']-=ans[5];
		cnt['I'-'A']-=ans[5];
		cnt['E'-'A']-=ans[5];
		ans[4]=cnt['F'-'A'];
		cnt['F'-'A']-=ans[4];
		cnt['O'-'A']-=ans[4];
		cnt['U'-'A']-=ans[4];
		cnt['R'-'A']-=ans[4];
		ans[3]=cnt['T'-'A'];
		cnt['T'-'A']-=ans[3];
		cnt['H'-'A']-=ans[3];
		cnt['R'-'A']-=ans[3];
		cnt['E'-'A']-=ans[3];
		cnt['E'-'A']-=ans[3];
		ans[1]=cnt['O'-'A'];
		cnt['O'-'A']-=ans[1];
		cnt['N'-'A']-=ans[1];
		cnt['E'-'A']-=ans[1];
		ans[9]=cnt['I'-'A'];
		cnt['I'-'A']-=ans[9];
		cnt['N'-'A']-=ans[9];
		cnt['N'-'A']-=ans[9];
		cnt['E'-'A']-=ans[9];
		/*
		FOR(i,0,MAXC-1) if(cnt[i]>0) {
			char c=i+'A';
			debug(c);
			assert(false);
		}
		*/
		//FOR(i,0,MAXD-1) cout<<ans[i]<<" ";
		//pnl();
		printf("Case #%d: ",tt);
		getAns();
	}
	return 0;
}