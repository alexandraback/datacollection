#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),(a).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define repp(i,a,n) for(int i=(a);i<(n);i++)
#define dec(i,n) for(int i=(n);i>0;i--)
#define decc(i,a,n) for(int i=(a);i>(n);i--)
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))
#define mem(a,b) memset((a),(b),sizeof(a))
#define clr(a) mem(a,0)
const double pi=acos(-1.0);
const int inf=10000000;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;
typedef vector< string > VS;
typedef vector< ll > VLL;
#define eps 1e-9
//main code starts here
#define max 1000005
bool vow[26];
char s[max];
int l;
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    clr(vow);
    vow[0]=vow['e'-'a']=vow['i'-'a']=vow['o'-'a']=vow['u'-'a']=1;
	int t,cas=1;
	cin>>t;
	while(t--)
	{
	    scanf("%s",s);
	    scanf("%d",&l);
	    ll ans=0;
	    int n=strlen(s);
	    ll c=0;
	    ll last=0;
	    rep(i,n)
	    {
	        if(!vow[s[i]-'a'])c++;
	        else c=0;
	        if(c>=l)
	        {
	            //if(on)ans++;
	            ans+=((ll)i+2-l);
	            last=((ll)i+2-l);
	        }
	        else
	        {
	            ans+=last;
	        }
	    }
	    printf("Case #%d: %lld\n",cas++,ans);
	}
	return 0;
}
