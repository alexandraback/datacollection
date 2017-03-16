#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>

using namespace std;

const char a[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

int main()
{
    //freopen("A-small-attempt0.in","r",stdin);
   // freopen("1.out","w",stdout);
    int te,i,j,k;
    char s[1111];
    scanf("%d\n",&te);
    for(i=1;i<=te;i++){
        
        gets(s);
        printf("Case #%d: ",i);
        k=strlen(s);
        for(j=0;j<k;j++)
        if(s[j]==' ')putchar(' ');else
            putchar(a[s[j]-'a']);
        puts("");
    }
   // system("pause");
}
