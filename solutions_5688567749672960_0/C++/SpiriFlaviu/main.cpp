#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <map>
#include <bitset>
#include <stack>
/*  //c++11
#include <unordered_map>
#include <unordered_set>
#include <tuple>
*/

using namespace std;

ifstream fin("1.in");
ofstream fout("1.out");

long long sol[1000001];

long long rev(long long a)
{
    long long r = 0;
    while(a)
    {
        r = r * 10 + a % 10;
        a /= 10;
    }
    return r;
}



long long query()
{
    long long n;
    fin>>n;
    return sol[n];
}

int main()
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    int T;
    sol[1] = 1;
    for(int i = 2; i <= 1000000; i++)
    {
        int r = rev(i);
        if(rev(r) == i && i > r)
            sol[i] = min(sol[i-1] + 1, sol[r] + 1);
        else sol[i] = sol[i-1] +1;
    }
    fin>>T;
    for(int i = 1; i <= T; i++)
        fout<<"Case #"<<i<<": "<<query()<<'\n';
    //for(int i = 1; i <= 20; i++)
        //cout<<sol[i]<<' ';
    return 0;
}


//FILE!!!
