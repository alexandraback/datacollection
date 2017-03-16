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
        string s;
        cin>>s;
        int n=s.size(),i;
        multiset<char> mys;
        f(i,n) mys.insert(s[i]);
        vi ans;
        while(!mys.empty() and mys.find('Z')!=mys.end())
        {
            auto it=mys.find('Z');
            mys.erase(it);
             it=mys.find('E');
            mys.erase(it);
             it=mys.find('R');
            mys.erase(it);
             it=mys.find('O');
            mys.erase(it);
            ans.pb(0);
        }
        while(!mys.empty() and mys.find('G')!=mys.end())
        {
            auto it=mys.find('E');
            mys.erase(it);
             it=mys.find('I');
            mys.erase(it);
             it=mys.find('G');
            mys.erase(it);
             it=mys.find('H');
            mys.erase(it);
             it=mys.find('T');
            mys.erase(it);
            ans.pb(8);
        }
        while(!mys.empty() and mys.find('X')!=mys.end())
        {
            auto it=mys.find('S');
            mys.erase(it);
             it=mys.find('I');
            mys.erase(it);
             it=mys.find('X');
            mys.erase(it);
            ans.pb(6);
        }
        while(!mys.empty() and mys.find('S')!=mys.end())
        {
            auto it=mys.find('S');
            mys.erase(it);
             it=mys.find('E');
            mys.erase(it);
             it=mys.find('V');
            mys.erase(it);
             it=mys.find('E');
            mys.erase(it);
             it=mys.find('N');
            mys.erase(it);
            ans.pb(7);
        }
        while(!mys.empty() and mys.find('V')!=mys.end())
        {
            auto it=mys.find('F');
            mys.erase(it);
             it=mys.find('I');
            mys.erase(it);
             it=mys.find('V');
            mys.erase(it);
             it=mys.find('E');
            mys.erase(it);
            ans.pb(5);
        }
        while(!mys.empty() and mys.find('F')!=mys.end())
        {
            auto it=mys.find('F');
            mys.erase(it);
             it=mys.find('O');
            mys.erase(it);
             it=mys.find('U');
            mys.erase(it);
             it=mys.find('R');
            mys.erase(it);
            ans.pb(4);
        }
        while(!mys.empty() and mys.find('R')!=mys.end())
        {
            auto it=mys.find('T');
            mys.erase(it);
             it=mys.find('H');
            mys.erase(it);
             it=mys.find('R');
            mys.erase(it);
             it=mys.find('E');
            mys.erase(it);
             it=mys.find('E');
            mys.erase(it);
            ans.pb(3);
        }
        while(!mys.empty() and mys.find('I')!=mys.end())
        {
            auto it=mys.find('N');
            mys.erase(it);
             it=mys.find('I');
            mys.erase(it);
             it=mys.find('N');
            mys.erase(it);
             it=mys.find('E');
            mys.erase(it);
            ans.pb(9);
        }
        while(!mys.empty() and mys.find('W')!=mys.end())
        {
            auto it=mys.find('T');
            mys.erase(it);
             it=mys.find('W');
            mys.erase(it);
             it=mys.find('O');
            mys.erase(it);
            ans.pb(2);
        }
        while(!mys.empty() and mys.find('O')!=mys.end())
        {
            auto it=mys.find('O');
            mys.erase(it);
            it=mys.find('N');
            mys.erase(it);
            it=mys.find('E');
            mys.erase(it);
            ans.pb(1);
        }
        sortall(ans);
        f(i,ans.size()) cout<<ans[i];cout<<endl;

    }

return 0;
}