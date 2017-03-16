#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char s[200]={"yhesocvxduiglbkrztnwjpfmaq"};
char ip[200];
int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int n;
    scanf("%d",&n);
    gets(ip);
    for(int i=0;i<n;i++){
        gets(ip);
        printf("Case #%d: ",i+1);
        int len=strlen(ip);
        for(int j=0;j<len;j++){
            if(ip[j]==' ') putchar(' ');
            else printf("%c",s[ip[j]-'a']);
        }
        puts("");
    }

}
