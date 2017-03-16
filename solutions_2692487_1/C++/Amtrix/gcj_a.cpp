#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <assert.h>
#include <math.h>
#include <iomanip>
using namespace std;

typedef long long ll;

#define f first
#define s second
#define mk make_pair
#define pii pair<int,int>

const int maxn = 100 + 55;

int n,m;
int arr[maxn];

int main() {
    freopen("Ulaz.txt","r",stdin);
    freopen("Izlaz.txt","w",stdout);
    int tests; scanf("%d",&tests);
    for (int t = 1; t <= tests; ++t) {
        scanf("%d%d",&m,&n);
        for (int i = 0; i < n; ++i)
            scanf("%d",arr+i);
        sort(arr, arr + n);

        int sol = n;
        int curr = 0;
        int add = 0;
        while (curr < n) {
            if (m > arr[curr]) m += arr[curr++];
            else if (m-1 > 0) m += m-1, add++;
            else break;
            sol = min(sol, add + n - curr);
        }

        printf("Case #%d: %d\n",t,sol);
    }
    return 0;
}
