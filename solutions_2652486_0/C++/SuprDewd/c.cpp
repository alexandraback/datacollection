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

int main()
{
    vector<pair<int, multiset<int> > > res;
    for (int a = 2; a <= 5; a++)
    {
        for (int b = a; b <= 5; b++)
        {
            for (int c = b; c <= 5; c++)
            {
                multiset<int> ms;
                for (int i = 0; i < 1 << 3; i++)
                {
                    int prod = 1;
                    if (i & (1 << 0)) prod *= a;
                    if (i & (1 << 1)) prod *= b;
                    if (i & (1 << 2)) prod *= c;
                    ms.insert(prod);
                    // printf("%d %d %d\n", a, b, c, prod);
                }

                res.push_back(make_pair(a * 100 + b * 10 + c, ms));
            }
        }
    }

    int ts;
    scanf("%d\n", &ts);
    for (int t = 0; t < ts; t++)
    {
        printf("Case #%d:\n", t+1);

        int sum = 0;
        int r, n, m, k;
        scanf("%d %d %d %d\n", &r, &n, &m, &k);
        for (int i = 0; i < r; i++)
        {
            // int* prods = new int[k];
            multiset<int> prods;
            set<int> pvals;
            for (int j = 0; j < k; j++)
            {
                int tmp;
                scanf("%d", &tmp);
                prods.insert(tmp);
                pvals.insert(tmp);
                // scanf("%d", prods + j);
            }

            double bestprob = 0; int curbest = 123;
            // vector<pair<int, multiset<int> > > maybe;
            for (int y = 0, cnt = size(res); y < cnt; y++)
            {
                // bool ok = true;

                // for (int j = 0; j < k; j++)
                // {
                //     ok = ok && res[y].second.count(prods[j]) > 0;
                // }

                // if (ok)
                // {
                //     maybe.push_back(res[y]);
                // }

                double curp = 1;

                for (set<int>::iterator it = pvals.begin(); it != pvals.end(); ++it)
                {
                    curp *= res[y].second.count(*it) / prods.count(*it);
                }

                if (curp > bestprob)
                {
                    bestprob = curp;
                    curbest = res[y].first;
                }
            }

            // printf("count = %d\n", size(maybe));
            // printf("%d\n", maybe[rand() % size(maybe)].first);
            // delete[] prods;
            // sum += size(maybe);
            printf("%d\n", curbest);
        }

        // printf("avg = %lf\n", sum / static_cast<double>(r));
    }

    return 0;
}
