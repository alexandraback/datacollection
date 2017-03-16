#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define REP(i,n) for(int i=0; i<(n); i++)

int n,s,t,v[110];
int pd[110][110];

bool surp(int a, int b, int c) {
    if (abs(a-b)==2 || abs(a-c)==2 || abs(b-c)==2) return true;
    return false;
}

bool valid(int a, int b, int c) {
    if (abs(a-b)<=2 && abs(a-c)<=2 && abs(b-c)<=2) return true;
    return false;
}

int calc(int x, int p) {
    if (p<0) return -1;
    if (x==n && !p) return 0;
    if (x==n) return -1;
    if (pd[x][p]!=-1) return pd[x][p];

    int res=-1;
    if (p) {
        for (int i=0;i<=10;i++)
            for (int j=0;j<=10;j++)
                for (int k=0;k<=10;k++)
                    if (surp(i,j,k) && valid(i,j,k) && i+j+k==v[x]) {
                        int pt=max(max(i,j),k)>=t?1:0;

                        res=max(res,calc(x+1,p-1)+pt);
                    }
    }

    for (int i=0;i<=10;i++)
        for (int j=0;j<=10;j++)
            for (int k=0;k<=10;k++)
                if (valid(i,j,k) && !surp(i,j,k) && i+j+k==v[x]) {
                    int pt=max(max(i,j),k)>=t?1:0;

                    res=max(res,calc(x+1,p)+pt);
                }
    
    return (pd[x][p]=res);
}

int main() {
    int nt;
    scanf("%d",&nt);

    for (int ct=1;ct<=nt;ct++) {
        memset(pd,-1,sizeof(pd));

        scanf("%d%d%d",&n,&s,&t);
        REP(i,n)
            scanf("%d",&v[i]);

        printf("Case #%d: %d\n",ct,calc(0,s));
    }
    return 0;
}
