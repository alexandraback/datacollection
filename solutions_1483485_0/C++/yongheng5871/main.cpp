#include<cstdio>
#include<iostream>
#include <cstring>
using namespace std;
const int Maxn=110;
char map[26]={'y','h','e','s','o','c','v','x','d','u','i',
                'g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

         int n;
         char x[2];
         scanf("%d",&n);
         gets(x);
         for(int cas=1;cas<=n;++cas)
         {
             char str[Maxn];
             gets(str);
             int i,len=strlen(str);
             char ans[Maxn];
             for(i=0;i<len;++i)
             {
                 if(str[i]>='a'&&str[i]<='z')
                 ans[i]=map[str[i]-'a'];
                 else ans[i]=' ';
             }
             ans[i]='\0';
             printf("Case #%d: ",cas);
             puts(ans);
         }
}
