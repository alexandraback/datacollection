#include<stdio.h>
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("output.txt","w",stdout);   
    int N,sol=0,inde=1,n,s,m,num,temp1,i;
    scanf("%d",&N);
    getchar();
    while(N!=0)
    {
               scanf("%d",&n);
            //   printf("n:%d\n",n);
               getchar();
               scanf("%d",&s);
            //   printf("s:%d\n",s);
               getchar();
               scanf("%d",&m);
            //   printf("m:%d\n",m);
               getchar();
               sol=0;
               for(i=0;i<n;i++)
               {
                               
                               scanf("%d",&num);
                      //         printf("num:%d\n",num);
                               getchar();
                                                if(num==0 && num>=m)
                                                {
                                                          sol++;
                                                }
                                                else if(num==0)
                                                {
                                                     continue;
                                                }
                                                else if(num%3==0)
                                                {
                                                     temp1=num/3;
                                                  //   printf("temp1:%d\n",temp1);
                                                     if(temp1>=m)
                                                     {
                                                                 sol++;
                                                     }
                                                     else if(s>0 && ((temp1+1)>=m))
                                                     {
                                                          s--;
                                                          sol++;
                                                     }
                                                }
                                                else if(num%3==1)
                                                {
                                                     temp1=num/3;
                                                     temp1++;
                                                     if(temp1>=m)
                                                     sol++;
                                                }
                                                else if(num%3==2)
                                                {
                                                     temp1=num/3;
                                                     temp1++;
                                                     if(temp1>=m)
                                                     {
                                                                 sol++;
                                                     }
                                                     else if(s>0 && ((temp1+1)>=m))
                                                     {
                                                          s--;
                                                          sol++;
                                                     }
                                                }
                              // printf("sol:%d\n",sol);
               }
               N--;
               printf("Case #%d: %d\n",inde,sol);
               inde++;
    }
    return 0;
}
