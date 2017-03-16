#include <bits/stdc++.h>
int a,x,y,t;
char *f[2] = {"RICHARD","GABRIEL"};
int main(){
	int t;scanf("%d",&t);
	for(int i=1;i<=t;i++){
		printf("Case #%d: ",i);
		scanf("%d%d%d",&a,&x,&y);
		if(x>y) std::swap(x,y);
		if(a==1 && x*y>=1) printf("%s\n",f[1]);
		else if(a==2 && x*y>=2 && (x*y)%2 == 0) printf("%s\n",f[1]);
		else if(a==3 && x*y>=6 && (x*y)%3 == 0) printf("%s\n",f[1]);
		else if(a==4 && x>=3 && y==4) printf("%s\n",f[1]);
		else printf("%s\n",f[0]);
	}
}