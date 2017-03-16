#include<stdio.h>
int tot,T;
int a[64][64];
int calc(int r,int c,int m,int O){
	int i,j;
	if(O==0){
		if(r==1){
			for(i=1;i<=m;i++)a[0][c-i]=2;
			return 1;
		}
		if(c==1){
			for(i=1;i<=m;i++)a[r-i][0]=2;
			return 1;
		}
	}
	if(m==0){
		if(r==1 && c==1)return 1;
		if(r==1 || c==1)return 0;
		return 1;
	}
	if(m==1){
		if(r==2 && c !=1)return 0;
		if(c==2 && r !=1)return 0;
		a[r-1][c-1]=2;
		return 1;
	}
	if(r>c && m >=c){
		for(i=0;i<c;i++)a[r-1][i]=2;
		return calc(r-1,c,m-c,1);
	}
	if(c>=r && m >=r){
		for(i=0;i<r;i++)a[i][c-1]=2;
		return calc(r,c-1,m-r,1);
	}
	if(c > r){
		for(i=1;i<=m;i++)a[r-1][c-i]=2;
		return 1;
	}else
	if(r>c){
		for(i=1;i<=m;i++)a[r-i][c-1]=2;
		return 1;
	}else{
		if(m < r-1){
			for(i=1;i<=m;i++)a[r-i][c-1]=2;
			return 1;
		}
		for(i=1;i<=m-1;i++)a[r-i][c-1]=2;
		a[r-2][c-1]=2;
		if(c>3)return 1;
		return 0;
	}
}
int main(){
	int i,j;
	int R,C,M;
	freopen("sample.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&T);
	for(tot=1;tot<=T;tot++){
		printf("Case #%d:\n",tot);
		scanf("%d%d%d",&R,&C,&M);
		for(i=0;i<R;i++)
			for(j=0;j<C;j++)a[i][j]=0;
		int ans = calc(R,C,M,0);
		a[0][0]=1;
		if(M==0 || ans==1){
			for(i=0;i<R;i++){
				for(j=0;j<C;j++)
					if(a[i][j]==1)printf("c");else
					if(a[i][j]==2)printf("*");else
					printf(".");
				printf("\n");
			}
		}else printf("Impossible\n");
	}
}
