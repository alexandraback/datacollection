//Tanuj Khattar
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

string f[20],s[20];
int n,ans;
int get(int mask){
	set<string> ff,ss;
	for(int i=0;i<n;i++)
		if(!((1<<i)&mask)){
			if(ff.count(f[i]) && ss.count(s[i]))return 0;
			ff.insert(f[i]),ss.insert(s[i]);
		}
	int ret=0;
	for(int i=0;i<n;i++)
		if((1<<i)&mask){
			if(!(ff.count(f[i]) && ss.count(s[i])))return 0;
			ret++;
		}
	return ret;
}
void solve(int i,int mask){
	if(i==n){
		ans = max(ans,get(mask));
		return;
	}
	solve(i+1,mask);
	solve(i+1,mask|(1<<i));
}
int main()
{
	int t;si(t);
	for(int T=1;T<=t;T++){
		printf("Case #%d: ",T);
		si(n);
		for(int i=0;i<n;i++)cin>>f[i]>>s[i];
		solve(0,0);
		cout<<ans<<endl;
		ans = 0;
	}
	return 0;
}
