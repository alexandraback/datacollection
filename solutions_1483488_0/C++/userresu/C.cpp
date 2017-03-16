#include <cstdio>
#include <set>
using namespace std;

int A,B;
set<int> used;
int main () {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for (int z=1;z<=T;++z) {
    scanf("%d %d",&A,&B);
    int cnt=0;
    int d=1,t=A;
    while (t>0) { d*=10; t/=10; }
    d/=10;
    for (int i=A;i<=B;++i) {
        used.clear();
        int a=i,b=i;
        while (b>0) {
              a=(a%10)*d+(a/=10);
              b/=10;
              if (i<a && a>=A && a<=B && used.find(a)==used.end()) {
                 ++cnt;
                 used.insert(a);
              }
        }
    }
    printf("Case #%d: %d\n",z,cnt);
    }
    return 0;
}
