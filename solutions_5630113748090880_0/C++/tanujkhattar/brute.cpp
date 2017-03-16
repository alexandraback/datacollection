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

VI A[21],B;
int n;
bool done[21],have[21],found;
bool cmp(int a,int b)
{
	for(int i=0;i<n;i++)
		if(A[a][i] >= A[b][i])
			return false;
	return true;
}
bool check1(VI B)
{	
	sort(ALL(B),cmp);
	for(int i=0;i<n-1;i++)
		if(!cmp(B[i],B[i+1]))
			return false;
	SET(done,0);
	int cnt = 0;VI ans;
	for(int i=0;i<n;i++)
	{
		VI c;
		for(int j=0;j<n;j++)
			c.PB(A[B[j]][i]);
		bool ok = false;
		for(int i=1;i<2*n;i++)
			if(!have[i] && !done[i] && c == A[i])
			{
				done[i]=1;ok=true;
				break;
			}
		if(!ok){cnt++;ans=c;}
		if(cnt>1)return false;
	}
	for(int i=0;i<SZ(ans);i++)printf("%d ",ans[i]);
	found=true;return true;
}
void go(int pos)
{
	if(SZ(B) > n)return;
	if(found)return;
	if(pos==2*n)
	{
		if(SZ(B)<n)return;
		check1(B);return;
	}
	go(pos+1);
	B.PB(pos);have[pos]=true;
	go(pos+1);
	B.pop_back();have[pos]=false;
}
int main()
{
	int t;si(t);
	for(int T=1;T<=t;T++)
	{
		printf("Case #%d: ",T);
		si(n);
		for(int i=1;i<2*n;i++)
		{
			A[i].clear();
			for(int j=0;j<n;j++)
			{
				int x;si(x);
				A[i].PB(x);
			}
		}
		found=false;go(1);puts("");
	}
	return 0;
}
