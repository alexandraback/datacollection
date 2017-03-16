#include<bits/stdc++.h>
using namespace std;
const int MAXN=10005;
const int INF=0x3f3f3f3f;
char s[MAXN];
char v[4][4]={
    '1','i','j','k',
    'i','0','k','J',
    'j','K','0','i',
    'k','j','I','0'
};
int val(char c){
    if(c=='1') return 1;
    if(c=='i') return 2;
    if(c=='j') return 3;
    if(c=='k') return 4;
    if(c=='0') return -1;
    if(c=='I') return -2;
    if(c=='J') return -3;
    if(c=='K') return -4;
}
map<int, map<int,int> > mp, decodeL, decodeR;
map<int,int> findLeft, findRight;
int pt[10];
void init(){
    for(int i=1; i<=4; i++){
        for(int j=1; j<=4; j++){
            int x=val(v[i-1][j-1]);
            mp[i][j]=x;
            decodeL[j][x]=i;
            decodeR[i][x]=j;
            mp[-i][j]=-x;
            decodeL[j][-x]=-i;
            decodeR[-i][x]=j;
            mp[i][-j]=-x;
            decodeL[-j][-x]=i;
            decodeR[i][-x]=-j;
            mp[-i][-j]=x;
            decodeL[-j][x]=-i;
            decodeR[-i][x]=-j;
        }
    }
}
int main(){
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    init();
    int t; cin>>t;
    for(int cs=1; cs<=t; cs++){
        long long X; int L; cin>>L>>X;
        scanf("%s",s);
        for(int i=-4; i<=4; i++) if(i){
            findLeft[i]=INF;
            findRight[i]=-INF;
        }
        int now=val(s[0]); findLeft[now]=0;
        for(int i=1; i<L; i++){
            now=mp[now][val(s[i])];
            findLeft[now]=min(findLeft[now],i);
        }
        int now1=now;
        now=val(s[L-1]); findRight[now]=L-1;
        for(int i=L-2; i>=0; i--){
            now=mp[val(s[i])][now];
            findRight[now]=max(findRight[now],i);
        }
        int now2=now;
        assert(now1==now2);
        int tmp=now; pt[0]=1;
        for(int i=1; i<=min(X,4LL); i++){
            pt[i]=now;
            now=mp[now][tmp];
        }
        now=pt[X%4];
        printf("Case #%d: ",cs);
        if(decodeL[4][decodeR[2][now]]!=3){
            goto failed;
        }
        for(int i=0; i<=min(X,4LL); i++){
            for(int j=0; j<=min(X,4LL); j++){
                if(i+j<X-1){
                    if(findLeft[decodeR[pt[i]][2]]!=INF&&findRight[decodeL[pt[j]][4]]!=-INF){
                        goto ok;
                    }
                }
                else if(i+j==X-1){
                    if(findLeft[decodeR[pt[i]][2]]+1<findRight[decodeL[pt[j]][4]]){
                        goto ok;
                    }
                }
            }
        }
        failed:; puts("NO");
        continue;
        ok:; puts("YES");
    }
    return 0;
}
