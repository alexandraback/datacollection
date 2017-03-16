#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000000 + 10;

int tc, a, n, res;

int mot[N];

void input()
{
    int i;
    scanf("%d %d", &a, &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &mot[i]);
    }
}

void process()
{
    int i, c = 0;
    long long m = a;
    sort(mot, mot + n);
    
    res = n;
    if(a == 1)
    {
        return;
    }
    
    for(i = 0; i < n; i++)
    {
        res = min(res, n - i + c);
        for(; m <= (long long)mot[i]; m = (m << 1) - 1, c++);
        m += (long long)mot[i];
    }
    res = min(res, c);
}

void output()
{
    printf("Case #%d: %d\n", tc, res);
}

int main()
{
    int t;
    
    freopen("/Users/protos37/Downloads/A-large.in", "r", stdin);
    freopen("/Users/protos37/Downloads/A-large.out", "w", stdout);
    
    scanf("%d", &t);
    
    for(tc = 1; tc <= t; tc++)
    {
        input();
        process();
        output();
    }
}