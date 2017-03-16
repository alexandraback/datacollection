#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int T;
char s[105];

int main() {
    scanf("%d",&T);
    for (int l=1;l<=T;++l) {
        scanf("%s",&s);
        int panjang = strlen(s);
        s[panjang]='+';
        int jawab = 0;
        for (int i=1;i<=panjang;++i) if (s[i]!=s[i-1]) ++jawab;
        printf("Case #%d: %d\n",l,jawab);
    }
    return 0;
}
