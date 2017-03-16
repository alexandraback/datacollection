#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=105;

int K,C,S;

ll cal(int k,int c) {
    ll ret=1;
    for(int i=0; i<c; i++)ret*=k;
    return ret;
}

vector<ll>ans;

int path[maxn],cp;

ll calpath() {
    ll ret=1;
    for(int i=0; i<cp; i++)
        ret+=(path[i]-1)*cal(K,C-i-1);
    return ret;
}

int main() {
    //freopen("in.cpp","r",stdin);
    freopen("D-large.in","r",stdin);
    freopen("out","w",stdout);
    int ncase=0;
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d%d",&K,&C,&S);
        ans.clear();
        for(int i=1; i<=K;) {
            cp=0;
            for(int j=i; j<=K&&j-i+1<=C; j++)
                path[cp++]=j;
            ans.push_back(calpath());
            i=path[cp-1]+1;
        }
        if(ans.size()<=S) {
            printf("Case #%d:",++ncase);
            for(int i=0; i<ans.size(); i++)printf(" %lld",ans[i]);
            printf("\n");
        } else printf("Case #%d: IMPOSSIBLE\n",++ncase);
    }
    return 0;
}
