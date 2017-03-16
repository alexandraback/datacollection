#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;

int E[55][55];
int A[55];
int vis[55];
int ord[55];
int die[55];
int die2[55];
int cchk[55];
int n, m;

struct unf{
	int p[55], w[55];
	void init(){for(int i=1;i<55;i++)p[i] = i, w[i] = 1;}
	int Find(int x){
		if(x == p[x])return x;
		return p[x] = Find(p[x]);
	}
	bool Union(int x,int y){
		x = Find(x), y = Find(y);
		if(x==y)return false;
		if(w[x] < w[y])p[x] = y, w[y] += w[x];
		else p[y] = x, w[x] += w[y];
		return true;
	}
};

bool comp(const int &a, const int &b){return A[a] < A[b];}

bool chk()
{
	unf u;
	u.init();
	int i, sz = 0;
	for(i=1;i<=n;i++)if(!die[i] && !die2[i])sz++;
	for(i=1;i<=n;i++){
		if(die[i] || die2[i])continue;
		for(int j=1;j<=n;j++){
			if(die[j] || die2[j])continue;
			if(E[i][j])if(u.Union(i, j))sz--;
		}
	}
	return sz == 1;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int Tc;
	scanf("%d",&Tc);
	for(int tt=1;tt<=Tc;tt++){
		scanf("%d%d",&n,&m);
		int i;
		for(i=1;i<=n;i++){
			scanf("%d",A+i);
		}
		for(i=1;i<=m;i++){
			int x, y;
			scanf("%d%d",&x,&y);
			E[x][y] = 1;
			E[y][x] = 1;
		}
		for(i=1;i<=n;i++)ord[i] = i;
		sort(ord+1,ord+1+n,comp);
		int ans[110], top = 0;
		ans[top++] = ord[1];
		vis[ord[1]] = 1;
		vector <int> v;
		v.push_back(ord[1]);
		memset(die, 0, sizeof die);
		while(top != n){
			vector <int> cango;
			memset(cchk, 0, sizeof cchk);
			memset(die2, 0, sizeof die2);
			for(i=(int)v.size()-1;i>=0;i--){
				if(i!=(int)v.size()-1)die2[v[i+1]] = 1;
				if(!chk())break;
				for(int j=1;j<=n;j++){
					if(!vis[j] && E[v[i]][j] && !cchk[j])cchk[j] = 1, cango.push_back(j);
				}
			}
			sort(cango.begin(), cango.end(), comp);
			int nxt = cango[0];
			ans[top++] = nxt;
			for(i=(int)v.size()-1;i>=0;i--){
				if(E[v[i]][nxt])break;
				v.pop_back();
				die[v[i]] = 1;
			}
			v.push_back(nxt);
			vis[nxt] = 1;
		}
		printf("Case #%d: ", tt);
		for(i=0;i<top;i++)printf("%d",A[ans[i]]);
		puts("");
		for(i=1;i<=n;i++)for(int j=1;j<=n;j++)E[i][j] = 0;
		for(i=1;i<=n;i++)vis[i] = 0;
	}
	return 0;
}
