#include<stdio.h>
#include<string.h>

char map[27] = "yhesocvxduiglbkrztnwjpfmaq";

int main()
{
    int n, m;
    char buffer[1000];
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        gets(buffer);
        m = strlen(buffer);
        for (int j = 0; j < m; j++)
        {
            if (buffer[j] != ' ')
            {
                buffer[j] = map[buffer[j] - 'a'];
            }
        }
        printf("Case #%d: %s\n", i + 1, buffer);
    }
    return 0;
}
