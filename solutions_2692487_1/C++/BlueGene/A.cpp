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

int n, A, a[MaxN], Count, Ans;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("A-large.in.txt", "r", stdin);
    freopen("A-large.out.txt", "w", stdout);
    #endif
    int TestCase;
    cin >> TestCase;
    for (int Test = 1; Test <= TestCase; ++Test)
    {
        cin >> A;
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        sort(a+1, a+n+1);
        Count = 0;
        Ans = 0x7FFFFFFF;
        for (int i = 1, j; i <= n; i = j)
        {
            for (j = i; j <= n && a[j] < A; A += a[j++]);
            Ans = min(Ans, n-j+1+Count);
            if (j <= n)
                if (A > 1)
                    for (; A <= a[j]; A += A-1, ++Count);
                else
                    break;
        }
        cout << "Case #" << Test << ": " << Ans << endl;
    }
	return 0;
}
