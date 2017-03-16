/*
ID:		ganeshk2
lang:	cpp
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long		ll;
typedef pair<int, int>	ii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<ii>		vii;
typedef vector<pll>		vpll;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
#define si(x)		scanf("%d",&x)
#define sl(x)		scanf("%I64d",&x)
#define ss(s)		scanf("%s",s)
#define pb			push_back
#define mp			make_pair
#define rep(i,b,a)  for(i=a;i<b;i++)
#define f(i,n)      rep(i,n,0)
#define tr(it,container) for(auto it=container.begin();it!=container.end();++it)
#define all(a)		a.begin(),a.end()
#define sortall(a)	sort(all(a))
#define mem(a,x)	memset(a,x,sizeof(a))
#define MOD			1000000007
#define PI          3.1415926535897932384626
#define F			first
#define S			second
#define endl		'\n'
/*
ll powe(ll a,ll b) {ll res=1;for(;b;b>>=1){if(b&(1LL))res=(res*a)%MOD;a=a*a%MOD;}return res;}
int scan_d(){
	int ip=getchar_unlocked(),ret=0,flag=1;for(;ip<'0'||ip>'9';ip=getchar_unlocked())
	if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}
	for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
ll scan_lld(){
	int ip=getchar_unlocked(),flag=1;ll ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked())
	if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}
	for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
*/

#define maxn 110

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t,testcase=1;
    cin>>t;
    while(t--)
    {
        cout<<"Case #"<<testcase++<<": ";
        int n,i,j,ans=0;
        cin>>n;
        string a[n],b[n];
        f(i,n) cin>>a[i]>>b[i];
        int max_mask=(1<<n);
        f(i,max_mask)
        {
            set<string> mys1,mys2;
            f(j,n)
            {
                if((i&(1<<j))) mys1.insert(a[j]),mys2.insert(b[j]);
            }
            int flag=0;
            f(j,n)
            {
                if(!(i&(1<<j)))
                {
                    if(mys1.find(a[j])==mys1.end() or mys2.find(b[j])==mys2.end())
                    {
                        flag=1;break;
                    }
                }
            }
            if(flag==0) ans = max(ans,n - (int)(__builtin_popcount(i)));
        }
        cout<<ans<<endl;

    }

return 0;
}