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

int main()
{
    freopen("new_lottery_game.in","r",stdin);
    freopen("new_lottery_game.out","w",stdout);
    int tc, nt=1;
    cin>>tc;
    while (tc--)
    {
        int a, b, k;
        cin>>a>>b>>k;
        int ret=0;
        for (int i=0;i<a;i++)
            for (int j=0;j<b;j++)
                if ((i&j)<k) ret++;
        cout<<"Case #"<<nt++<<": "<<ret<<endl;
    }
}
