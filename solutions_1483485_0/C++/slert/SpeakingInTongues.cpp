#include<cstdio>
#include<cstring>
            //abcdefghijklmnopqrstuvwxyz
char map[27]="yhesocvxduiglbkrztnwjpfmaq";
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int tc;
    scanf("%d\n", &tc);
    for(int ti = 1; ti <= tc; ti++)
    {
        char in[200];
        char out[200];
        gets(in);
        int len = strlen(in);
        for(int i = 0; i < len; i++)
        {
            if(in[i] == ' ')out[i] = ' ';
            else out[i] = map[in[i]-'a'];

        }
        out[len] = '\0';
        printf("Case #%d: %s\n", ti, out);
    }
}
