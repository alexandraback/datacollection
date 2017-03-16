#include <cstdio>
#include <cstring>

using namespace std;

char a[28]="yhesocvxduiglbkrztnwjpfmaq";


int main()
{
    int cas;
    char s[200];
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%d", &cas);
    gets(s);
    for (int T=1; T<=cas; ++T)
    {
        gets(s);
        printf("Case #%d: ", T);
        for(int i=0; s[i]; ++i)
            printf("%c", (s[i]<='z'&&s[i]>='a')?a[s[i]-'a']:s[i]);
        puts("");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

