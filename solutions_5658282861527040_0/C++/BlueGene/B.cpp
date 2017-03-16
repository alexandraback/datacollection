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

long long A, B, K;
int f[50][2];

int main()
{
    freopen("B-small-attempt0.in.txt", "r", stdin);
    freopen("B-small-attempt0.out.txt", "w", stdout);
    int TestCase;
    cin >> TestCase;
    for (int Test = 1; Test <= TestCase; ++Test)
    {
        cout << "Case #" << Test << ": ";
        cin >> A >> B >> K;
        long long Ans = 0;
        for (int i = 0; i < A; ++i)
            for (int j = 0; j < B; ++j)
                if ((i & j) < K)
                    ++Ans;
        cout << Ans << endl;
    }
    return 0;
}
