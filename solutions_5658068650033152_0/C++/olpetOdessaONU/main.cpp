#pragma comment(linker, "/STACK:65000000")
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<cstring>
#include<string>
#include<cmath>
#include<complex>
#include<ctime>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<int> vi;
typedef vi::iterator vit;
typedef set<ll> si;
typedef si::iterator sit;
typedef vector<pii> vpi;

#define sq(x) ((x)*(x))
#define all(x) (x).begin(),(x).end()
#define cl(x) memset(x,0,sizeof(x))
//#define LL "%I64d"
#define RLL(x) scanf(LL,&(x))

int n, m, k;

int getSq(int base, int &height)
{
    height = min(height, (base - 1) / 2);
    base -= 2;
    if(base <= 0 || height <= 0)
        return 0;
    return height * (base - height + 1);
}

int mas[4];

void test(int T)
{
    cin>>n>>m>>k;
    int answ = k;
    for(int x = 2; x <= n; ++x)
        for(int y = 2; y <= m; ++y)
        {
            int tmpS = x * y - 4;
            int tmpV = 2 * (x + y - 4);
            int width = (n - x) / 2;
            int height = (m - y) / 2;
            int width2 = n - x - width;
            int height2 = m - y - height;
            tmpS += getSq(y - 2, width) + getSq(y - 2, width2);
            tmpS += getSq(x - 2, height) + getSq(x - 2, height2);
            if(x == 3 && y == 7)
            {
                int kkk = -1;
            }
            mas[0] = width + height + 2;
            mas[1] = width2 + height + 2;
            mas[2] = width + height2 + 2;
            mas[3] = width2 + height2 + 2;
            sort(mas, mas+4);
            if(tmpS >= k)
                answ = min(answ, tmpV);
            else
            {
                for(int i=3; i>=0 && tmpS < k; --i)
                {
                    if(mas[i] == 0)
                        break;
                    ++tmpV;
                    tmpS += mas[i] - 1;
                }
                answ = min(answ, tmpV + max(k - tmpS, 0));
                if(answ == 12)
                {
                    int kkk = -1;
                }
            }
        }
    printf("Case #%d: %d\n", T, answ);
}

int main(int argc, const char * argv[])
{
    
    freopen("/Users/olpet/Downloads/GCJ/c.in", "r", stdin);
    freopen("/Users/olpet/Downloads/GCJ/c.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; ++t)
        test(t+1);
    return 0;
}