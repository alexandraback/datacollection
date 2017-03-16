#include<cstdio>
#include<cstring>
#include<cmath>
#define LL long long
using namespace std;
LL c[20],p[20],ans,x,y,xx,yy;
int TT,T,i,s[10000100];
LL sqr(LL x){return x*x;}
bool check(LL x){
	int i,len;
	for(i=1;i<=15;i++){
		c[i]=x%p[i]/p[i-1];
	}
	for(i=15;i;i--)if(c[i])break;
	len=i;
	for(i=1;i<=len/2;i++)if(c[i]!=c[len-i+1])return 0;
	return 1;
}
int main(){
//	freopen("C-large-1.in","r",stdin);
//	freopen("C-large-1.out","w",stdout);
	scanf("%d",&TT);
	p[0]=1;
	for(i=1;i<=15;i++)p[i]=p[i-1]*10;
	memset(s,0,sizeof(s));
	for(x=1;x<=10000000;x++)if(check(x)&&check(x*x))
		s[x]=1;
	for(i=1;i<=10000000;i++)s[i]+=s[i-1];
	for(T=1;T<=TT;T++){
		printf("Case #%d: ",T);
		scanf("%I64d%I64d",&x,&y);
		xx=(int)sqrt(x-1);yy=(int)sqrt(y);
		printf("%d\n",s[yy]-s[xx]);
	}
	
}