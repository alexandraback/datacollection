#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char a[]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
int main()
{
    //freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
   int t;
   scanf("%d",&t);
   getchar();
   for(int i=1;i<=t;i++)
   {
       char b[500];
       gets(b);
       printf("Case #%d: ",i);
       for(int i=0;i<strlen(b);i++)
       {
           if(b[i]>='a'&&b[i]<='z')
       printf("%c",a[b[i]-'a']);
       else
       printf("%c",b[i]);
       }
       printf("\n");
   }
   return 0;
}
