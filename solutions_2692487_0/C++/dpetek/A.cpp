#include<iostream>
#include<cstdio>
#include<vector>
#include <algorithm>
using namespace std;

int solve(int a, vector<int> &v, int index, int cnt) {
    if (index == v.size()) return cnt;
    if ( a <= v[index]) {


        int tmp = solve(a, v, index + 1, cnt + 1);
        if ( a - 1 > 0){
            int tmpCnt = cnt, tmpA = a;
            while (tmpA <= v[index]) {
                tmpA += tmpA - 1;
                tmpCnt ++;
            }

            if (v[index] - 1 > 0 ) {
                tmp = min (tmp, solve(tmpA + v[index], v, index + 1, tmpCnt));
            }
        }

        return tmp;

    } else {
        return solve(a + v[index], v, index + 1, cnt);
    }
}


int main(void)
{
    freopen("A-small.in", "r", stdin);
    freopen("A-small.out", "w", stdout);
    int t;
    scanf ("%d", &t);

     for (int _test=1;_test<=t;++_test) {
        int a, n , b;
        vector<int>v;
        scanf("%d %d", &a, &n);
        for (int i=0;i<n;++i) {
            scanf ("%d", &b);
            v.push_back(b);
        }
        sort(v.begin(), v.end());
        int res = solve(a, v, 0, 0);
        printf("Case #%d: %d\n", _test, res);
     }

    return 0;
}
