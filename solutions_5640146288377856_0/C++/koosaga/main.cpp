#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

int r,c,w;

int f(int x){
    if(x <= w) return 1;
    return f(x / 2) + f((x-1) / 2)  + 0;
}

int solve(){
    scanf("%d %d %d",&r,&c,&w);
    return f(c) + w - 1;
}

int main(){
    freopen("A-small-attempt2.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for (int i=1; i<=t; i++) {
        printf("Case #%d: %d\n",i,solve());
    }
}