#include<stdio.h>
#include<string.h>

int m(int i,int j){
	int f=1;
	if(i<0){
		i=-i;
		f*=-1;
	}
	if(j<0){
		j=-j;
		f*=-1;
	}
	if(i==1)return j*f;
	if(i==2){
		if(j==1)return 2*f;
		if(j==2)return -1*f;
		if(j==3)return 4*f;
		if(j==4)return -3*f;
	}
	if(i==3){
		if(j==1)return 3*f;
		if(j==2)return -4*f;
		if(j==3)return -1*f;
		if(j==4)return 2*f;
	}
	if(i==4){
		if(j==1)return 4*f;
		if(j==2)return 3*f;
		if(j==3)return -2*f;
		if(j==4)return -1*f;
	}
}

int a[10005],mul[10005*24];
char s[10005];

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int q=1;q<=t;q++){
		int i,j,k=0;
		int l,x;
		scanf("%d%d",&l,&x);
		if(x>=12)x=(x%4)+12;
		scanf("%s",s+1);
		for(i=1;i<=l;i++){
			if(s[i]=='i')a[i]=2;
			else if(s[i]=='j')a[i]=3;
			else a[i]=4;
		}
		bool f1=0,f2=0;
		mul[0]=1;
		for(i=0;i<x;i++){
			for(j=1;j<=l;j++){
				k++;
				mul[k]=m(mul[k-1],a[j]);
				if(!f1&&mul[k]==2)f1=1;
				if(f1&&!f2&&mul[k]==4)f2=1;
			}
		}
		if(f2&&mul[x*l]==-1)printf("Case #%d: YES\n",q);
		else printf("Case #%d: NO\n",q);
	}
	return 0;
}
