#include <cstdio>
#include <algorithm>
using namespace std;

int N,S,P,x;
int main () {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for (int z=1;z<=T;++z) {
    scanf("%d %d %d",&N,&S,&P);
    int cnt1=0,cnt2=0;
    for (int i=1;i<=N;++i) {
        scanf("%d",&x);
        if ((x+2)/3>=P) ++cnt1;
        else if (x && x%3!=1 && (x+2)/3+1>=P) ++cnt2;
    }
    printf("Case #%d: %d\n",z,cnt1+min(cnt2,S));
    }
    return 0;
}
