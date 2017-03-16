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
vector<string> ar;
int main()
{	DRT()
	{	ar.clear();
		int b;LL m;
		cin>>b>>m;
		cout<<"Case #"<<t1<<": ";
		if((1LL<<(b-2))<m)
		{	cout<<"IMPOSSIBLE\n";
			continue;
		}
		else
			cout<<"POSSIBLE\n";
		ar.resize(b);
		f(i,0,b)
			f(j,0,b)
				if(j>i)
					ar[i].pb('1');
				else
					ar[i].pb('0');
		m--;
		f(i,1,b-1)
			if((1LL<<(b-2-i))>m)
				ar[0][i]='0';
			else 
				m-=(1LL<<(b-2-i));
		f(i,0,b)
			cout<<ar[i]<<endl;
	}
}


