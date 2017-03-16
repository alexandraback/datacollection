#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<utility>
#include<set>
#include<stack>
#include<list>
#include<deque>
#include<bitset>
#include<iomanip>
#include<cstring>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<cmath>
#include<cctype>


#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(long long i=a;i<=b;i++)
#define ren(i,a,b) for(long long i=a;i>=b;i--)
#define ff first
#define ss second
#define pll pair<long long int,long long int>
#define pii pair<int,int>
#define vll vector<long long int>  
#define vii vector<int>
#define gi(n) scanf("%d",&n)
#define gll(n) scanf("%lld",&n)
#define gstr(n) scanf("%s",n)
#define gl(n) cin >> n
#define oi(n) printf("%d",n)
#define oll(n) printf("%lld",n)
#define ostr(n) printf("%s",n)
#define ol(n) cout << n
#define os cout<<" "
#define on cout<<"\n"
#define o2(a,b) cout<<a<<" "<<b
#define all(n) n.begin(),n.end()
#define present(s,x) (s.find(x) != s.end()) 
#define cpresent(s,x) (find(all(s),x) != s.end()) 
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
using namespace std;
 
typedef unsigned long long int ull;
typedef long long int ll;
typedef vector<vector<ll> > mat;

int pp[10005]={0};vll pr;

void seive()
{
	pp[0]=1;pp[1]=1;
	rep(i,2,10004)
	{
		if(pp[i])
		continue;
		pr.pb(i);
		for(int j=2*i;j<=10004;j+=i)
		pp[j]=1;
	}
}

int main()
{ios_base::sync_with_stdio(false);
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
seive();
int t,t1=0;
gl(t);
while(t--)
{
	t1++;
	ol("Case #");ol(t1);ol(":\n");
	pair<string,vll>ans[1005];	
	ll n,k,cnt=0;
	cin>>n>>k;
	rep(msk,0,(1ll<<(n-2))-1)
	{
		int kk=0;vll a1;
		rep(b,2,10)
		{
			tr(pr,it)
			{
				ll num=1,p1=b;
				rep(j,0,n-3)
				{
					if(msk&(1ll<<j))
					{
						num=(num+p1)%(*it);
					}
					p1*=b;
					p1%=(*it);
				}
				num=(num+p1)%(*it);
				if(num==0)
				{
					kk++;
					a1.pb(*it);
					break;
				}	
			}
		}
		if(kk==9)
		{
			cnt++;
			string s="1";
			rep(j,0,n-3)
			{
				if(msk&(1ll<<j))
				{
					s+='1';
				}
				else
				{
					s+='0';
				}
			}
			s+='1';
			reverse(all(s));
			ans[cnt-1].ff=s;
			ans[cnt-1].ss=a1;
		}
		if(cnt==k)
		break;	
	}
	rep(i,0,k-1)
	{
		ol(ans[i].ff);os;
		tr(ans[i].ss,it)
		{
			ol(*it);os;
		}
		on;
	}
}
return 0;
}
