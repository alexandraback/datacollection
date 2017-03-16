#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<list>
using namespace std;
#define INF (1<<29)
#define min(x,y) (((x)<(y))?(x):(y))
#define max(x,y) (((x)>(y))?(x):(y))
#define FOR(i,x,y) for(int i=(x);i<(y);++i)
#define FOE(i,x,y) for(int i=(x);i<=(y);++i)
#define FIT(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); ++it)
#define CLR(i) memset(i,0,sizeof(i))
#define eps (1e-8)
#define feq(x,y) (fabs((x)-(y))<=eps)
#define fgt(x,y) (((x)-(y)) > eps)
#define flt(x,y) (((y)-(x)) > eps)
#define fgeq(x,y) (fgt(x,y) || feq(x,y))
#define fleq(x,y) (flt(x,y) || feq(x,y))
#define ll long long

char s[200];

int main(){
    int T; scanf("%d",&T); gets(s);
    FOE(t,1,T){
        gets(s);
        int n = strlen(s);
        int cnt = 0;
        while (s[n-1] == '+') --n;

        if (n >= 1){
            ++cnt;
            char tar = s[n-1];
            for(int i=n-2;i>=0;--i){
                if (s[i] != tar){
                    tar = s[i];
                    ++cnt;
                }
            }
        }

        printf("Case #%d: %d\n",t,cnt);
    }
    return 0;
}
