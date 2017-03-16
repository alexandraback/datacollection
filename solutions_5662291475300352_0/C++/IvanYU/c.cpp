#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string.h>
#define INT64 long long
using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    int n;

    for (int _T = 1; _T <= T; ++_T)
    {
        int d, m, h;
        INT64 x[2],y[2];
        scanf("%d", &n);
        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d %d %d",&d,&m,&h);
            while(m > 0){
                x[cnt] = d;
                y[cnt] = h;
                h++;
                m--;
                cnt++;
            } 
        }
        if(cnt == 1){
            //printf("jizz\n");
            printf("Case #%d: 0\n", _T);
            continue;
        }

        if(y[0] > y[1]) swap(y[0], y[1]), swap(x[0], x[1]);

        if(y[0]*(720 - x[0]) <= y[1]*(360 - x[1]))
            ans = 1;

        printf("Case #%d: %d\n", _T, ans);
    }

}