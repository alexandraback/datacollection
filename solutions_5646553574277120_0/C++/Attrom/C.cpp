#include <cstdio>
#include <numeric>
#include <fstream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>

using namespace std;
int obt[302],v;

#define rep(i,n) for(int i = 1; i <= (n); i++)


void mark(int x)
{
    for(int i=v;i>=1;i--)
    {
        if(obt[i]==1) obt[i+x]=1;
    }
    obt[x]=1;
}

ifstream in("date.in");
ofstream out("date.out");
int main()
{
    int t,c,d,x,rez=0;
    in>>t;
    rep(i,t)
    {
        in>>c>>d>>v;

        rep(k,d)
        {
            in>>x;
            mark(x);
        }

        rep(j,v)
        {
            if(obt[j]==0)
            {
                mark(j);
                rez++;
            }
        }
        out<<"Case #"<<i<<": "<<rez<<"\n";
        for(int z=1;z<=302;z++) obt[z]=0;
        rez=0;
    }
    return 0;
}
