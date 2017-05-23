#include <bits/stdc++.h>
using namespace std;
#define SD(a) scanf("%d", &a)
char str1[5];
char str2[5];
int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("outputki.txt", "w", stdout);
    int tcase, t;
    SD(tcase);
    int a, b, len1, len2, i1, i2, i3, j1, j2, j3, a1, a2, a3, b1, b2, b3, mina, minb, _min;
    for(t = 1; t <= tcase; t++)
    {
        scanf("%s %s", str1, str2);
        len1 = strlen(str1);
        len2 = strlen(str2);
        mina = minb = _min = 1000;
        for(i1 = 0; i1 < 10; i1++)
        {
            if(str1[0] == '?') a1 = i1;
            else a1 = str1[0] - '0';

            for(i2 = 0; i2 < 10; i2++)
            {
                if(len1 < 2) a2 = 0;
                else
                {
                    if(str1[1] == '?') a2 = i2;
                    else a2 = str1[1] - '0';
                }

                for(i3 = 0; i3 < 10; i3++)
                {
                    if(len1 < 3) a3 = 0;
                    else
                    {
                        if(str1[2] == '?') a3 = i3;
                        else a3 = str1[2] - '0';
                    }
                    if(len1 == 3) a = a1*100 + a2 * 10 + a3;
                    else if (len1 == 2)  a = a1*10 + a2;
                    else a = a1;

                    for(j1 = 0; j1 < 10; j1++)
                    {
                        if(str2[0] == '?') b1 = j1;
                        else b1 = str2[0] - '0';

                        for(j2 = 0; j2 < 10; j2++)
                        {
                            if(len2 < 2) b2 = 0;
                            else
                            {
                                if(str2[1] == '?') b2 = j2;
                                else b2 = str2[1] - '0';
                            }

                            for(j3 = 0; j3 < 10; j3++)
                            {
                                if(len2 < 3) b3 = 0;
                                else
                                {
                                    if(str2[2] == '?') b3 = j3;
                                    else b3 = str2[2] - '0';
                                }
                                if(len2 == 3) b = b1*100 + b2 * 10 + b3;
                                else if (len2 == 2)  b = b1*10 + b2;
                                else b = b1;

                                if(abs(a - b) < _min)
                                {
                                    //printf("de %d %d\n", a, b);
                                    mina = a;
                                    minb = b;
                                    _min = abs(a - b);
                                }
                                else if(abs(a - b) == _min)
                                {
                                    if(mina > a)
                                    {
                                        mina = a;
                                        minb = b;
                                    }
                                    else if(mina == a)
                                    {
                                        minb = min(minb, b);
                                    }
                                }
                            }
                        }
                    }

                }
            }
        }
        if(len1 == 3)printf("Case #%d: %03d %03d\n", t, mina, minb);
        else if(len1 == 2)printf("Case #%d: %02d %02d\n", t, mina, minb);
        else printf("Case #%d: %d %d\n", t, mina, minb );
    }

    return 0;
}
