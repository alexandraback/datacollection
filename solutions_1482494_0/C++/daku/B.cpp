/*
 * =====================================================================================
 *
 * Nazwa pliku:  	B.cpp
 * Autor:		Szymon Stankiewicz (Daku)
 * Kontakt:		dakurels@gmail.com
 * Stworzony:		28.04.2012 02:59:45
 *
 * =====================================================================================
*/
#include<iostream>
#include<cstdio>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
#include<deque>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<sstream>
#include<cstring>
 using namespace std;

long long int lvl[1000][2], K;

bool comp(long long a, long long b)
{
     return lvl[a][1]>lvl[b][1];
}

bool test(int a, long long C)
{
    bool x=true;
    long long stars=0;
    bool wyk[1000][2];
    for (int i = 0; i<C; i++)
    {
        wyk[i][0]=false;
        wyk[i][1]=false;
    }
    while(x && stars<2*C)
    {
        x=false;
        for (int i = 0; i<C; i++)
        {
            for(int j=0; j<=1; j++)
                if(lvl[i][j]<=stars && !wyk[i][j])
                {
                    x=true;
                    stars++;
                    wyk[i][j]=true;
                }
        }
    }
    if(stars<2*C)
    {
        printf("Case #%d: Too Bad\n", a);
        return true;
    }
    return false;
}

void calc(int a)
{
    long long X, help, posort[1000], C, stars, out, iter=0;
    bool done[1000][2], que[1000];
    pair<long long, long long> pom;
    priority_queue<pair<long long, long long> > moz;
    scanf("%lld", &C);
    X=2*C;
    for (int i = 0; i<C; i++)
    {
        scanf("%lld %lld", &lvl[i][0], &lvl[i][1]);
//        printf("%lld %lld\n", lvl[i][0], lvl[i][1]);
        posort[i]=i;
        done[i][0]=false;
        done[i][1]=false;
        que[i]=false;
    }
    if(test(a, C))
        return;
    sort(posort, posort+C, comp);
  for (int i = 0; i<C; i++)
    {
//        printf("%lld %lld\n", lvl[i][0], lvl[i][1]);
    }
    stars=0;
    out=0;
    while(stars<X)
    {
        help=posort[C-1];
        while(C>0 && lvl[help][1]<=stars)
        {
//            printf("BIG %lld %lld\n", help, lvl[help][1]);
            stars++;
            done[help][1]=true;
            if(!done[help][0])
            {
                stars++;
                done[help][0]=true;
            }
            C--;
            out++;
            help=posort[C-1];
        }
        for (int i = 0; i<C; i++)
        {
            help=posort[i];
            if(lvl[help][0]<=stars && !done[help][0])
            {
                stars++;
                out++;
                done[help][0]=true;
                break;
            }
        }
        if(stars==X)
            break;
        /*if(moz.empty())
        {
            printf("LOL\n");
            //printf("Case #%d: Too Bad\n", a);
            return;
        }*/
/*        if(moz.size()>2)
        {
            while(!moz.empty())
            {
                pom=moz.top();
                moz.pop();
                printf("%lld\n", pom.first);
            }
            return ;
        }*/
        /*pom=moz.top();
        moz.pop();
        stars++;
        done[pom.second][0]=true;
        out++;*/
//       printf("SMA %lld\n", pom.second);
    }
    printf("Case #%d: %lld\n", a, out);
}

int main()
{
    scanf("%lld", &K);
    for (int i =1; i<=K; i++)
        calc(i);
    return 0;
}
