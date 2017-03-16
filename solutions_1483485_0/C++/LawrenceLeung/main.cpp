#include <cstdlib>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

using namespace std;

int main(int argc, char *argv[])
{
    char* src = "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jvqz";
    char* dst = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give upzq";
    char map[26];
    
    memset(map, -1, sizeof(map));
    for (char* p = src; *p; p++)
    {
        if (islower(*p))
        {
           map[*p-'a'] = dst[p-src];
        }
    }
    
    for (int i = 0; i < sizeof(map); i++)
    {
        if (map[i] == -1)
        {
           printf ("%c is not mapped", i+'a');
        }
    }
    
    int nCase, caseId;
    char line[200];
    scanf("%d", &nCase);
    gets(line);
    for (caseId = 1; caseId <= nCase; caseId++)
    {
        gets(line);
        for (char *p = line; *p; p++)
        {
	        if (islower(*p))
	        {
			   *p = (map[*p-'a']);
	        }
	        else if (isupper(*p))
	        {
			   *p = (map[*p-'A'])+'A';
	        }
		}
        printf ("Case #%d: %s\n", caseId, line);
    }
    
    return EXIT_SUCCESS;
}
