#include<cstdio>
int max(int a,int b) {
	if(a>b) return a;
	return b;
}
int main () {
	int t,T;
	int n,m,i,j,ans;
	int maxrow[101]={0};
	int maxcol[101]={0};
	int num[101][101]={0};
	scanf("%d",&T);
	for(t=0;t<T;t++) {
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++) maxrow[i]=0;
		for(i=0;i<m;i++) maxcol[i]=0;
		ans=1;
		for(i=0;i<n;i++) 
			for(j=0;j<m;j++) {
				scanf("%d",&num[i][j]);
				maxrow[i]=max(maxrow[i],num[i][j]);
				maxcol[j]=max(maxcol[j],num[i][j]);
			}
		for(i=0;i<n;i++) 
			for(j=0;j<m;j++)
				if(maxrow[i]>num[i][j]&&maxcol[j]>num[i][j]) 
					ans=0;
		if(ans==1) printf("Case #%d: YES\n",t+1);
		else printf("Case #%d: NO\n",t+1);
	}
	return 0;
}