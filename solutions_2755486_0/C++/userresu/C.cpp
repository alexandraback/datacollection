#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct attack { 
    int d,w,e,s;
    bool operator<(const attack &b) const {
        return d<b.d;
    }
};

vector<attack> v;
int h[810],hn[810];
int main () {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for (int z=1;z<=T;++z) {
    v.clear();
    int N;
    scanf("%d",&N);
    for (int i=0;i<810;++i) h[i]=hn[i]=0;
    int d,n;
    int w,e;
    int s;
    int dd,dp,ds;
    for (int i=1;i<=N;++i) {
        scanf("%d %d %d %d %d %d %d %d",&d,&n,&w,&e,&s,&dd,&dp,&ds);
        w+=200;
        w<<=1;
        e+=200;
        e<<=1;
        dp<<=1;
        for (int j=0;j<n;++j) v.push_back((attack){d+j*dd,w+j*dp,e+j*dp,s+j*ds});
    }
    sort(v.begin(),v.end());
    int tot=0;
    for (int i=0;i<v.size();++i) {
        attack a = v[i];
        int succ=0;
        for (int j=a.w;j<=a.e;++j) if (h[j]<a.s) {
            succ=1;
            hn[j]=max(hn[j],a.s);
        }
        tot+=succ;
        if (i+1<v.size() && v[i+1].d!=v[i].d) {
            for (int j=0;j<810;++j) h[j]=hn[j];
        }
    }
    printf("Case #%d: %d\n",z,tot);}
    return 0;
}
