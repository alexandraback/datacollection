#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define UPLOAD 1
#if UPLOAD
#define openFiles() freopen("osmos.in", "r", stdin); freopen("osmos.out", "w", stdout)
#else
#define openFiles()
#endif

int cases, armin, omotes, curtotes, totes;
int motes[105];

bool hp(int i, int j)
{
    return i<j;
}

int main()
{
    openFiles();
    scanf("%d", &cases);
    for(int q=1; q<=cases; q++)
    {
        scanf("%d%d", &armin, &omotes);
        for(int i=1; i<=omotes; i++)
        {
            scanf("%d", &motes[i]);
        }
        sort(motes+1, motes+omotes+1, hp);
        curtotes=0;
        totes=omotes;
        for(int i=1; i<=omotes; i++)
        {
            if(motes[i]>=armin)
            {
                if(curtotes+(omotes-i)+1<totes)
                {
                    totes=curtotes+(omotes-i)+1;
                }
                while(motes[i]>=armin && curtotes<=omotes)
                {
                    armin+=armin-1;
                    curtotes++;
                }
                if(curtotes>omotes)
                {
                    break;
                }
            }
            armin+=motes[i];
        }
        if(curtotes<totes)
        {
            totes=curtotes;
        }
        printf("Case #%d: %d\n", q, totes);
    }
    return 0;
}
