#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char dic[30] = "yhesocvxduiglbkrztnwjpfmaq", ash[5];

int main ()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n; scanf("%d", &n); gets(ash);
    for (int i = 0; i < n; i++)
    {
        char tt[210]; gets(tt);
        printf("Case #%d: ", i + 1);
        for (int j = 0; ; j++)
        {
            if (!tt[j]) break;
            else if (tt[j] < 'a' || tt[j] > 'z') printf("%c", tt[j]);
            else if (dic[tt[j] - 'a'] != '?') printf("%c", dic[tt[j] - 'a']);
            else printf("[%c]", tt[j]);
        } printf("\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
