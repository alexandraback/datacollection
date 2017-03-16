#include<cstdio>
using namespace std;
int main()
{
    int  t, it =1,g,i,e,r,n;
    scanf("%d",&t);
    while(t--)
    {
              scanf("%d%d%d",&e,&r,&n);
              int a[n];
              for(i=0;i<n;i++)
              {
              scanf("%d",&a[i]);
              }
              
              g=0;
              
              for(i=0;i<n;i++)
              {
                              if(a[i]==1){
                              if( e < r) g = g + e;
                              else g = g+r;
                              }
                              else
                              g= g+(a[i]*e);
              }
              
              printf("Case #%d: %d\n",it++,g);
    }
    return 0;
}
                       
