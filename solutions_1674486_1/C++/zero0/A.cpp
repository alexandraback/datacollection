#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int t;
int n,m,x,in;
int rep[1007];
int ile[1007],inor[1007];
int color[1007];
vector<int>adj[1007];

int Find(int a) {
 if(rep[a]==a) return a;
 else{
	rep[a]=Find(rep[a]);
	return rep[a];
}
}

bool Union(int a, int b)
{
	int fa = Find(a);
	int fb = Find(b);
 
	if (fa==fb) return false;
	if (ile[fa]<=ile[fb])
	{
		ile[fb]+=ile[fa];
		rep[fa]=fb;
	}
	else
	{
		ile[fa]+=ile[fb];
		rep[fb]=fa;
	}
	return true;
}

inline void init(){
	for(int i=0;i<=n;i++){
		adj[i].clear();
		rep[i]=i;
		ile[i]=1;
		color[i]=0;
	}
}

inline void odkoloruj(){
	for(int i=0;i<=n;i++)
		color[i]=0;
}

bool b;
inline void dfs(int u){
	//printf("jestem w %d\n",u);
	color[u]=1;
	int l,v;
	
	l=adj[u].size();
	for(int i=0;i<l;i++){
		v=adj[u][i];
		if(color[v]==0)
			dfs(v);
		else if(color[v]==2){
		//	printf(" Z %d do %d !!!!!!!!!!!!\n",u,v);
			b=1;
		}
	}
	color[u]=2;
	//printf("wychodze z %d\n",u);
}

int main()
{
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d",&n);
		init();
		b=0;
		for(int j=0;j<n;j++){
			scanf("%d",&m);
			//printf("wczytalem m - %d\n",m);
			for(int k=0;k<m;k++){
				scanf("%d",&x);
				adj[j+1].push_back(x);
			}
		}
		
		for(int j=0;j<n;j++){
				dfs(j+1);
				odkoloruj();
		}
		if(b==0)
				printf("Case #%d: No\n",i+1);
		else
				printf("Case #%d: Yes\n",i+1);
	}
return 0;
}
