#include<stdio.h>
#include<string.h>

int gcd(int a, int b) {
  return b == 0 ? a : a > b ? gcd(b, a%b) : gcd(a, b%a); 
}
int main()
{
    
    
    
    freopen("A.in","r",stdin);
    freopen("out1.txt","w",stdout);
    int t,test = 1,p,q,flag,ans,i,l,num;
    char str[50];
    scanf("%d",&t);
    while(t--)
    {
              ans = 0,p=0,q=0;
              flag = 0;
              scanf("%s",str);
              i = 0;
              l = strlen(str);
              while(str[i]!='/')
              {
                                p = p*10 + str[i] - '0' ;
                                i++;
              }
              i++;
              while(i<l)
              {
                        q = q*10 + str[i] - '0';
                        i++;
              }
              
                            num = gcd(p,q);
                            p = p/num;
                            q =q/num;
              while(flag==0)
              {
                            
                            if(!(q&(q-1)))
                            {
                                          if(p>=q)
                                          {flag=1;
                                          break;}
                                          else 
                                          {
                                               ans++;
                                           }
                            }
                            else 
                            flag=2;
                            if(ans>40)
                            flag=2;
                            
                            p = p*2;
                            num = gcd(p,q);
                            p = p/num;
                            q =q/num;
              }
              if(flag==2)
              {
                         printf("Case #%d: impossible\n",test++);
              }
              else if (flag==1)
              printf("Case #%d: %d\n",test++,ans);
    }
    return 0;
}
