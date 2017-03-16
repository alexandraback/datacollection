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
    int ts;
    scanf("%d\n", &ts);
    for (int t = 0; t < ts; t++)
    {
        int n, m;
        scanf("%d %d\n", &n, &m);
        int** arr = new int*[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = new int[m];
            for (int j = 0; j < m; j++)
            {
                scanf("%d", arr[i] + j);
            }
        }

        bool ok = true;

        for (int i = 0; ok && i < n; i++)
        {
            for (int j = 0; ok && j < m; j++)
            {
                bool a = true, b = true;

                for (int k = 0; k < n; k++)
                {
                    a = a && arr[i][j] >= arr[k][j];
                }

                for (int k = 0; k < m; k++)
                {
                    b = b && arr[i][j] >= arr[i][k];
                }

                ok = ok && (a || b);
            }
        }

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         printf("%d ", arr[i][j]);
        //     }

        //     printf("\n");
        // }

        printf("Case #%d: %s\n", t+1, ok ? "YES" : "NO");

        for (int i = 0; i < n; i++)
        {
            delete[] arr[i];
        }

        delete[] arr;
    }
    
    return 0;
}

