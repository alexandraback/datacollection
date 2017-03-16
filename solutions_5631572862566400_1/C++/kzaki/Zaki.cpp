#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<string>
#include<cstring>
#include<bitset>
#define pii pair<int,int>
#define A first
#define B second
using namespace std;
int n,J,ct,ans;
int BFF[1001],tag[1001],BBFF[1001];
vector <int> E[1001];
int TRY1(int i,int sv){
    if(tag[i] == sv){
        if(i != sv) return -10000;
        else return 0;
    }

    tag[i] = sv;
    return TRY1(BFF[i],sv)+1;
}
int TRY2(int now,int par){
    int sv = 0;
    for(int i=0;i<E[now].size();i++)
        if(E[now][i] != par)
            sv = max(sv,TRY2(E[now][i],now));
    return sv+1;
}
void Do(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) E[i].clear(), tag[i] = 0;
    for(int i=1;i<=n;i++){
        scanf("%d",&BFF[i]);
        E[BFF[i]].push_back(i);
        E[i].push_back(BFF[i]);
    }
    ans = 0;
    ct = 0;
    for(int i=1;i<=n;i++)
        ans = max(ans,TRY1(i,i));
    for(int i=1;i<=n;i++){
        if(BFF[BFF[i]] == i){
            ct = ct +  TRY2(i,BFF[i]) + TRY2(BFF[i],i);
        }
    }
    ans = max(ans,ct/2);
    printf("%d",ans);
}
int main(){
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int rr=1;rr<=T;rr++){
        printf("Case #%d: ",rr);
        Do();
        printf("\n");
    }
    return 0;
}
