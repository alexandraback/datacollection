#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	freopen("C-large.in","r",stdin);
	freopen("C2.out","w",stdout);
	int T,Ti,r,c,x,s[55];
	scanf("%d",&T);
	for(int Ti=1;Ti<=T;Ti++){
		scanf("%d %d %d",&r,&c,&x);
		memset(s,0,sizeof(s));
		printf("Case #%d:\n",Ti);
		x=r*c-x;
		if(x==1 || r==1 || c==1){
			x--;
			for(int i=1;i<=r;i++){
				for(int j=1;j<=c;j++){
					if(i==1 && j==1) printf("c");
					else if(x>0){
						x--;
						printf(".");
					}else printf("*");
				}
				printf("\n");
			}
			continue;
		}
		for(int k=2;k<=r;k++){
			if((x%k==1 && (x/k<=2 || k==2)) || x/k<=1 || (x-1)/k+1>c) continue;
			for(int i=1;i<=k;i++) s[i]=x/k;
			x=x%k;
			if(x==1){s[1]++;s[2]++;s[k]--;}
			else for(int i=1;i<=k;i++) if(x>0){s[i]++;x--;}
				
			for(int i=1;i<=r;i++){
				for(int j=1;j<=c;j++){
					if(i==1 && j==1) printf("c");
					else if(i<=k && j<=s[i]) printf(".");
					else printf("*");
				}
				printf("\n");
			}
			goto gg;
		}
		printf("Impossible\n");
		gg:;
	}
	return 0;
}
		
