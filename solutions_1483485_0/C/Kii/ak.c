#include<stdio.h>
int main()
{
      freopen("A-small-attempt1.in","r",stdin);
    freopen("output.txt","w",stdout);   
    int n,i,k=0,flag,j;
    char c1;
    char a[52];
    char b[52]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q','Y','H','E','S','O','C','V','X','D','U','I','G','L','B','K','R','Z','T','N','W','J','P','F','M','A','Q'};
    for(i='a';i<='z';i++)
    {
                         a[k]=i;
                         k++;
    } 
    for(i='A';i<='Z';i++)
    {
                         a[k]=i;
                         k++;
    } 
 scanf("%d",&n);
 getchar();
 for(j=1;j<=n;j++)
 {
            printf("Case #%d: ",j);
            c1=getchar();
            if(c1==EOF)
            break;
            while(c1!=10)
            {
                         flag=0;
                         for(i=0;i<52;i++)
                         {
                                          if(c1==a[i])
                                          {
                                          printf("%c",b[i]);
                                          flag=1;
                                          break;
                                          }
                         }
                         if(flag==0)
                         printf("%c",c1);
                         c1=getchar();   
                          if(c1==EOF)
            break;
            }     
            printf("\n");
 }
 return 0;
}
