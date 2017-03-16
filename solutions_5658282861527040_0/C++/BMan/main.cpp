//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<cmath>
#include<climits>
#include<string>
#include<map>
#include<queue>
#include<vector>
#include<stack>
#include<set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define pb(a) push(a)
#define INF 0x1f1f1f1f
#define lson idx<<1,l,mid
#define rson idx<<1|1,mid+1,r
#define PI  3.1415926535898
template<class T> T min(const T& a,const T& b,const T& c) {
    return min(min(a,b),min(a,c));
}
template<class T> T max(const T& a,const T& b,const T& c) {
    return max(max(a,b),max(a,c));
}
void debug() {
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
   // freopen("d:\\out1.txt","w",stdout);
#endif
}
int getch() {
    int ch;
    while((ch=getchar())!=EOF) {
        if(ch!=' '&&ch!='\n')return ch;
    }
    return EOF;
}

const int maxn = 110;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int ca = 1; ca <= t; ca++)
    {
        int a, b, k;
        scanf("%d%d%d", &a, &b, &k);
        int res = 0;
        for(int i = 0; i < a; i++)
            for(int j = 0; j < b; j++)
                if((i&j) < k) res++;
        printf("Case #%d: %d\n", ca, res);
    }
    return 0;
}
