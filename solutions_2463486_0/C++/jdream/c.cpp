#include<cstdio>
#include<cstring>
#include<cmath>
#define LL long long
using namespace std;
int c[20],p[20],ans,x,y,s[110],xx,yy;
int TT,T,i;
int sqr(int x){return x*x;}
bool check(int x){
	int i,len;
	for(i=1;i<=5;i++){
		c[i]=x%p[i]/p[i-1];
	}
	for(i=5;i;i--)if(c[i])break;
	len=i;
	for(i=1;i<=len/2;i++)if(c[i]!=c[len-i+1])return 0;
	return 1;
}
int main(){
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	scanf("%d",&TT);
	
	p[0]=1;
	for(i=1;i<=5;i++)p[i]=p[i-1]*10;
	memset(s,0,sizeof(s));
	for(i=1;i<=100;i++)if(check(i)&&check(i*i))
		s[i]=1;
	for(i=1;i<=100;i++)s[i]+=s[i-1];
	for(T=1;T<=TT;T++){
		printf("Case #%d: ",T);
		scanf("%d%d",&x,&y);
		xx=sqrt(x-1);yy=sqrt(y);
		printf("%d\n",s[yy]-s[xx]);
	}
	
}