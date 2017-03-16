#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <ctime>
#include <iterator>
#include <utility>
#include <numeric>
#include <functional>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>

using namespace std;

const int MaxN = 110;

int n, m, w;
int f[MaxN];

int main()
{
    freopen("A-small-attempt2.in.txt", "r", stdin);
    freopen("A-small-attempt2.out.txt", "w", stdout);
    //freopen("A-large.in.txt", "r", stdin);
    //freopen("A-large.out.txt", "w", stdout);
    int TestCase;
    cin >> TestCase;
    for (int Test = 1; Test <= TestCase; ++Test)
    {
        cin >> n >> m >> w;
        memset(f, 63, sizeof(f));
        f[w] = w;
        for (int i = w+1, j, k; i <= m; ++i)
            for (j = 1; j <= i; ++j)
            {
                k = w+int(i != w && j != 1 && j != i);
                if (j > w)
                    k = max(k, f[j-1]+(m-j)/w+1);
                if (i-j >= w)
                    k = max(k, f[i-j]+(j-1)/w+1);
                f[i] = min(f[i], k);
            }
        cout << "Case #" << Test << ": " << m/w*(n-1)+f[m] << endl;
    }
    return 0;
}
