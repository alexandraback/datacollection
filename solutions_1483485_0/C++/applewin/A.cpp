#include<stdio.h>
#include<string.h>

using namespace std;

char mapping[27] = {'y','h','e','s','o','c','v','x','d','u',
'i','g','l','b','k','r','z','t','n','w',
'j','p','f','m','a','q'};
char str[120];
int main(){
    int T;
    gets(str);
    sscanf(str,"%d", &T);
    for(int i=1;i<=T;++i){
        printf("Case #%d: ", i);
        gets(str);
        for(int j=0, l=strlen(str);j<l;++j)
            if('a' <= str[j] && str[j] <= 'z')
                printf("%c", mapping[str[j]-'a']);
            else
                printf("%c", str[j]);
        puts("");
    }
    return 0;
}
