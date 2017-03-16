#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long LL;

const LL maxv = 100000000000000LL;

vector<LL> res;

bool check(LL x)
{
    vector<int> ar;

    while(x)
    {
        ar.push_back(x % 10);
        x /= 10;
    }

    int N = ar.size();
    int n = N / 2,i;

    for(i = 0;i < n;i++)
    {
        if(ar[i] != ar[N - 1 - i])
            return false;
    }
    return true;
}

LL get1(LL x)
{
    LL ret = x;
    while(x)
    {
        ret = ret * 10 + (x % 10);
        x /= 10;
    }
    return ret;
}

LL get2(LL x)
{
    LL ret = x;
    x /= 10;
    while(x)
    {
        ret = ret * 10 + (x % 10);
        x /= 10;
    }
    return ret;
}

void init()
{
    LL i;
    for(i = 1;i <= 5000;i++)
    {
        LL x1 = get1(i);
        LL x2 = get2(i);

        LL y1 = x1 * x1;
        LL y2 = x2 * x2;

        if(y1 <= maxv && check(y1))
            res.push_back(y1);

        if(y1 == y2) continue;

        if(y2 <= maxv && check(y2))
            res.push_back(y2);
    }
}

int main()
{
    init();

    int ca,cn,i;

    LL a,b;

    freopen("CL1.in","r",stdin);
    freopen("CL1.out","w",stdout);

    cin >> cn;
    for(ca = 1;ca <= cn;ca ++)
    {
        cout << "Case #"<< ca << ": ";

        int n = res.size(),cnt = 0;

        cin >> a >> b;
        for(i = 0;i < n;i++)
        {
            if(res[i] >= a && res[i] <= b) cnt++;
        }

        cout << cnt << endl;
    }
    return 0;
}
