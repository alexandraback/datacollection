#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <cstring>
#include <fstream>

using namespace std;
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()
#define FOR(i,s,n) for(int i=(s);i<(n);++i)
#define REP(i,n) FOR(i,0,(n))
#define PB(x) push_back((x))
#define CLR(a,v) memset((a),(v),sizeof((a)))
typedef long long ll;

string f(int x, int n)
{
    if(x<0)throw "XXX";
    string res(n, '0');

    REP(i,n)res[n-1-i]=(x%10)+'0', x/=10;

    return res;
}

bool g(string a, string b)
{
    int n = SZ(a);
    REP(i,n)if(a[i]!='?'&&a[i]!=b[i])return false;
    return true;
}

int sz[4] = {0, 10, 100, 1000};

void solve()
{
    string a,b;
    cin>>a>>b;

    int diff=100500, ra=-1,rb=-1,n=SZ(a);

    REP(i,sz[n])REP(j,sz[n])
    {
        int d = abs(i-j);
        if(d>=diff)continue;

        string aa=f(i,n), bb=f(j,n);
        if(g(a,aa)&&g(b,bb))
        {
            diff = d, ra = i, rb = j;
        }
    }

    cout << f(ra, n) << " " << f(rb, n) << endl;
}


int main()
{
    //freopen("../input.txt", "r", stdin);
    freopen("../data/B-small-attempt1.in", "r", stdin);
    freopen("../output.txt", "w+", stdout);

    int T;
    scanf("%d", &T);
    REP(i, T)
    {
        printf("Case #%d: ", i+1);
        solve();
    }

    return 0;
}
