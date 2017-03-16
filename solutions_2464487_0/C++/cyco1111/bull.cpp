#include<cstdio>

using namespace std;

int main()
{
    int t,it=1;
    unsigned long long int r,v;
    unsigned long long int i,ans,x,ctr;
    
    scanf("%d",&t);
    while(t--)
    {
              scanf("%llu%llu",&r,&v);
              x=0;
              i=0;
              ctr=0;
              while(x<=v)
              {
                   x+=((2*r)+(((i+1)*(i+1))-(i*i)));
                   i+=2;
                   ctr++;
              }
              ans=ctr-1;
          printf("Case #%d: %llu\n",it++,ans);
      }
          return 0;
}
                      
              
