#include "iostream"
#include "cstring"
#include "cstdio"
#include "vector"
#include "cstdlib"
#define PB push_back
using namespace std;
int a[110];
int r[110][10];
int ans[110];
int vis[1000];
int rn,n,m,k;
vector<string> v;
int check(int now,int x,int y,int z)
{
	memset(vis,0,sizeof(vis));
	vis[1]=1;
	vis[x]=1;vis[y]=1;vis[z]=1;
	vis[x*y]=1;vis[x*z]=1;vis[y*z]=1;
	vis[x*y*z]=1;
	for(int i=1;i<=k;i++){
		if(vis[r[now][i]]==0) return 0;
	}
	return 1;
}
int main(void)
{
	int T;
	freopen("C-small-1-attempt1.in","r",stdin);
	srand(time(0));
	scanf("%d",&T);
	int g=0;
	while(T--){		
		scanf("%d%d%d%d",&rn,&n,&m,&k);
		for(int i=1;i<=rn;i++){
			for(int j=1;j<=k;j++){
				scanf("%d",&r[i][j]);
			}			
		}		
		printf("Case #%d:\n",++g);
		for(int i=1;i<=rn;i++){
			v.clear();
			for(int a1=2;a1<=m;a1++){
				for(int a2=2;a2<=m;a2++){
					for(int a3=2;a3<=m;a3++){
						if(check(i,a1,a2,a3)){
							string s;
							s+=('0'+a1);
							s+=('0'+a2);
							s+=('0'+a3);
							v.PB(s);
						}
					}
				}
			}
			int sz=v.size();
			if(sz==0){
				string s;
				s="222";
				v.PB(s);
				sz=1;
			}
			cout<<v[rand()%sz]<<endl;
		}
	}
	return 0;
}