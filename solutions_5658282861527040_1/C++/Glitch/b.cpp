#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
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
template <class T> int size(T &x) { return x.size(); }

// assert or gtfo

int A[60], B[60], K[60];

ll memK[60][2][2][2];

ll cntK(int at, bool foundK, bool foundA, bool foundB)
{
    if (at == -1)
    {
        return 1;
    }

    if (memK[at][foundK][foundA][foundB] != -1)
        return memK[at][foundK][foundA][foundB];

    ll res = 0;
    for (int kd = 0; kd <= 1; kd++)
    {
        if (kd > K[at] && !foundK)
            continue;

        for (int ad = 0; ad <= 1; ad++)
        {
            if (ad > A[at] && !foundA)
                continue;

            for (int bd = 0; bd <= 1; bd++)
            {
                if (bd > B[at] && !foundB)
                    continue;

                if (kd == (ad & bd))
                {
                    res += cntK(
                        at - 1,
                        foundK || kd < K[at],
                        foundA || ad < A[at],
                        foundB || bd < B[at]
                    );
                }
            }
        }
    }

    return memK[at][foundK][foundA][foundB] = res;
}

int main()
{
    int ts;
    scanf("%d\n", &ts);

    for (int t = 0; t < ts; t++)
    {
        printf("Case #%d: ", t+1);

        ll a, b, k;
        cin >> a >> b >> k;
        a--;
        b--;
        k--;

        for (int i = 50; i >= 0; i--)
        {
            A[i] = (1LL << i) & a ? 1 : 0;
            B[i] = (1LL << i) & b ? 1 : 0;
            K[i] = (1LL << i) & k ? 1 : 0;
        }

        memset(memK, -1, sizeof(memK));

        cout << cntK(50, false, false, false) << endl;
    }

    return 0;
}

