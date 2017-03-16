#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>
#include<string>
#include<set>
#include<queue>
#define MP(x,y) make_pair(x,y)
#define clr(x,y) memset(x,y,sizeof(x))
#define forn(i,n) for(int i=0;i<n;i++)
#define sqr(x) ((x)*(x))
#define MAX(a,b) if(a<b) a=b;
#define ll long long
using namespace std;


set<int> zyc;
int main() {
    freopen("/home/zyc/Downloads/in", "r", stdin);
    freopen("/home/zyc/Downloads/out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++)
    {
        zyc.clear();
        int n, i;
        scanf("%d", &n); 
        printf("Case #%d: ", cas);
        if(n == 0)
        {
            printf("INSOMNIA\n");
            continue;
        }

        for(i = 1; ; i++)
        {
            int x = i * n;
            while(x)
            {
                zyc.insert(x % 10); 
                x /= 10;
            }
            if(zyc.size() == 10)
            {
                break;
            }
        }
        printf("%d\n", i * n);
    }
    return 0;
}
