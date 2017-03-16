#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=10;
char board[MAXN],target[MAXN],buf[MAXN];
int k,l,s,ans,maxv,next[MAXN];
void GetNext() {
    int j=0,k=-1;
    next[0]=-1;
    while(j<l) {
        while(k>-1&&target[j]!=target[k])
            k=next[k];
        if(target[++j]==target[++k])
            next[j]=next[k];
        else
            next[j]=k;
    }
}
int KMP(const char str[]) {
    int i=0,j=0,ret=0;
    while(i<s) {
        while(j>-1&&str[i]!=target[j])
            j=next[j];
        ++i;
        if(++j==l) {
            ++ret;
            j=next[j];
        }
    }
    return ret;
}
void dfs(int idx) {
    if(idx==s) {
        int cnt=KMP(buf);
        ans+=cnt;
        maxv=max(maxv,cnt);
        return;
    }
    for(int i=0; i<k; ++i) {
        buf[idx]=board[i];
        dfs(idx+1);
    }
}
int main() {
    //freopen("B-small-attempt0.in","r",stdin);
    //freopen("B-small-attempt0.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cas=1; cas<=t; ++cas) {
        scanf("%d%d%d%s%s",&k,&l,&s,board,target);
        ans=maxv=0;
        GetNext();
        dfs(0);
        printf("Case #%d: %f\n",cas,maxv-ans/pow(k,s));
    }
}
