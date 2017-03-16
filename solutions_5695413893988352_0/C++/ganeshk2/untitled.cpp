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
        string a,b;
        cin>>a>>b;
        int n=a.size(),i,j;
        string ans1="000",ans2="999";
        if(n==1)
        {
            f(i,10)
            {
                string c=to_string(i);
                if(a[0]!='?' and c[0]!=a[0]) continue;
                f(j,10)
                {
                    string d=to_string(j);
                    if(b[0]!='?' and d[0]!=b[0]) continue;
                    int curr = abs(ans1[0]-ans2[0]);
                    if(abs(i-j)<abs(curr)) {ans1=c;ans2=d;}
                }
            }
        }
        else if(n==2)
        {
            f(i,100)
            {
                string c=to_string(i);
                while(c.size()<2) c='0'+c;
                if(a[0]!='?' and c[0]!=a[0]) continue;
                if(a[1]!='?' and c[1]!=a[1]) continue;
                f(j,100)
                {
                    string d=to_string(j);
                    while(d.size()<2) d='0'+d;
                    if(b[0]!='?' and d[0]!=b[0]) continue;
                    if(b[1]!='?' and d[1]!=b[1]) continue;
                    int a1=ans1[0]*10+ans1[1];
                    int a2=ans2[0]*10+ans2[1];
                    if(abs(i-j)<abs(a1-a2)) {ans1=c;ans2=d;}
                }
            }
        }
        else if(n==3)
        {
            f(i,1000)
            {
                string c=to_string(i);
                while(c.size()<3) c='0'+c;
                if(a[0]!='?' and c[0]!=a[0]) continue;
                if(a[1]!='?' and c[1]!=a[1]) continue;
                if(a[2]!='?' and c[2]!=a[2]) continue;
                f(j,1000)
                {
                    string d=to_string(j);
                    while(d.size()<3) d='0'+d;
                    if(b[0]!='?' and d[0]!=b[0]) continue;
                    if(b[1]!='?' and d[1]!=b[1]) continue;
                    if(b[2]!='?' and d[2]!=b[2]) continue;
                    int a1=ans1[0]*100+ans1[1]*10+ans1[2];
                    int a2=ans2[0]*100+ans2[1]*10+ans2[2];
                    if(abs(i-j)<abs(a1-a2)) {ans1=c;ans2=d;}
                }
            }

        }
        cout<<ans1<<" "<<ans2<<endl;

    }

return 0;
}