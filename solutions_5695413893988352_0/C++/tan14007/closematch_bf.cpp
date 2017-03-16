#include <bits/stdc++.h>
#define X first
#define Y second
#define PI pair<int,int>
using namespace std;
int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
char sa[1010],sb[1010];
int ma[1010],mb[1010];
stack <int> S;
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf(" %d",&t);
	for(l=1;l<=t;l++){
		printf("Case #%d: ",l);
		scanf(" %s %s",sa,sb);
		w=1;
		a=strlen(sa);
		b=strlen(sb);
		for(i=0;i<a;i++)w*=10;
		p=INT_MAX;
		for(i=0;i<w;i++){
			v=i;
			for(k=a-1;k>=0;k--){
				if(sa[k]!='?'&&(v%10)!=(sa[k]-'0'))break;
				v/=10;
			}
			if(k>=0)continue;
			//printf("-----%d\n",i);
			for(j=0;j<w;j++){
				v=j;
				//printf("%d\n",j);
				for(k=b-1;k>=0;k--){
					if(sb[k]!='?'&&(v%10)!=(sb[k]-'0'))break;
				//	printf("%d %c %d\n",j,sb[k],v%10);
					v/=10;
				}
				if(k>=0)continue;
				//printf("%d\n",j);
				if(abs(i-j)<p){
					p=abs(i-j);
					y=i,z=j;
				}
			}
		}
		while(y){
			S.push(y%10);
			y/=10;
		}
		for(i=0;i<a-S.size();i++)printf("0");
		while(!S.empty()){
			printf("%d",S.top());
			S.pop();
		}printf(" ");
		while(z){
			S.push(z%10);
			z/=10;
		}
		for(i=0;i<b-S.size();i++)printf("0");
		while(!S.empty()){
			printf("%d",S.top());
			S.pop();
		}printf("\n");
		//printf("%d %d\n",y,z);
	}
	return 0;
}