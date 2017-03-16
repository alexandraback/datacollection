#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;
char St[26] = {'y','h','e','s','o',
               'c','v','x','d','u',
               'i','g','l','b','k',
               'r','z','t','n','w',
               'j','p','f','m','a',
               'q'};
int main() {
    freopen("131.in","r",stdin);
    freopen("output.txt","w",stdout);
    char Dat[500];
    int n;
    scanf("%d\n",&n);
    for (int i = 1; i <= n; i++) {
        printf("Case #%d: ",i);
        gets(Dat);
        int m = strlen(Dat);
        for (int i = 0; i < m; i++) if (Dat[i] >= 'a' && Dat[i] <= 'z')
            printf("%c",St[Dat[i]-'a']);
        else printf("%c",Dat[i]);
        printf("\n");
    }
}
