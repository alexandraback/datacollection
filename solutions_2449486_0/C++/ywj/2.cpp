#include<stdio.h>

int map[110][110],row[110],col[110];

int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int Case=1;Case<=T;Case++){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d",&map[i][j]);
			}
		}
		for(int i=0;i<n;i++){
			row[i]=map[i][0];
			for(int j=1;j<m;j++){
				if(map[i][j]>row[i])row[i]=map[i][j];
			}
		}
		for(int j=0;j<m;j++){
			col[j]=map[0][j];
			for(int i=1;i<n;i++){
				if(map[i][j]>col[j])col[j]=map[i][j];
			}
		}
		bool flag=false;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(map[i][j]<row[i]&&map[i][j]<col[j]){
					flag=true;
					break;
				}
			}
			if(flag)break;
		}
		if(flag)printf("Case #%d: NO\n",Case);
		else printf("Case #%d: YES\n",Case);
	}
	return 0;
}