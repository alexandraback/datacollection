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

int F[11];
bool check(VI A)
{
	A.PB(A[0]);
	for(int i=0;i<SZ(A)-1;i++)
	{
		if(i && (!(F[A[i]] == A[i-1] || F[A[i]] == A[i+1])))return false;
		if(!i && !(F[A[i]] == A[i+1]))return false;
	}
	return true;
}
int ans,n;VI A;
void go(int pos)
{
	if(pos==n+1)
	{
		if(SZ(A)<=1)return;
		VI B = A;
		sort(ALL(B));
		do{
			if(check(B)){ans = max(ans,SZ(B));break;}
		}while(next_permutation(ALL(B)));
		return;
	}
	go(pos+1);
	A.PB(pos);
	go(pos+1);
	A.pop_back();
}
int main()
{
	int t;si(t);
	for(int T=1;T<=t;T++)
	{
		printf("Case #%d: ",T);
		si(n);ans = 0;
		for(int i=1;i<=n;i++)
			si(F[i]);
		A.clear();
		go(1);dout(ans);
	}
	return 0;
}
