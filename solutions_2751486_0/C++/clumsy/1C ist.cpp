#include<stdio.h>
#include<string.h>


char a[1200000];
int  b[1200000];


long long givee(int x)
{
     return (long long )(x*(x+1) / 2) ;
}



int check( char x)
{
    return !( x=='a' || x== 'e' || x=='i' || x== 'o' || x== 'u' );
 }
 
 
int main()
{
    int t,l,i,ctr,j,cntr = 1;
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    long long ans = 0;
    int n;
    scanf("%d",&t);
    while(t--)
    {
              scanf("%s",a);
              scanf("%d",&n);
              
              ans = 0;  
              ctr = 0;  
              
              l = strlen(a);
              for(i=0;i<=l;i++)
              b[i] = 0;
              
              for(i=0;i<l;i++)
              {
                              
                              if(check(a[i]))
                              {
                                            ctr = 0;
                                            while(i<l && check(a[i]) )
                                            ctr++,i++;
                                            if(ctr>=n)
                                            {
                                            for(j=i-1;j>=i-ctr;j--)
                                            b[j] = ctr;
                                            
                                            }
                              }
                              
              }
              
              
           //   for(i=0;i<l;i++)
             // printf("%d ",b[i]);
              
              ans = 0;
              
              
              ctr = 0;          
              for(i=0;i<l;)
              {
                              if(b[i])
                              {
                                      ans += givee(ctr+n-1);
                                      ans-=2*givee(n-1);
                                      ans+=givee(b[i]);
                                      ans-=givee(b[i]-n+1);
                                      while(i<l && b[i])
                                      i++;
                                      
                                      ctr = n-1;
                              }
                              else
                              ctr++,i++;
              }
              
              ans+=givee(ctr);
              ans = givee(l) - ans;
              printf("Case #%d: %lld\n",cntr++,ans);
              
              
    }
    return 0;
}
