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

int cnt[26],ans[11];
int idx(char c){
	return c-'A';
}
int main()
{
	int T;si(T);
	for(int t=1;t<=T;t++){
		printf("Case #%d: ",t);
		string s;cin>>s;
		for(auto c:s)
			cnt[c-'A']++;
		//zero
		cnt[idx('E')]-=cnt[idx('Z')];
		cnt[idx('R')]-=cnt[idx('Z')];
		cnt[idx('O')]-=cnt[idx('Z')];
		ans[0]+=cnt[idx('Z')];
		cnt[idx('Z')]-=cnt[idx('Z')];
		//two
		cnt[idx('T')]-=cnt[idx('W')];
		cnt[idx('O')]-=cnt[idx('W')];
		ans[2]+=cnt[idx('W')];
		cnt[idx('W')]-=cnt[idx('W')];
		//four
		cnt[idx('F')]-=cnt[idx('U')];
		cnt[idx('O')]-=cnt[idx('U')];
		cnt[idx('R')]-=cnt[idx('U')];
		ans[4]+=cnt[idx('U')];
		cnt[idx('U')]-=cnt[idx('U')];
		//five
		cnt[idx('I')]-=cnt[idx('F')];
		cnt[idx('V')]-=cnt[idx('F')];
		cnt[idx('E')]-=cnt[idx('F')];
		ans[5]+=cnt[idx('F')];
		cnt[idx('F')]-=cnt[idx('F')];
		//six
		cnt[idx('S')]-=cnt[idx('X')];
		cnt[idx('I')]-=cnt[idx('X')];
		ans[6]+=cnt[idx('X')];
		cnt[idx('X')]-=cnt[idx('X')];
		//seven
		cnt[idx('S')]-=cnt[idx('V')];
		cnt[idx('E')]-=cnt[idx('V')];
		cnt[idx('E')]-=cnt[idx('V')];
		cnt[idx('N')]-=cnt[idx('V')];
		ans[7]+=cnt[idx('V')];
		cnt[idx('V')]-=cnt[idx('V')];
		//eight
		cnt[idx('E')]-=cnt[idx('G')];
		cnt[idx('I')]-=cnt[idx('G')];
		cnt[idx('H')]-=cnt[idx('G')];
		cnt[idx('T')]-=cnt[idx('G')];
		ans[8]+=cnt[idx('G')];
		cnt[idx('G')]-=cnt[idx('G')];
		//three
		cnt[idx('T')]-=cnt[idx('H')];
		cnt[idx('R')]-=cnt[idx('H')];
		cnt[idx('E')]-=cnt[idx('H')];
		cnt[idx('E')]-=cnt[idx('H')];
		ans[3]+=cnt[idx('H')];
		cnt[idx('H')]-=cnt[idx('H')];
		//one
		cnt[idx('N')]-=cnt[idx('O')];
		cnt[idx('E')]-=cnt[idx('O')];
		ans[1]+=cnt[idx('O')];
		cnt[idx('O')]-=cnt[idx('O')];
		//nine
		cnt[idx('N')]-=cnt[idx('I')];
		cnt[idx('N')]-=cnt[idx('I')];
		cnt[idx('E')]-=cnt[idx('I')];
		ans[9]+=cnt[idx('I')];
		cnt[idx('I')]-=cnt[idx('I')];
		//done
		for(int i=0;i<=9;i++)
			for(int j=0;j<ans[i];j++)
				printf("%d",i);
		puts("");
		SET(ans,0);SET(cnt,0);
	}
	return 0;
}
