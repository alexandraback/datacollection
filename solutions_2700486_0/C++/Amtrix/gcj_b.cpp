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
#include <fstream>
using namespace std;

typedef long long ll;

#define f first
#define s second
#define mk make_pair
#define pii pair<int,int>

int n,c,r;

int main() {
    freopen("Ulaz.txt","r",stdin);
    freopen("Izlaz.txt","w",stdout);
    int tests; scanf("%d",&tests);
    for (int t = 1; t <= tests; ++t) {
        scanf("%d%d%d",&n,&c,&r);
        int level = (r + abs(c)) / 2;

        int sub = 1;
        int dst = r;
        for (int i = 0; i < level; ++i) {
            n -= sub;
            sub += 4;
        }
        //cout<<"S: "<<n<<" , "<<dst<<" "<<level<<" sub: "<<sub<<endl;
        printf("Case #%d: ",t);
        if (sub <= n) {
            printf("1.0\n");
            continue;
        } else if (n <= 0) {
            printf("0.0\n");
            continue;
        } else if(c == 0 && sub != n) {
            printf("0.0\n");
            continue;
        }

        int need = dst + 1;
        int capacity = sub / 2;

      //  cout<<endl<<capacity<<" , "<<need<<" , "<<n<<endl;
        int cnt = 0;
        int good = 0;
        for (int r = 0; r <= n; ++r) {
            int l = n - r;
            if (r > capacity || l > capacity) continue;
            int a = 1;
            if (l == r) a = 2;
            cnt += a;
            if (l >= need) good+= a;
        }
        printf("%.10lf\n",good/(double)cnt);

    }
    return 0;
}
