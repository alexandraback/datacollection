// /\||/\||
//
//
//////////////////////
// Program: 
// Written By Alireza Farhadi (LGM)
//////////////////////
#include <bits/stdc++.h>

using namespace std;

#if ( _WIN32 || __WIN32__ )
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

#define show(x) cerr<<((#x))<<" = "<<((x))<<" "<<endl
#define bit(a,b) (((a)>>(b))&1)
#define FE(i, c) for(auto i = ((c)).begin(); i != ((c)).end(); i++)
#define get(x,i) (get<((i))>(((x))))
#define ALL(x) ((x)).begin(),((x)).end()
#define Mt make_tuple
#define gcd __gcd
#define endl '\n'
#define bcnt(x) ((__builtin_popcount(x)))
#define bcntll(x) ((__builtin_popcountll(x)))
#define sz(x) ((int((x).size())))
#define sqr(x) ((((x))*((x))))
#define fx(x) fixed<<setprecision(x)
#define fl endl<<flush
#define list _list

template<class T> inline void smn(T &a,const T &b){if(b<a) a=b;}
template<class T> inline void smx(T &a,const T &b){if(b>a) a=b;}
template<class T> inline T _rev(const T & a){T _=a; reverse(_.begin(),_.end()); return _;}


/*
	ifstream fin(".in");
	ofstream fout(".out");
#define cin fin
#define cout fout
 */

int Main();
int main()
{
	ios_base::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	return Main();
}

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pie;
typedef pie pii;
typedef tuple<int,int,int> trip;
typedef complex<double> point;

const double eps=1e-8;
const ld leps=1e-14;
const int MN=60;
int n,m;
bool mat[MN][MN];
string code[MN];
bool block[MN];
bool temp[MN];
bool visited[MN];
string bst;
int order[MN];
bool mark[MN];
int t;
bool cmp(const int & a,const int & b)
{
	return code[a]<code[b];
}
void dfs(int a)
{
	mark[a]=1;
	for (int i=0;i<n;i++) if (mat[a][i] && !mark[i] && !temp[i])
		dfs(i);
}
bool av(vector <int> p,int v)
{
	if (p.size()>0)
	{
		bool fnd=false;
		for (int & x:p) if (mat[x][v])
		{
			fnd=true;
			break;
		}
		if (!fnd) return false;
	}
	for (int i=0;i<n;i++) temp[i]=block[i];
	while (p.size()>0 && !mat[p.back()][v])
		temp[p.back()]=true,p.pop_back();
	p.push_back(v);
	memset(mark,0,sizeof(mark));
	for (int & x:p) if (!mark[x])
		dfs(x);
	for (int i=0;i<n;i++) if (visited[i]==0 && mark[i]==0) return false;
	return true;
}
void go(vector <int> p,string c)
{

	int cnt=0;
	for (int i=0;i<n;i++) cnt+=visited[i];
	if (cnt==n)
	{
		bst=c;
		return ;
	}
	for (int i=0;i<n;i++) 
		if (!visited[order[i]] && av(p,order[i]))
		{
			while (p.size()>0 && mat[p.back()][order[i]]==0)
				block[p.back()]=1,p.pop_back();
			p.push_back(order[i]);
			visited[order[i]]=1;
			go(p,c+code[order[i]]);
			return ;
		}
}
int tc;
int Main()
{
	cin>>t;
	while (t-->0)
	{
		bst="";
		memset(mat,0,sizeof(mat));
		memset(block,0,sizeof(block));
		memset(visited,0,sizeof(visited));
		cin>>n>>m;
		show(n);
		for (int i=0;i<n;i++) cin>>code[i];
		for (int i=0;i<m;i++)
		{
			int a,b; cin>>a>>b; a--; b--;
			mat[a][b]=mat[b][a]=1;
		}
		for (int i=0;i<n;i++) order[i]=i;		
		sort(order,order+n,cmp);
		go(vector<int> {},"");		
		cout<<"Case #"<<++tc<<": "<<bst<<endl;
	}
	return 0;
}
