#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

set < pair<int, int> > res;

int power[10];

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    power[0] = 1;
    for (int i = 1; i < 10; i++) power[i] = power[i-1]*10;
    int t;
    scanf("%d", &t);
    for (int no = 1; no <= t; no++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        int n = 1;
        int temp = a;
        while (temp/10!=0) n++, temp/=10;
        res.clear();
        for (int i = a; i < b; i++)
        {
            for (int j = 1; j < n; j++)
            {
                temp = i/power[j] + (i%power[j])*power[n-j];
                if (temp <= b && temp > i) res.insert(make_pair(i, temp));
            }
        }
        printf("Case #%d: %d\n", no, res.size());
    }
}
