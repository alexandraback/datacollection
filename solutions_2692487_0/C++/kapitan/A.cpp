#include <stdlib.h>
#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <deque>
#define FOR(x,z) for(int x=0;x<(z);++x)
#define DS(i) fprintf(stderr, "DEBUG: %s\n",i);
#define DI(i) fprintf(stderr, "DEBUG: %d\n",i);
#define DF(i) fprintf(stderr, "DEBUG: %f\n",i);
#define LL long long
#define ULL unsigned long long
using namespace std;
deque<int> m;
int A,N;
bool s(int a, int b)
{
    return a<b;
}
void wczytaj()
{
    m.clear();
    scanf("%d %d", &A,&N);
    int tmp;
    FOR(i,N)
    {
        scanf("%d",&tmp);
        m.push_back(tmp);
    }
    sort(m.begin(),m.end(),s);
    //FOR(i,N)
    //    printf("m: %d\n",m[i]);
}
void wykonaj()
{
    while(m.size()&&A>m.front())
    {
        A+=m.front();
        m.pop_front();
    }
    int w=m.size();
    //DI(A)
    int dod=0;
    FOR(i,w)
    {
        dod++;
        A+=A-1;
        while(m.size()&&A>m.front())
        {
            A+=m.front();
            m.pop_front();
        }
        int s=m.size();
        w=min(w,dod+s);
        if(m.size()==0)
            break;
    }
    printf("%d\n", w);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        wczytaj();
        DI(t)
        printf("Case #%d: ",t);
        wykonaj();
    }
    return 0;
}
