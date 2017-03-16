#include<cstdio>
#include<cassert>
#include<vector>
using namespace std;
struct DisjointSets
{
	int S[1000];
	void Clear(const int n){for(int i=0;i<n;i++)S[i]=i;}
	int Find(const int a){return S[a]==a?a:(S[a]=Find(S[a]));}
	void Merge(const int a,const int b){S[Find(a)]=Find(b);}
}DJ;
void getmax(int &a,const int b){if(b>a)a=b;}
int N,F[1000];
vector<int>CYC;
void BuildCYC(const vector<int>&s)
{
	static bool vis[1000];
	for(const int i:s)vis[i]=false;
	int cur=s[0];
	for(;!vis[cur];cur=F[cur])vis[cur]=true;
	CYC.clear();
	for(;vis[cur];cur=F[cur])vis[cur]=false,CYC.push_back(cur);
	for(const int u:CYC)F[u]=-1;
}
vector<int>ET[1000];
void BuildGraph(const vector<int>&s)
{
	for(const int i:s)ET[i].clear();
	for(const int i:s)if(F[i]!=-1)ET[F[i]].push_back(i);
}
int Height(const int u)
{
	int ans=1;
	for(const int nxt:ET[u])getmax(ans,Height(nxt)+1);
	return ans;
}
int Solve()
{
	vector<int>hs;
	for(const int u:CYC)hs.push_back(Height(u));
	const int n=hs.size();
	if(n>2)return n;
	assert(n==2);
	return max(2,hs[0]+hs[1]);
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int testcount;scanf("%d",&testcount);
	while(testcount--)
	{
		scanf("%d",&N);
		DJ.Clear(N);
		for(int i=0;i<N;i++)scanf("%d",&F[i]),--F[i],DJ.Merge(F[i],i);
		static int vis[1000];
		for(int i=0;i<N;i++)vis[i]=false;
		int ans1=0,ans2=0;
		for(int i=0;i<N;i++)if(!vis[i])
		{
			vector<int>s;
			for(int j=i;j<N;j++)if(DJ.Find(j)==DJ.Find(i))s.push_back(j),vis[j]=true;
//			printf("sz=%d\n",(int)s.size());
			BuildCYC(s);
			BuildGraph(s);
			if((int)CYC.size()==2)ans2+=Solve();
			else getmax(ans1,Solve());
		}
		static int kase=0;
		printf("Case #%d: %d\n",++kase,max(ans1,ans2));
	}
	return 0;
}
