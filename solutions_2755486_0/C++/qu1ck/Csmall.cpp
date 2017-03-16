#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;


struct attack{
    int w,e,h;
    attack(int _w, int _e,int _h):w(_w),e(_e),h(_h) {}
    bool operator<(const attack &a)const{
        return (w<a.w) || (w==a.w && e<a.e) || (w==a.w && e==a.e && h<a.h);
    }
};

vector<pair<int, attack> > attacks;

int wall[1000];
int newh[1000];
int sh=500;

int process(attack &a){
    int ret=0;
    for(int i=sh+2*a.w;i<=sh+2*a.e;i++){
        if(wall[i]<a.h){
            ret=1;
            newh[i]=max(newh[i],a.h);
        }
    }
    return ret;
}

void rebuild(){
    for(int i=0;i<1000;i++)
        wall[i]=newh[i];
}

int main() {
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    int ncase;
    scanf("%d",&ncase);
    for(int C=1;C<=ncase;C++){
        printf("Case #%d: ",C);
        int N;
        scanf("%d",&N);
        int d,n,w,e,s,dd,dp,ds;
        attacks.clear();
        for(int i=0;i<N;i++){
            scanf("%d%d%d%d%d%d%d%d",&d,&n,&w,&e,&s,&dd,&dp,&ds);
            for(int j=0;j<n;j++){
                attacks.push_back(make_pair(d,attack(w,e,s)));
                w+=dp;
                e+=dp;
                d+=dd;
                s+=ds;
            }
        }
        sort(attacks.begin(),attacks.end());
        memset(wall,0,sizeof(wall));
        memset(newh,0,sizeof(newh));
        int ans=0;
        for(int i=0;i<attacks.size();i++){
            if(i && attacks[i].first!=attacks[i-1].first)rebuild();
            int succ=process(attacks[i].second);
            ans+=succ;
            //printf("%d: %d %d %d: %d: %d\n",attacks[i].first,attacks[i].second.w,attacks[i].second.e,attacks[i].second.h,succ,ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}