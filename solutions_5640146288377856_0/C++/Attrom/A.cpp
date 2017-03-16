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

#define rep(i,n) for(int i = 1; i <= (n); i++)

ifstream in("date.in");
ofstream out("date.out");
int main()
{
    int t;
    int r,c,w,rez;
    in>>t;
    rep(i,t)
    {
        in>>r>>c>>w;
        if(c%w)   rez=r*(c/w)+w;
        else rez=r*(c/w)+w-1;

        out<<"Case #"<<i<<": "<<rez<<"\n";
    }
    return 0;
}
