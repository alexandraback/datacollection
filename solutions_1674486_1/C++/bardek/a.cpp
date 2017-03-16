#include <cstdio>
#include <algorithm>
#include <vector>

#define fru(j,n) for(int j=0;j<n;++j)
#define tr(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it)
#define x first
#define y second

using namespace std;

typedef pair<int,int> pii;
typedef long long LL;

const int MAXN = 1001;
vector<int> V[MAXN];
bool C[MAXN];
bool dfs(int u)
{
	C[u]=1;
	tr(it,V[u]) if(C[*it]) return 1;
	else if(dfs(*it)) return 1;
	return 0;
}
bool solve()
{
	int n;
	scanf("%d",&n);
	fru(i,n) V[i].clear();
	fru(i,n) 
	{
		int t;
		scanf("%d",&t);
		fru(o,t)
		{
			int a;
			scanf("%d",&a);
			--a;
			V[a].push_back(i);
		}
	}
	fru(i,n) C[i]=0;
	fru(i,n) if(dfs(i)) return 1;
	else
	{
		fru(j,n) C[j]=0;
	}
	return 0;
}

int main()
{
	int o;
	scanf("%d",&o);
	fru(oo,o)
	{
		 printf("Case #%d: ",oo+1);
		 printf("%s\n",solve()?"Yes":"No");
	}
    return 0;
}
