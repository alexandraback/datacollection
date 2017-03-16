#include <stdio.h>
#include <string.h>
int n,m,map[101][101],line[2][101];
bool check(){
	int i,j,k;
	memset(line,0,sizeof(line));
	for(k=1;k<=100;k++){
		for(i=0;i<n;i++){
			if(line[0][i]!=0) continue;
			for(j=0;j<m;j++){
				if(map[i][j]!=k) break;
			}
			if(j==m)
				line[0][i]=k;
		}
		for(j=0;j<m;j++){
			if(line[1][j]!=0) continue;
			for(i=0;i<n;i++){
				if(map[i][j]!=k) break;
			}
			if(i==n)
				line[1][j]=1;
		}
		for(i=0;i<n;i++){
			if(line[0][i]==0) continue;
			for(j=0;j<m;j++){
				if(map[i][j]==k)
					map[i][j]++;
			}
		}
		for(j=0;j<m;j++){
			if(line[1][j]==0) continue;
			for(i=0;i<n;i++){
				if(map[i][j]==k)
					map[i][j]++;
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(map[i][j]==k) return false;
			}
		}
	}
	return true;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int test,testt,i,j;
	scanf("%d",&testt);
	for(test=1;test<=testt;test++){
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++){
			for(j=0;j<m;j++)
				scanf("%d",&map[i][j]);
		}
		if(check())
			printf("Case #%d: YES\n",test);
		else
			printf("Case #%d: NO\n",test);
	}
	return 0;
}
