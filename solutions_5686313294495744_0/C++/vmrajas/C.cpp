//Vanjape Rajas Mangesh

#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))

#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

string s1[20],s2[20];
set<string> pe1,pe2,tp1,tp2;
int main()
{
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		pe1.clear();pe2.clear();
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>s1[i]>>s2[i];
			pe1.insert(s1[i]);
			pe2.insert(s2[i]);
		}
		int po=1;
		for(int i=0;i<n;i++)
			po*=2;
		int ans=0;
		for(int bi=0;bi<po;bi++)
		{
			tp1.clear();
			tp2.clear();
			int temp=bi;
			int ct=0;
			for(int i=0;i<n;i++)
			{
				if(temp%2)
				{
					tp1.insert(s1[i]);
					tp2.insert(s2[i]);
				}
				else
					ct++;
				temp/=2;
			}
			if(SZ(tp1)==SZ(pe1)&&SZ(tp2)==SZ(pe2)&&ct>ans)
				ans=ct;
		}
		cout<<"Case #"<<t<<": "; 
		cout<<ans<<"\n";
	}
	return 0;
}
