#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const char  a[30] = "yhesocvxduiglbkrztnwjpfmaq";
int         n;

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%d", &n);
    while (getchar() != '\n');
    for (int i = 1; i <= n; ++i)
    {
        printf("Case #%d: ", i);
        char ch;
        while (1)
        {
            scanf("%c", &ch);
            if (ch == '\n')
                break;
            printf("%c", ch == ' ' ? ' ' : a[ch - 'a']);
        }
        cout<<endl;
        //printf("\n");
        //printf("\r");
    }
    return 0;
}
