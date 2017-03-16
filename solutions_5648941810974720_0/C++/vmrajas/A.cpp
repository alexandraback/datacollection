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

int cnt[26];
int ans[10];
int main()
{
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		for(int i=0;i<26;i++)
			cnt[i]=0;
		string s;
		cin>>s;
		for(int i=0;i<SZ(s);i++)
			cnt[s[i]-'A']++;
		ans[0]=cnt['Z'-'A'];cnt['Z'-'A']-=ans[0];cnt['E'-'A']-=ans[0];cnt['R'-'A']-=ans[0];cnt['O'-'A']-=ans[0];
		ans[2]=cnt['W'-'A'];cnt['T'-'A']-=ans[2];cnt['W'-'A']-=ans[2];cnt['O'-'A']-=ans[2];
		ans[8]=cnt['G'-'A'];cnt['E'-'A']-=ans[8];cnt['I'-'A']-=ans[8];cnt['G'-'A']-=ans[8];cnt['H'-'A']-=ans[8];cnt['T'-'A']-=ans[8];
		ans[6]=cnt['X'-'A'];cnt['S'-'A']-=ans[6];cnt['X'-'A']-=ans[6];cnt['I'-'A']-=ans[6];
		ans[7]=cnt['S'-'A'];cnt['S'-'A']-=ans[7];cnt['E'-'A']-=ans[7];cnt['V'-'A']-=ans[7];cnt['E'-'A']-=ans[7];cnt['N'-'A']-=ans[7];
		ans[3]=cnt['H'-'A'];cnt['T'-'A']-=ans[3];cnt['H'-'A']-=ans[3];cnt['R'-'A']-=ans[3];cnt['E'-'A']-=ans[3];cnt['E'-'A']-=ans[3];
		ans[5]=cnt['V'-'A'];cnt['F'-'A']-=ans[5];cnt['I'-'A']-=ans[5];cnt['V'-'A']-=ans[5];cnt['E'-'A']-=ans[5];
		ans[4]=cnt['F'-'A'];cnt['F'-'A']-=ans[4];cnt['O'-'A']-=ans[4];cnt['U'-'A']-=ans[4];cnt['R'-'A']-=ans[4];
		ans[1]=cnt['O'-'A'];cnt['O'-'A']-=ans[1];cnt['N'-'A']-=ans[1];cnt['E'-'A']-=ans[1];
		ans[9]=cnt['I'-'A'];cnt['N'-'A']-=ans[9];cnt['I'-'A']-=ans[9];cnt['N'-'A']-=ans[9];cnt['E'-'A']-=ans[9];
		cout<<"Case #"<<t<<": "; 
		for(int i=0;i<10;i++)
			for(int j=0;j<ans[i];j++)
				cout<<i;
		cout<<"\n";

	}
	return 0;
}
