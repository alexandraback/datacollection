#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <string.h>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <cstdio>
#include <math.h>
#include <bitset>
#include <fstream>
#include <assert.h>
#include <iomanip>
#include <ctime>
using namespace std;

const int maxn = 10000;

int n,sup,p;
int sum[maxn];

int main(){
    freopen("Ulaz.txt","r",stdin);
    freopen("Izlaz_gcj_b.txt","w",stdout);
    int tests; scanf("%d",&tests);
    for (int t = 1; t <= tests; ++t){
        scanf("%d%d%d",&n,&sup,&p);
        for (int i = 0; i < n; ++i)
            scanf("%d",&sum[i]);

        int sol = 0;
        sort(sum, sum + n);
        reverse(sum, sum + n);
        for (int i = 0; i < n; ++i){
            int f = sum[i] / 3;
            int s = f, t = f;
            if(sum[i]%3 == 1) t ++;
            else if( sum[i]%3 == 2) s ++, t ++;

            if(t >= p) sol ++;
            else if (t < p && sup){
                if(f == s && s == t) t++,f--;
                else if(s == t) t++, s--;

                if(t>=p && t >= 0 && f >= 0 && s >= 0 && f <= 10 && s <= 10 && t <= 10){
                    sol++;
                    sup--;
                }
            }
        }

        printf("Case #%d: %d\n",t,sol);

    }
    return 0;
}
