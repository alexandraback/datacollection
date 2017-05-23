#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    map < char, char > mymap;
    int case_all, case_count = 1;
    char *a = "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
    char *b = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";
    for (int i = 0; a[i] != '\0'; ++i)
    {
        if (a[i] >= 'a' && a[i] <= 'z')
        {
            mymap[a[i]] = b[i];
        }
    }
    mymap['q'] = 'z'; mymap['z'] = 'q';
    scanf("%d\n", &case_all);
    for (case_count = 1; case_count <= case_all; case_count += 1)
    {
        char s[111];
        gets(s);
        for (int i = 0; s[i] != '\0'; ++i)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                s[i] = mymap[s[i]];
            }
        }
        printf("Case #%d: %s\n", case_count, s);
    }
    return 0;
}
