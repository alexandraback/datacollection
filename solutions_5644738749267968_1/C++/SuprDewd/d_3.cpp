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

int main()
{
    int ts;
    scanf("%d\n", &ts);

    for (int t = 0; t < ts; t++)
    {
        int n;
        scanf("%d\n", &n);

        vector<double> a(n), b(n);

        for (int i = 0; i < n; i++)
            scanf("%lf", &(a[i]));

        for (int i = 0; i < n; i++)
            scanf("%lf", &(b[i]));

        sort(all(a));
        sort(all(b));

        int cnt = 0;
        for (int i = 0, j = 0; i < n; i++)
        {
            while (j < n && b[i] > a[j])
                j++;

            if (j == n)
                break;

            cnt++;
            j++;
        }


        int cnt2 = 0;
        for (int i = 0; i < n; i++)
        {
            int j = i;
            while (j < n && a[i] > b[j])
                j++;

            if (j == n)
                j = i;

            swap(b[i], b[j]);

            if (a[i] > b[i])
                cnt2++;
        }

        printf("Case #%d: ", t+1);
        printf("%d %d\n", cnt, cnt2);
    }

    return 0;
}

