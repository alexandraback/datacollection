#include <cstdio>
const int MAXN=100005;
double s[MAXN],c[MAXN],ans;
int t,a,b;
int main(){
   scanf("%d",&t);
   for(int m=1;m<=t;++m){
      scanf("%d%d",&a,&b);
      for(int i=1;i<=a;++i) scanf("%lf",&s[i]);
      c[1]=s[1];
      for(int i=2;i<=a;++i) c[i]=c[i-1]*s[i];
      ans=2+b;
      for(int k=0;k<=a;++k){
	 float tmp=2*k+b-a+1;
	 tmp+=(b+1)*(1-c[a-k]);
	 if(tmp<ans) ans=tmp;
      }
      printf("Case #%d: %.8f\n",m,ans);
   }
}
