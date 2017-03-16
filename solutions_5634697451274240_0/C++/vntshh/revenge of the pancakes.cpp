//Author: Vineet Shah
//IIT Indore
#include<bits/stdc++.h>
#define rep(i,start,lim) for(long long i=start;i<lim;i++)
#define repd(i,start,lim) for(long long i=start;i>=lim;i--)
#define MOD 1000000007
#define scan(x) scanf("%lld",&x)
#define print(x) printf("%lld",x)
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define br printf("\n")
#define bit(x,i) (x&(1<<i))
using namespace std;
typedef long long lld;
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	lld tol=0,t,ans,k;
	cin>>t;
	rep(ttt,1,t+1)
	{
		string x;
		cin>>x,ans=0;
		k=x.size(),tol=0;
		rep(i,0,k)
		{
			if(x[i]=='-' && i==0) ans+=1;
			else if(x[i]=='-' && i>=1 && x[i-1]!='-') ans+=2;
		}
		printf("Case #%lld: %lld\n",ttt,ans);
	}
	
	
	return 0;
}


