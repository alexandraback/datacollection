#include <stdio.h>
#include <algorithm>
int n,m,su[101],print,tbl[105][1000010];
void pro(int start){
	int i,j;
	for(i=0;i<=n;i++){
		for(j=0;j<=m+1;j++)
			tbl[i][j]=0x7fffffff;
	}
	for(j=0;j<=start;j++){
		tbl[0][j]=0;
	}
	for(i=0;i<n;i++){
		for(j=m;j>=0;j--){
			if(tbl[i][j+1]<tbl[i][j])
				tbl[i][j]=tbl[i][j+1];
		}
		for(j=3;j<=m+1;j++){
			if(tbl[i][(j>>1)+1]==0x7fffffff) continue;
			if(tbl[i][(j>>1)+1]+1<tbl[i][j])
				tbl[i][j]=tbl[i][(j>>1)+1]+1;
		}
		for(j=m+1;j>=0;j--){
			if(tbl[i][j]==0x7fffffff) continue;
			if(su[i]<j){//eat
				if(j+su[i]>m){
					if(tbl[i+1][m+1]>tbl[i][j])
						tbl[i+1][m+1]=tbl[i][j];
				}
				else{
					if(tbl[i+1][j+su[i]]>tbl[i][j])
						tbl[i+1][j+su[i]]=tbl[i][j];
				}
			}
			else{//can't eat
				if(tbl[i+1][j]>tbl[i][j]+1)
					tbl[i+1][j]=tbl[i][j]+1;
			}
		}
	}
	print=0x7fffffff;
	for(i=0;i<=m+1;i++){
		if(print>tbl[n][i])
			print=tbl[n][i];
	}
}
int main(){
	int testt,test,i,s;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&testt);
	for(test=1;test<=testt;test++){
		scanf("%d %d",&s,&n);
		m=s;
		for(i=0;i<n;i++){
			scanf("%d",&su[i]);
			if(m<su[i])
				m=su[i];
		}
		std::sort(su,su+n);
		pro(s);
		printf("Case #%d: %d\n",test,print);
	}
	return 0;
}
