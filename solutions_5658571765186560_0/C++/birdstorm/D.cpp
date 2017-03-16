#include<bits/stdc++.h>
using namespace std;
const int MAXN=10005;
const int INF=0x3f3f3f3f;
char s[MAXN];
bool canfill[4][4][4]={
    {{1,0,0,0},{1,1,0,0},{1,0,0,0},{1,1,0,0}},
    {{1,1,0,0},{1,1,0,0},{1,1,1,0},{1,1,0,0}},
    {{1,0,0,0},{1,1,1,0},{1,0,1,0},{1,1,1,1}},
    {{1,1,0,0},{1,1,0,0},{1,1,1,1},{1,1,0,1}}
};
int main(){
    freopen("D-small-attempt2.in","r",stdin);
    freopen("D-small-attempt2.out","w",stdout);
    int t; cin>>t;
    for(int cs=1; cs<=t; cs++){
        int x, r, c;
        scanf("%d%d%d",&x,&r,&c);
        printf("Case #%d: ",cs);
        if(!canfill[r-1][c-1][x-1]) puts("RICHARD");
        else puts("GABRIEL");
    }
    return 0;
}

