#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <stack>
#include <cstring>
#include <iomanip>
#include <ctime>
using namespace std;
#define pb push_back
#define INF 1001001001
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define SZ(x) ((int)((x).size()))
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,SZ(t))s<<t[i]<<" ";return s; }
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

int n,m;
string tab[142];
vector<int> g[142];
vector<int> kol;
bool taken[142], visited[142];
bool mat[100][100], mat2[100][100];

/*void dfs_check(int w)
{
	visited[w]=1;
	for(int i=0;i<g[w].size();i++)
	{
		if(!visited[g[w][i]] && !taken[g[w][i]])
		{
			dfs_check(g[w][i]);
		}
	}
}*/
/*void dfs_check(int w)
{
	visited[w]=1;
	for(int i=0;i<n;i++)
	{
		if(mat2[w][i]
		if(!visited[g[w][i]] && !taken[g[w][i]])
		{
			dfs_check(g[w][i]);
		}
	}
}

void dfs(int w)
{
	//?????
	taken[w]=1;
	string temp="999999";
	//int next;
	vector<pair<string,int> > sprawdz;
	for(int i=0;i<g[w].size();i++)
	{
		if(!taken[g[w][i]])sprawdz.pb(mp(tab[g[w][i]],g[w][i]));
	}
	sort(sprawdz.begin(),sprawdz.end());
	for(int i=0;i<sprawdz.size();i++)
	{
		for(int j=0;j<n;j++)visited[j]=0;
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				mat2[i][j]=mat[i][j];
		mat2[w][sprawdz[i].second]=0;
		dfs_check(sprawdz[i].second);
		bool ok=1;
		for(int j=0;j<n;j++)
		{
			if(!visited[j] && !taken[j])ok=0;
		}
		if(ok)
		{
			kol.pb(sprawdz[i].second);
			dfs(sprawdz[i].second);
			break;
		}
	}	
}*/

bool check(vector<int> perm)
{
	stack<int> s;
	s.push(perm[0]);
	for(int i=1;i<perm.size();i++)
	{
		int temp=s.top();
		bool ok=0;
		while(!ok && !s.empty())
		{	
			for(int j=0;j<g[temp].size();j++)
			{
				if(g[temp][j]==perm[i])
				{
					s.push(perm[i]);
					ok=1;
					break;
				}
			}
			if(!ok)s.pop();
		}
		if(!ok)return 0;
	}
	return 1;
}

int solve(int test)
{
	printf("Case #%d: ",test);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		tab[i]=s;
	}
	for(int i=0;i<n+5;i++)g[i].clear();
	for(int i=0;i<n+5;i++){taken[i]=0; visited[i]=0;}
	//for(int i=0;i<n+5;i++)
	//	for(int j=0;j<n+5;j++)
	//		mat[i][j]=0;
	for(int i=0;i<m;i++)
	{
		wez2(a,b);
		a--;
		b--;
		g[a].pb(b);
		g[b].pb(a);
		//mat[a][b]=1;
		//mat[b][a]=1;
	}
	vector<int> perm;
	string res;
	bool jest=0;
	for(int i=0;i<100000;i++)
	{
		perm.clear();
		for(int j=0;j<n;j++)perm.pb(j);
		for(int j=0;j<n;j++)
		{
			int k=rand()%(n-j);
			int t=perm[j+k];
			perm[j+k]=perm[j];
			perm[j]=t;
		}
		if(check(perm))
		{
			string tym;
			for(int i=0;i<perm.size();i++)tym=tym+tab[perm[i]];
			if(jest==0 || tym<res)
			{
				jest=1;
				res=tym;
			}
		}
	}
	
	/*kol.clear();
	string temp=tab[0];
	int start=0;
	for(int i=0;i<n;i++)
	{
		if(tab[i]<temp)
		{
			temp=tab[i];
			start=i;
		}
	}
	kol.pb(start);
	taken[start]=1;
	dfs(start);
	*/
	/*string res;
	for(int i=0;i<kol.size();i++)
	{
		res=res+tab[kol[i]];
	}*/
	cout<<res<<endl;
	return 0;
}

int main()
{
    wez(t);
    for(int i=1;i<=t;i++)solve(i);
    return 0;   
}
