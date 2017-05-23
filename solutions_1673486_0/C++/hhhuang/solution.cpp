#include <stdio.h>
#include <string.h>

char map[26];

char s1[200] = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
char s2[200] = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";



int main()
{
    int n = 0;
    char st[200];
    char mask[26];
    scanf("%d\n", &n);

    int i, j;
    memset(mask, 0, sizeof(mask));
    for(i = 0 ; i < strlen(s1) ; i++)
    {
        map[s1[i] - 'a'] = s2[i];
        mask[s2[i] - 'a'] = 1;
    }
    map['q' - 'a'] = 'z';
    map['z' - 'a'] = 'q';
    //for(i = 0 ; i < 26 ; i++)
    //    printf("(%c %c %d)  ", i + 'a', map[i], mask[i]);
    for(int i = 0 ; i < n ; i++)
    {   
        gets(st);
        for(j = 0 ; j < strlen(st) ; j++)
            if(st[j] != ' ') st[j] = map[st[j] - 'a'];
        printf("Case #%d: %s\n", i+1, st);
    }
    return 0;
}
