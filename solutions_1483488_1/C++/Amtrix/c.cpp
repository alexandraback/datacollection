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

int lo,hi;

bool was[10000000];

int numlen(int x){
    int ret = 0;
    while(x){
        ret ++;
        x /= 10;
    }
    return ret;
}

int main(){
    freopen("Ulaz.txt","r",stdin);
    freopen("Izlaz_gcj_c.txt","w",stdout);
    int tests; scanf("%d",&tests);

    for (int t = 1; t <= tests; ++t){
        memset(was, false, sizeof(was));
        scanf("%d%d",&lo,&hi);
        int n = numlen(lo);

        int push = 1;
        for (int j = 0; j < n; ++j)
            push *= 10;

        int sol = 0;

        for (int i = lo; i <= hi; ++i){
            if(was[i]) continue;

            int sz = 0;
            int pw = 1;
            int toleft = push;
            for (int j = 0; j < n; ++j){
                int val = (i%pw)*toleft + (i/pw);
                pw *= 10;
                toleft /= 10;
                if(numlen(val) != n || was[val] || val < lo || val > hi) {
                    was[val] =  true;
                    continue;
                }
                was[val] =  true;
                sz ++;
            }
            sol += (sz * (sz - 1)) >> 1;
        }

        printf("Case #%d: %d\n",t, sol);
    }
    return 0;
}
