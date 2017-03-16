#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

char map[] = "yhesocvxduiglbkrztnwjpfmaq";

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, k = 0;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        char s[200];
        gets(s);
        int len = strlen(s);
        printf("Case #%d: ",++k);
        for(int i = 0; i < len; ++i)
        {
            if(s[i] == ' ') putchar(' ');
            else
            {
                putchar(map[s[i] - 'a']);
            }
        }
        putchar('\n');
    }
    return 0;
}
