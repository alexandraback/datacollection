#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int maxE;
vector<vector<int> > dp;
// day energy
int solveSmall(int day, int value, int e, int r, vector<int> &v)
{
    if (day >= v.size() ) return value;

    int maxy = 0;
    for (int i=0;i<=e;++i)
    {
        int newE = e - i + r;
        if ( newE > maxE ) newE = maxE;
        int tmp = solveSmall(day + 1, value + i * v[day], newE, r, v);
        if (tmp > maxy ) maxy = tmp;
    }
    return maxy;
}

int main(void)
{
    freopen("B-small.in", "r", stdin);
    freopen("B-small.out", "w", stdout);
    int t;
    scanf ("%d", &t);

     for (int _test=1;_test<=t;++_test) {
        int e, r, n, a;
        vector<int> v;
        scanf("%d %d %d", &e, &r, &n);
        maxE = e;

        for (int i=0;i<n;++i) {
            scanf("%d", &a);
            v.push_back(a);
        }
        int res = solveSmall(0, 0, e,r,v);
        printf("Case #%d: %d\n", _test, res);
     }

    return 0;
}
