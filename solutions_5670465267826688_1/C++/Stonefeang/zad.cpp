#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

pair <int,char> tabl[500][500];

int t;

int n;
long long x;

char tab[1000007];
pair <int,char> co[1000007];

pair <int,char> mno(pair <int,char> a, char b)
{
    pair <int,char> ret=tabl[a.second][b];
    ret.first^=a.first;
    return ret;
}

int piei;
int piej;

int main()
{
    tabl['1']['1']=make_pair(0, '1');
    tabl['1']['i']=make_pair(0, 'i');
    tabl['1']['j']=make_pair(0, 'j');
    tabl['1']['k']=make_pair(0, 'k');
    tabl['i']['1']=make_pair(0, 'i');
    tabl['j']['1']=make_pair(0, 'j');
    tabl['k']['1']=make_pair(0, 'k');

    tabl['i']['i']=make_pair(1, '1');
    tabl['j']['j']=make_pair(1, '1');
    tabl['k']['k']=make_pair(1, '1');

    tabl['i']['j']=make_pair(0, 'k');
    tabl['j']['k']=make_pair(0, 'i');
    tabl['k']['i']=make_pair(0, 'j');

    tabl['j']['i']=make_pair(1, 'k');
    tabl['k']['j']=make_pair(1, 'i');
    tabl['i']['k']=make_pair(1, 'j');
    scanf("%d", &t);
    for (int h=1; h<=t; h++)
    {
        scanf("%d%lld", &n, &x);
        if (x>20)
        {
            x-=21;
            x%=20;
            x+=21;
        }
        scanf("%s", tab);
        for (int i=0; i<n*x; i++)
        {
            tab[i]=tab[i%n];
        }
        co[0].first=0;
        co[0].second=tab[0];
        for (int i=1; i<n*x; i++)
        {
            co[i]=mno(co[i-1], tab[i]);
        }
        piei=-1;
        piej=-1;
        for (int i=0; i<n*x; i++)
        {
            if (!co[i].first && co[i].second=='i')
            {
                piei=i;
                break;
            }
        }
        for (int i=piei+1; i<n*x; i++)
        {
            if (!co[i].first && co[i].second=='k')
            {
                piej=i;
                break;
            }
        }
        printf("Case #%d: ", h);
        if (piei>=0 && piej>piei && piej<n*x-1 && co[n*x-1].first && co[n*x-1].second=='1')
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
