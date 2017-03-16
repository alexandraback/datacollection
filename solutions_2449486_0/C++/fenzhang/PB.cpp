#include<stdio.h>
#include<algorithm>
int n,m;
int l[111][111];
void sol(int uuu){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",l[i]+j);
	int flag=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int flag1=1,flag2=1;
			for(int k=0;k<n;k++)
				if(l[i][j]<l[k][j])
					flag1=0;
			for(int k=0;k<m;k++)
				if(l[i][j]<l[i][k])
					flag2=0;
			if(flag1||flag2)
				continue;
			else
				flag=0;
			}
		}
	printf("Case #%d: %s\n",uuu,flag?"YES":"NO");
	}
int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("PB.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int ti=0;ti<t;ti++)
		sol(ti+1);
	return 0;
	}
