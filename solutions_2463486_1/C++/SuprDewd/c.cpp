#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <fstream>
#include <cassert>
using namespace std;

#define all(o) (o).begin(), (o).end()
#define allr(o) (o).rbegin(), (o).rend()
const int INF = 2147483647;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> int size(T x) { return x.size(); }

// assert or gtfo

bool is_pal(long long n)
{
    long long rev = 0, tmp = n;
    while (tmp)
    {
        rev = rev * 10 + (tmp % 10);
        tmp /= 10;
    }

    return rev == n;
}

int main()
{
    int mxn = 10000000 + 1000;
    int* cnt = new int[mxn];

    cnt[0] = 0;
    for (int i = 1; i < mxn; i++)
    {
        cnt[i] = cnt[i - 1];
        if (is_pal(i) && is_pal(static_cast<long long>(i)*i))
        {
            cnt[i]++;
        }
    }


    int ts;
    scanf("%d\n", &ts);
    for (int t = 0; t < ts; t++)
    {
        long long a, b;
        cin >> a >> b;

        int as = static_cast<int>(sqrt(static_cast<double>(a))),
            bs = static_cast<int>(sqrt(static_cast<double>(b))) + 1;
        
        int res = (static_cast<long long>(bs) * bs > b ? cnt[bs-1] : cnt[bs]) - (static_cast<long long>(as) * as == a ? cnt[as - 1] : cnt[as]);
        printf("Case #%d: %d\n", t+1, res);
    }
    
    return 0;
}

