#include <cstdio>


using namespace std;

const int maxN=1000;
const int maxM=10;

int g[maxN*maxM+1];
int first[maxN+1];
int nextv[maxN*maxM+1];
int mem;
bool used[maxN+1];
bool used2[maxN+1];
bool find;

void GraphInit()
{
	find=false;
	for (int i=0; i<maxN; i++) { 
		first[i]=-1;
		used[i]=false;
		used2[i]=false;
	}
	mem=0;
}

void AddEdge(int v1, int v2)
{
	g[mem]=v2;
	nextv[mem]=first[v1];
	first[v1]=mem;
	mem++;
}

void DFS(int v) 
{
	used[v]=true;
	int r=first[v];
	while (r!=-1) {
		if (used[g[r]]) find=true;
		else DFS(g[r]);
		r=nextv[r];
	}
}

int main()
{
	freopen("inA.txt","r",stdin);
	freopen("outA.txt","w",stdout);

	int T;
	scanf("%d",&T);
  for (int t=0; t<T; t++) {
	GraphInit();
	int n;
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		int m;
		scanf("%d",&m);
		for (int j=0; j<m; j++) {
			int v;
			scanf("%d",&v);
			v--;
			used2[v]=true;
			AddEdge(i,v);
		}
	}
	for (int i=0; i<n; i++)  
		if (!used2[i]) {
			for (int j=0; j<n; j++)
				used[j]=false;
			DFS(i);
		}

	printf("Case #%d: ",t+1);
	if (find) printf("Yes\n");
	else printf("No\n");
  }

	
	return 0;
}