#include <cstdio>
#include <algorithm>

using namespace std;

int nr[105], ile[200], bylo[200], bylsyf[200];
char t[105][105];

int main ()
{
    int z,a,b,c,d,e,f,n,p,k,mono,zbiory;
    long long w;

    scanf ("%d", &z);

    for (a=1; a<=z; a++)
    {
        scanf ("%d", &n);
        getchar();
        zbiory=0;
        w=1;

        for (b=0; b<200; b++)
            bylo[b]=bylsyf[b]=0;

        for (b=0; b<n; b++)
        {
            scanf ("%s", t[b]);
            nr[b]=-1;
        }

        for (b=0; b<n; b++)
        {
            for (c=0; c<200; c++)
                ile[c]=0;

            for (c=0; t[b][c]; c=d)
            {
                ile[t[b][c]]++;

                if (ile[t[b][c]]>1 || bylsyf[t[b][c]])
                    break;

                for (d=c+1; t[b][c]==t[b][d]; d++);

                if (bylo[t[b][c]] && c && t[b][d])
                    break;

                bylo[t[b][c]]++;

                if (c && t[b][d])
                    bylsyf[t[b][c]]++;
            }

            if (t[b][c])
                break;
        }

        if (b<n)
        {
            printf ("Case #%d: 0\n", a);
            continue;
        }

        for (b=0; b<26; b++)
        {
            p=-1;
            k=-1;
            mono=0;

            for (c=0; c<n; c++)
            {
                for (d=0; t[c][d]==b+'a'; d++);

                if (!t[c][d])
                {
                    mono+=1;
                    continue;
                }

                if (t[c][0]==b+'a')
                {
                    if (p!=-1)
                        break;
                    p=c;
                }

                for (d=0; t[c][d]; d++);

                if (t[c][d-1]==b+'a')
                {
                    if (k!=-1)
                        break;
                    k=c;
                }
            }

            if (c<n)
                break;

            if (p!=-1)
            {
                if (k!=-1)
                {
                    if (nr[p]!=-1 && nr[k]!=-1 && nr[p]==nr[k])
                        break;

                    zbiory--;

                    e=nr[p];
                    f=nr[k];

                    if (e<0)
                    {
                        e=-2;
                        zbiory++;
                    }

                    if (f<0)
                    {
                        f=-2;
                        zbiory++;
                    }

                    for (c=0; c<n; c++)
                        if (nr[c]==e || nr[c]==f || c==p || c==k || t[c][0]==b+'a')
                            nr[c]=b;
                }
                else
                {
                    e=nr[p];

                    if (e<0)
                    {
                        zbiory++;
                        e=-2;
                    }

                    for (c=0; c<n; c++)
                        if (nr[c]==e || c==p || t[c][0]==b+'a')
                            nr[c]=b;
                }
            }
            else
            {
                if (k!=-1)
                {
                    f=nr[k];

                    if (f<0)
                    {
                        f=-2;
                        zbiory++;
                    }

                    for (c=0; c<n; c++)
                        if (nr[c]==f || c==k || t[c][0]==b+'a')
                            nr[c]=b;
                }
                else if (mono)
                {
                    zbiory++;

                    for (c=0; c<n; c++)
                        if (t[c][0]==b+'a')
                            nr[c]=b;
                }
            }

            for (e=2; e<=mono; e++)
                w=(w*e)%1000000007;
        }

        if (b<26)
        {
            printf ("Case #%d: 0\n", a);
            continue;
        }

        for (e=2; e<=zbiory; e++)
                w=(w*e)%1000000007;

        printf ("Case #%d: %lld\n", a, w);
    }


    return 0;
}
