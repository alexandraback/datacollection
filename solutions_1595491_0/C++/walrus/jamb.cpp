#include"stdio.h"
int main(){
    int T;
    scanf("%d",&T);
    for(int tt=0;tt<T;tt++)
    {
      int n,s,p;
      scanf("%d%d%d",&n,&s,&p);
      if(p==1)s=0;
      int ans=0;
      for(int i=0;i<n;i++){
	 int x;
	 scanf("%d",&x);
	 if(x>=3*p-2)ans++;
	 else if(x>=3*p-4 && s)ans++,s--;
      }
      if(p==0)ans=n;
      printf("Case #%d: %d\n",tt+1,ans);
    }
}