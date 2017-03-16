#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char a[30] = {"yhesocvxduiglbkrztnwjpfmaq"};
char g[110];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, l;
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++){
        fgets(g, 1000, stdin);
        l = strlen(g);
        printf("Case #%d: ", i + 1);
        for(int j = 0; j < l; j++){
            if(g[j] >= 'a' && g[j] <= 'z'){
                printf("%c", a[g[j] - 'a']);
            }else printf("%c", g[j]);
        }
    }
    return 0;
}
