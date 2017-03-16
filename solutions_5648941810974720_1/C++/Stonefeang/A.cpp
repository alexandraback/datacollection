#include <bits/stdc++.h>
using namespace std;

int t;

int n;
char wcz[2007];

int wyn[30];
int ile[30];

int zab[30];

vector <int> kto[30];

vector <int> letsy[30];

int kon()
{
    for (int i=0; i<26; i++)
    {
        if (ile[i])
        {
            return 0;
        }
    }
    return 1;
}

int czymoz(int v)
{
    for (int i=0; i<letsy[v].size(); i++)
    {
        if (!ile[letsy[v][i]])
        {
            return 0;
        }
    }
    return 1;
}

int mus(int v)
{
    int licz;
    for (int i=0; i<letsy[v].size(); i++)
    {
        licz=0;
        int pom=letsy[v][i];
        for (int j=0; j<kto[pom].size(); j++)
        {
            if (!zab[kto[pom][j]])
            {
                licz++;
            }
        }
        if (licz==1)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    letsy[0].push_back('Z'-'A');
    letsy[0].push_back('E'-'A');
    letsy[0].push_back('R'-'A');
    letsy[0].push_back('O'-'A');

    letsy[1].push_back('O'-'A');
    letsy[1].push_back('N'-'A');
    letsy[1].push_back('E'-'A');

    letsy[2].push_back('T'-'A');
    letsy[2].push_back('W'-'A');
    letsy[2].push_back('O'-'A');

    letsy[3].push_back('T'-'A');
    letsy[3].push_back('H'-'A');
    letsy[3].push_back('R'-'A');
    letsy[3].push_back('E'-'A');
    letsy[3].push_back('E'-'A');

    letsy[4].push_back('F'-'A');
    letsy[4].push_back('O'-'A');
    letsy[4].push_back('U'-'A');
    letsy[4].push_back('R'-'A');

    letsy[5].push_back('F'-'A');
    letsy[5].push_back('I'-'A');
    letsy[5].push_back('V'-'A');
    letsy[5].push_back('E'-'A');

    letsy[6].push_back('S'-'A');
    letsy[6].push_back('I'-'A');
    letsy[6].push_back('X'-'A');

    letsy[7].push_back('S'-'A');
    letsy[7].push_back('E'-'A');
    letsy[7].push_back('V'-'A');
    letsy[7].push_back('E'-'A');
    letsy[7].push_back('N'-'A');

    letsy[8].push_back('E'-'A');
    letsy[8].push_back('I'-'A');
    letsy[8].push_back('G'-'A');
    letsy[8].push_back('H'-'A');
    letsy[8].push_back('T'-'A');

    letsy[9].push_back('N'-'A');
    letsy[9].push_back('I'-'A');
    letsy[9].push_back('N'-'A');
    letsy[9].push_back('E'-'A');

    for (int i=0; i<10; i++)
    {
        for (int j=0; j<letsy[i].size(); j++)
        {
            if (kto[letsy[i][j]].empty() || kto[letsy[i][j]].back()!=i)
            kto[letsy[i][j]].push_back(i);
        }
    }

    scanf("%d", &t);
    for (int tt=1; tt<=t; tt++)
    {
        printf("Case #%d: ", tt);
        for (int i=0; i<26; i++)
        {
            wyn[i]=0;
            ile[i]=0;
            zab[i]=0;
        }
        scanf("%s", wcz+1);
        for (int i=1; wcz[i]; i++)
        {
            n++;
            ile[wcz[i]-'A']++;
        }
        while(!kon())
        {
            for (int i=0; i<10; i++)
            {
                if (!czymoz(i))
                {
                    zab[i]=1;
                }
            }
            int u=20;
            for (int i=0; i<10; i++)
            {
                if (!zab[i] && mus(i))
                {
                    u=i;
                    break;
                }
            }
            wyn[u]++;
            for (int i=0; i<letsy[u].size(); i++)
            {
                ile[letsy[u][i]]--;
            }
        }
        for (int i=0; i<10; i++)
        {
            for (int j=1; j<=wyn[i]; j++)
            {
                printf("%d", i);
            }
        }
        printf("\n");
    }
    return 0;
}
