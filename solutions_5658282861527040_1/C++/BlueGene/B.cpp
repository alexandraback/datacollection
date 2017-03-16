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
long long f[50][2][2][2];

int main()
{
    //freopen("B-small-attempt0.in.txt", "r", stdin);
    //freopen("B-small-attempt0.out.txt", "w", stdout);
    freopen("B-large.in.txt", "r", stdin);
    freopen("B-large.out.txt", "w", stdout);
    int TestCase;
    cin >> TestCase;
    for (int Test = 1; Test <= TestCase; ++Test)
    {
        cout << "Case #" << Test << ": ";
        cin >> A >> B >> K;
        --A, --B, --K;
        memset(f, 0, sizeof(f));
        f[31][1][1][1] = 1;
        for (int i = 31; i; --i)
        {
            int a = (A >> (i-1)) & 1;
            int b = (B >> (i-1)) & 1;
            int k = (K >> (i-1)) & 1;
            //000
            f[i-1][0][0][0] += f[i][0][0][0]*4;
            //100
            if (a)
            {
                f[i-1][0][0][0] += f[i][1][0][0]*2;
                f[i-1][1][0][0] += f[i][1][0][0]*2;
            }
            else
                f[i-1][1][0][0] += f[i][1][0][0]*2;
            //010
            if (b)
            {
                f[i-1][0][0][0] += f[i][0][1][0]*2;
                f[i-1][0][1][0] += f[i][0][1][0]*2;
            }
            else
                f[i-1][0][1][0] += f[i][0][1][0]*2;
            //001
            if (k)
            {
                f[i-1][0][0][0] += f[i][0][0][1]*3;
                f[i-1][0][0][1] += f[i][0][0][1];
            }
            else
                f[i-1][0][0][1] += f[i][0][0][1]*3;
            //110
            if (a && b)
            {
                f[i-1][0][0][0] += f[i][1][1][0];
                f[i-1][0][1][0] += f[i][1][1][0];
                f[i-1][1][0][0] += f[i][1][1][0];
                f[i-1][1][1][0] += f[i][1][1][0];
            }
            else if (a)
            {
                f[i-1][0][1][0] += f[i][1][1][0];
                f[i-1][1][1][0] += f[i][1][1][0];
            }
            else if (b)
            {
                f[i-1][1][0][0] += f[i][1][1][0];
                f[i-1][1][1][0] += f[i][1][1][0];
            }
            else
                f[i-1][1][1][0] += f[i][1][1][0];
            //101
            if (a && k)
            {
                f[i-1][0][0][0] += f[i][1][0][1]*2;
                f[i-1][1][0][0] += f[i][1][0][1];
                f[i-1][1][0][1] += f[i][1][0][1];
            }
            else if (a)
            {
                f[i-1][0][0][1] += f[i][1][0][1]*2;
                f[i-1][1][0][1] += f[i][1][0][1];
            }
            else if (k)
                f[i-1][1][0][0] += f[i][1][0][1]*2;
            else
                f[i-1][1][0][1] += f[i][1][0][1]*2;
            //011
            if (b && k)
            {
                f[i-1][0][0][0] += f[i][0][1][1]*2;
                f[i-1][0][1][0] += f[i][0][1][1];
                f[i-1][0][1][1] += f[i][0][1][1];
            }
            else if (b)
            {
                f[i-1][0][0][1] += f[i][0][1][1]*2;
                f[i-1][0][1][1] += f[i][0][1][1];
            }
            else if (k)
                f[i-1][0][1][0] += f[i][0][1][1]*2;
            else
                f[i-1][0][1][1] += f[i][0][1][1]*2;
            //111
            if (a && b && k)
            {
                f[i-1][0][0][0] += f[i][1][1][1];
                f[i-1][1][0][0] += f[i][1][1][1];
                f[i-1][0][1][0] += f[i][1][1][1];
                f[i-1][1][1][1] += f[i][1][1][1];
            }
            else if (a && b)
            {
                f[i-1][0][0][1] += f[i][1][1][1];
                f[i-1][1][0][1] += f[i][1][1][1];
                f[i-1][0][1][1] += f[i][1][1][1];
            }
            else if (a && k)
            {
                f[i-1][0][1][0] += f[i][1][1][1];
                f[i-1][1][1][0] += f[i][1][1][1];
            }
            else if (b && k)
            {
                f[i-1][1][0][0] += f[i][1][1][1];
                f[i-1][1][1][0] += f[i][1][1][1];
            }
            else if (a)
            {
                f[i-1][0][1][1] += f[i][1][1][1];
                f[i-1][1][1][1] += f[i][1][1][1];
            }
            else if (b)
            {
                f[i-1][1][0][1] += f[i][1][1][1];
                f[i-1][1][1][1] += f[i][1][1][1];
            }
            else if (k)
                f[i-1][1][1][0] += f[i][1][1][1];
            else
                f[i-1][1][1][1] += f[i][1][1][1];
        }
        long long Ans = 0;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                for (int k = 0; k < 2; ++k)
                    Ans += f[0][i][j][k];
        cout << Ans << endl;
    }
    return 0;
}
