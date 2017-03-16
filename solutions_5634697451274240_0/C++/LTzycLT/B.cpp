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


char a[200];
int main() {
    freopen("/home/zyc/Downloads/in", "r", stdin);
    freopen("/home/zyc/Downloads/out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++)
    {
        scanf("%s", a); 
        int l = strlen(a);
        int n = 0;
        for(int i = 1; i < l; i++)
        {
            if(a[i] != a[i - 1]) n += 1;
        }
        if(a[l - 1] != '+') n += 1;
        printf("Case #%d: %d\n", cas, n);
    }
    return 0;
}
