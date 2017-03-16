#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define bug puts("here");

using namespace std;

typedef long long ll;

const int maxn =  100086;
const ll mod = 1e9+7;

double a[maxn];

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.txt","w+",stdout);
    double c,f,x;
    int T;
    int kase = 0;
    cin >> T;
    while(T--)
    {
        kase ++;
        cin >> c >> f >> x;
        double ans = 88888888.0;
        int i;
        a[0] = 0;
        double now = 2.0;
        for(i=1;i<=int(x+0.5);i++)
        {

            a[i] = a[i-1] + c/now;
            now += f;
        }
        for(i=0;i<=int(x+0.5);i++)
        {
            ans = min(ans, a[i] + x/(2 + i*f));
        }
        printf("Case #%d: %.7lf\n",kase,ans);
    }
    fclose(stdin);
    fclose(stdout);
}
