#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const char cp[27]="yhesocvxduiglbkrztnwjpfmaq";

char s[110];

int main(){
    freopen("A-small-attempt3.in","r",stdin);
    freopen("1.out","w",stdout);
    int t;
    scanf("%d",&t);
    getchar();
    for (int i=0;i<t;i++){
        gets(s);
        printf("Case #%d: ",i+1);
        for (int j=0;j<strlen(s);j++)
            if (s[j]>='a' && s[j]<='z') printf("%c",cp[s[j]-'a']);
            else printf("%c",s[j]);
        printf("\n");
    }
    return 0;
}
/*
3
ejp mysljylc kd kxveddknmc re jsicpdrysi
our language is impossible to understand
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
there are twenty six factorial possibilities
de kr kd eoya kw aej tysr re ujdr lkgc jv
so it is okay if you want to just give up
*/
