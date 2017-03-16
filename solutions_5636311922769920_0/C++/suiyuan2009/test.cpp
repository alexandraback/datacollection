#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn=105;


int k,c,s;

int main() {
    //freopen("in.cpp","r",stdin);
    freopen("D-small-attempt0.in","r",stdin);
    freopen("out","w",stdout);
    int ncase=0;
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d%d",&k,&c,&s);
        if(k!=s){
            printf("Case #%d: IMPOSSIBLE\n",++ncase);
            continue;
        }
        printf("Case #%d:",++ncase);
        for(int i=1;i<=k;i++)printf(" %d",i);
        printf("\n");
    }
    return 0;
}
