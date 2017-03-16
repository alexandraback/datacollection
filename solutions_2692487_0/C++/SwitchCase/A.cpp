// <-------------------[sWitCHcAsE]---------------------->
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<cassert>
#include<vector>
#include<map>
#include<cstring>
#include<cassert>
#include<queue>

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORS(i,a,n) for(int i=a;i<n;i++)
#define FORR(i,a) for(int i=a;i>=0;i--)
#define foreach(it, x) for(typeof(x.begin()) it = x.begin(); it!=x.end();it++)
#define ERR(x) cerr<<#x<<" "<<x<<endl
#define pb push_back
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;

typedef vector<int> VI;
typedef long long ll;
typedef long double ld;

inline int print(int d) { return printf("%d",d);}
inline int read(int &d) { 
	d=0;
	int sign=1,ch;
	while((ch<'0'||ch>'9') && ch!='-' && ch!=EOF)ch=getchar_unlocked();
	if(ch=='-')
		sign=-1, ch=getchar_unlocked();
	do 
		d=(d<<3)+(d<<1)+ch-'0';
	while((ch=getchar_unlocked())>='0' && ch<='9');
	d*=sign;
	return 1;
}

int v[105];
int dp[105][2];

int main(int argc,char** args) 
{
	int tc;read(tc);FOR(tests,tc) {
		cout<<"Case #"<<tests+1<<": ";
		int A,N;
		scanf("%d %d",&A, &N);
		FOR(i,N)scanf("%d",&v[i]);

		sort(v,v+N);
		int i = 0;
		int cA = A;
		int ans = N;
		int tans = 0;
		int remans = N;
		memset(dp, 63,sizeof dp);
		FOR(i,N) dp[i][1] = N;
/*		for(;i<N;i++) {
			tans = 0;
			if (cA>v[i]) {cerr<<"added "<<v[i]<<" since cA is "<<cA<<endl;cA+=v[i]; dp[i][0] = dp[i-1][0];}
			else {
				cerr<<"If removed from "<<i<<" ans is "<<tans+(N-i)<<endl;
				while(v[i]>=cA && cA>1) {
					tans++;
					cerr<<"due to index "<<i<<" Added "<<cA-1<<endl;
					cA += (cA-1);
				}
				if ( cA>v[i]) {
					cA+=v[i];
					if ( i >0) {dp[i][0] = tans + dp[i-1][0]; dp[i][1] = min(dp[i][1], dp[i-1][0] + (N-i));}
					else dp[i][0] = min(tans, N), dp[i][1] = N;
				}

			}
		}
		ans = min(dp[N-1][1],dp[N-1][0]);*/
		int pans=0;
		for(;i<N;i++) {
			 tans = 0;
             if (cA>v[i]) {cerr<<"added "<<v[i]<<" since cA is "<<cA<<endl;cA+=v[i]; dp[i][0] = dp[i-1][0];}
			 else {
				 while(v[i]>=cA && cA>1) {
					 tans++;
					 cerr<<"due to index "<<i<<" Added "<<cA-1<<endl;
					 cA+=(cA-1);
				 }
				 cA+=v[i];
				 if ( tans >0) {
					if ( tans > N-i) {
						pans +=N-i;
					}
					else {
						pans +=tans;
					}
				 }
				 else {
					 pans += N-i;
					 break;
				 }
			 }
		}
		cerr<<"pasn is "<<pans<<endl;
		ans = min(ans, pans);
		cout<<ans<<endl;


	}
}
