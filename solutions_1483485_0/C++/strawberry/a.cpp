#include<iostream>
#include<cstdio>
using namespace std;
char a[30]="yhesocvxduiglbkrztnwjpfmaq",inp[105];
int main(){
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int cas;
    scanf("%d",&cas);
    getchar();
    for(int c=1;c<=cas;c++){
        gets(inp);
        for(int i=0;inp[i];i++)
            if('a'<=inp[i]&&inp[i]<='z')
                inp[i]=a[inp[i]-'a'];
        printf("Case #%d: %s\n",c,inp);
    }
    return 0;
}

