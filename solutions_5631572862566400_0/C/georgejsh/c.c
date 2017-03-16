#include<stdio.h>
	int e[1000];
	int f[1000][1000];
	int df[1000];

int k;
int z;
int end;
int curr[1000];
int ci=0;
int n;
int check(){
	int i,j,k=0;
	if(e[curr[0]]!=curr[ci-1] && e[curr[0]]!=curr[1] ){
				k++;
		}
	for(i=1;i<ci-1;i++)
		if(e[curr[i]]!=curr[i-1] && e[curr[i]]!=curr[i+1] ){
				k++;
		}
	if(e[curr[ci-1]]!=curr[0] && e[curr[ci-1]]!=curr[ci-2] ){
				k++;
		}
	if(!k)
	return ci;
	else
	return 0;
}
int bffs(int i,int j,int dis[1000]){
	int l;
	//printf("%d ",i);
	curr[ci++]=i;
	dis[i]=j;
	k++;
	if(check()>z)
		z=check();
	if(dis[e[i]]>=1) {
		
		for(l=0;l<df[i];l++){
			if(dis[f[i][l]]==0){
				int m=k;
		//printf("r%d %d\n",i,f[i][l]);
				bffs(f[i][l],j+1,dis);
				k=m;
			}
		}		
	}
	else if(dis[e[i]]==0)
	bffs(e[i],j+1,dis);
	{
		for(l=0;l<n;l++)
			if(dis[l]==0){
				int m=k;
				bffs(l,j+1,dis);
				k=m;
			}
	}
	ci--;
}
int main(){
	int t;
	int i;
	int max,j,l;
	for(scanf("%d",&t),i=1;i<=t;i++){
		scanf("%d",&n);
		for(j=0;j<1000;j++){
			for(k=0;k<n;k++)
			 f[j][k]=0;
				e[j]=0;
				df[j]=0;
			//dis[j]=0;
		//	}
		}		
		for(j=0;j<n;j++){
			scanf("%d",&k);
			e[j]=k-1;
			f[k-1][df[k-1]++]=j;
		}
		max=-1;
		for(j=0;j<n;j++){
			z=-1;
			k=0;
			int dis[1000];
			for(l=0;l<n;l++)
				dis[l]=0;
			dis[j]=1;
			l=bffs(j,1,dis);
			//printf("a%d\n",z);
			if(z>max)
				max=z;
			for(k=0;k<n;k++)
				dis[k]=0;
		}		
		printf("Case #%d: %d\n",i,max);
	}
}
