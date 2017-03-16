#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <fstream>
#include <cstring>

using namespace std;
typedef long long LL;

int x, y;

int main()
{
    freopen("pogo.in","r",stdin);
    freopen("pogo.out","w",stdout);
    int nt, tt=1;
    cin>>nt;
    while (nt--)
    {
        cin>>x>>y;
        string ret="";
        for (int i=0;i<abs(x);i++)
            if (x>0) ret+="WE";
            else ret+="EW";
        for (int i=0;i<abs(y);i++)
            if (y>0) ret+="SN";
            else ret+="NS";
        cout<<"Case #"<<tt++<<": "<<ret<<endl;
    }
}
