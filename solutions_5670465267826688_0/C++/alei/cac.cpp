#include<bits/stdc++.h>
using namespace std;
typedef long long int uli;

char s[12345];
int m[8][8]={
    {0, 1, 2, 3, 4, 5, 6, 7},
    {1, 4, 3, 6, 5, 0, 7, 2},
    {2, 7, 4, 1, 6, 3, 0, 5},
    {3, 2, 5, 4, 7, 6, 1, 0},
    {4, 5, 6, 7, 0, 1, 2, 3},
    {5, 0, 7, 2, 1, 4, 3, 6},
    {6, 3, 0, 5, 2, 7, 4, 1},
    {7, 6, 1, 0, 3, 2, 5, 4}
};

int main(){ 
    freopen("c1.in","r",stdin);
    freopen("c1.out","w",stdout);
    int t,n;
    uli x;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
        scanf("%d %lld %s",&n,&x,s);
        int blk=0;
        for(int i=0;i<n;i++) blk=m[blk][s[i]-'h'];

        int tot=0;
        for(int i=0;i<(x%4);i++)tot=m[tot][blk];

        bool ok=false;
        if(tot==4){
            int lft=0;
            int ii=-1,ri=-1;
            for(int r=0;r<4 && ii==-1;r++){
                int v=lft;
                for(int i=0;i<n && ii==-1;i++){
                    v=m[v][s[i]-'h'];
                    if(v==1) ii=i,ri=r;
                }
                lft=m[lft][blk];
            }

            int rht=0;
            int ik=-1,rk=-1;
            for(int r=0;r<4 && ik==-1;r++){
                int v=rht;
                for(int i=n-1;i>=0 && ik==-1;i--){
                    v=m[s[i]-'h'][v];
                    if(v==3) ik=i,rk=r;
                }
                rht=m[blk][rht];
            }
            if(ii>=0 && ik>=0){
                uli tb=ri+rk+2;
                if(ii<ik)tb--;
                if(x>=tb) ok=true;
            }
        }
        if(ok)printf("Case #%d: YES\n",tt);
        else printf("Case #%d: NO\n",tt);
    }
    return 0;
}
