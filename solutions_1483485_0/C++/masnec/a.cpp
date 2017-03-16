#include<stdio.h>
#include<string.h>

int main()
{

    int cas;
    char input[105];
    int map[26]={int('y'-'a'),int('h'-'a'),int('e'-'a'),int('s'-'a'),int('o'-'a'),
                int('c'-'a'),int('v'-'a'),int('x'-'a'),int('d'-'a'),int('u'-'a'),
                int('i'-'a'),int('g'-'a'),int('l'-'a'),int('b'-'a'),int('k'-'a'),
                int('r'-'a'),int('z'-'a'),int('t'-'a'),int('n'-'a'),int('w'-'a'),
                int('j'-'a'),int('p'-'a'),int('f'-'a'),int('m'-'a'),int('a'-'a'),
                int('q'-'a')};

    scanf("%d",&cas);
    getchar();
    for(int i=1;i<=cas;++i)
    {
        gets(input);
        printf("Case #%d: ",i);
        for(int j=0;j<strlen(input);++j)
        {
            if('a'<=input[j] && input[j]<='z')
                printf("%c", char(map[int(input[j]-'a')]+'a'));
            else
                printf("%c",input[j]);

        }
        printf("\n");

    }
    return 0;
}
