#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long LL;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
inline void OPEN(string s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(), "w", stdout);
}
inline void CLOSE()
{
	fclose(stdin);
	fclose(stdout);
}
string ar[55];
char br[7];
vector<int> ve[55];
int urutan[55];
bool visit[55];
int main()
{
	int t;
	scanf("%d", &t);
	for(int i=1;i<=t;i++)
	{
		int n,m;
		scanf("%d%d", &n,&m);
		for(int j=1;j<=n;j++) 
		{
			scanf("%s", br);
			ar[j]=br;
		}
		for(int j=0;j<m;j++)
		{
			int a,b;
			scanf("%d%d", &a, &b);
			ve[a].pb(b);
			ve[b].pb(a);
		}
		//puts("BISA");
		string hasil = "";
		for(int j=1;j<=n;j++) urutan[j] = j;
		int cou = 0 ;
		do
		{
		//	printf("%d\n", cou++);
			fill(visit+1, visit+1+n, 0);
			bool valid = 1;
			visit[urutan[1]] = 1;
			for(int j=1;j<=n;j++)
			{
				if(!visit[urutan[j]]) 
				{
					valid = 0;
					break;
				}
				for(int k=0;k<(int) ve[urutan[j]].size();k++) visit[ve[urutan[j]][k]] = 1;
			}
			if(valid)
			{
				string s = "";
				for(int j=1;j<=n;j++) s+=ar[urutan[j]];
				if(!hasil.size()) hasil = s;
				else hasil = min(hasil,s);
				//puts(s.c_str());
			}
		}
		while(next_permutation(urutan+1, urutan+1+n));
		
		printf("Case #%d: %s\n", i,hasil.c_str());
		for(int j=1;j<=n;j++) ve[j].clear();
	}
	return 0;
}
