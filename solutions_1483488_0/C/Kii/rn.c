#include<stdio.h>
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);   
    int n,sol,arin,temp,x,num,i,j,a,b,count,karin,r,k,ch;
    int arr[1500];
 //   int arr2[1500000];
    scanf("%d",&n);
    getchar();
    for(j=1;j<=n;j++)
    {
    scanf("%d",&a);
    getchar();
  //  printf("a:%d\n",a);
    scanf("%d",&b);
    getchar();
 //   printf("b:%d\n",b);
    karin=0;
     sol=0;
    for(i=a;i<=b;i++)
    {
                    
                     arin=1;
                     arr[0]=i;
                     temp=i;
                     x=10;
                     while((i/x)!=0)
                     {
                                    ch=1;
                                    while(temp!=0)
                                    {
                                    temp=temp/10;
                                    ch=ch*10;
                                    }
                                    temp=i;
                           r=temp%x;
                           temp=temp/x;  
                           num=(r*(ch/x))+temp;
                        //   printf("num:%d\n",num);
                        //   printf("i:%d\n",i);
                           if(num!=i && num>=a && num<=b)
                           {
                           if(arin==1)
                           {
                            arr[arin]=num;          
                            arin++;
                            sol++;
                           }
                           else
                           {
                               count=0;
                               for(k=0;k<arin;k++)
                               {
                                                  if(num==arr[k])
                                                  {
                                                                 count=1;
                                                                 break;
                                                  }
                               }
                               if(count==0)
                               {
                                           arr[arin]=num;
                               sol++;
                               arin++;
                               }
                           }
                           }
                           x=x*10;
                           temp=i;
                     }
    }
    printf("Case #%d: %d\n",j,sol/2);
    }
    return 0;
}
