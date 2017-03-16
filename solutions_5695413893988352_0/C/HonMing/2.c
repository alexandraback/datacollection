#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int i,j,k;
    int ii,jj,kk;
    int res;
    char cstr[30];
    char jstr[30];
    int p[2000];
    int state;

    scanf("%d", &kk);

    for(ii = 1; ii <= kk; ii++)
    {
        state = 0;
        scanf("%s %s", cstr, jstr);

        for(i = 0; i < strlen(cstr); i++)
        {
            if(cstr[i] != '?' && jstr[i] != '?')
            {
                state = cstr[i] - jstr[i];
                j = i;
                if(state != 0)
                    break;
            }
        }

        if(state == 0)
        {
            for(i = 0; i < strlen(cstr); i++)
            {
                if(jstr[i] == '?' && cstr[i] == '?')
                {
                    jstr[i] = '0';
                    cstr[i] = '0';
                }
                else if(jstr[i] == '?')
                {
                    jstr[i] = cstr[i];
                }
                else if(cstr[i] == '?')
                {
                    cstr[i] = jstr[i];
                }
            }

        }
        else
        {
            for(i = 0; i < strlen(cstr); i++)
            {
                if(i < j)
                {
                    if(jstr[i] == '?' && cstr[i] == '?')
                    {
                        jstr[i] = '0';
                        cstr[i] = '0';
                    }
                    else if(jstr[i] == '?')
                    {
                        jstr[i] = cstr[i];
                    }
                    else if(cstr[i] == '?')
                    {
                        cstr[i] = jstr[i];
                    }
                }
                else if(i > j)
                {
                    if(state > 0)
                    {
                        if(cstr[i] == '?')
                            cstr[i] = '0';
                        if(jstr[i] == '?')
                            jstr[i] = '9';
                    }
                    else
                    {
                        if(cstr[i] == '?')
                            cstr[i] = '9';
                        if(jstr[i] == '?')
                            jstr[i] = '0';
                    }
                }
            }
        }
        
       
        printf("Case #%d: %s %s\n", ii, cstr, jstr);
    }
}
