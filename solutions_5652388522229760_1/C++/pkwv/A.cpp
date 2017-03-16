//#pragma comment(linker,"/STACK:102400000,102400000")
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>
#include<list>
//#include<ext/rope>
#define PB push_back
#define MP make_pair
#define PF push_front
#define lson k<<1
#define rson k<<1|1
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ldb;

const int N = 100005;
bool has[18];

void calc(int n)
{
    if(n == 0)
    {
        has[0] = true;
        return;
    }
    while(n)
    {
        has[n % 10] = true;
        n /= 10;
    }
}

bool all()
{
    for(int i = 0; i < 10; i++) if(!has[i]) return false;
    return true;
}

int main()
{
#ifdef PKWV
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out","w",stdout);
#endif // PKWV
    int T, cas(1);
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        int last(-1);
        for(int i = 0; i < 10; i++) has[i] = false;
        for(int i = 1; i <= 100; i++)
        {
            calc(i * n);
            if(all())
            {
                last = i * n;
                break;
            }
        }
        printf("Case #%d: ", cas++);
        if(last == -1) printf("INSOMNIA\n");
        else printf("%d\n", last);
    }
    return 0;
}

