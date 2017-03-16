#include<bits/stdc++.h>
#define f(i,a,n) for(int i=a;i<n;i++)
#define S second
#define F first
#define Sc(n) scanf("%lld",&n)
#define scc(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define sp(a) scanf("%lld %lld",&a.first,&a.second)
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define all(a) a.begin(),a.end()
#define sc(n) scanf("%d",&n)
#define It iterator
#define SET(a,b) memset(a,b,sizeof(a))
#define DRT()  int t,t1=0; cin>>t; while(t1++<t)
// inbuilt functions
// __gcd,  __builtin_ffs,     (returns least significant 1-bit, __builtin_ffsll(1)=1)
// __builtin_clz,             (returns number of leading zeroes in 
// __builtin_popcount,
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> vi;
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define trv(s,it) for(auto it:s)
map<PII,int> m1,m2,m3;
stack<pair<PII,int> > st;
int main()
{	DRT()
	{     cout<<"Case #"<<t1<<": ";
		m1.clear();
		m2.clear();
		m3.clear();
		int an=0;
		int j,p,s,k;
		cin>>j>>p>>s>>k;
		f(a,0,j)
			f(b,0,p)
				m1[mp(a,b)]=0;
		f(a,0,j)
			f(b,0,s)
				m2[mp(a,b)]=0;
		f(a,0,p)
			f(b,0,s)
				m3[mp(a,b)]=0;
		f(a,0,j)
			f(b,0,p)
				f(c,0,s)
					if(m1[mp(a,b)]<k && m2[mp(a,c)]<k && m3[mp(b,c)]<k)
					{	st.push(mp(mp(a,b),c));
						an++;
						m1[mp(a,b)]++;
						m2[mp(a,c)]++;
						m3[mp(b,c)]++;
					}
		cout<<an<<endl;
		pair<PII,int> tmp;
		while(!st.empty())
		{	tmp=st.top();
			cout<<tmp.F.F+1<<" "<<tmp.F.S+1<<" "<<tmp.S+1<<endl;
			st.pop();
		}
	}
}


