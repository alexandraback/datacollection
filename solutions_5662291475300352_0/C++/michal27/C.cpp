#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <stack>
using namespace std;

#define For(i,n) for(int i=0; i<(n); i++)
#define mp(a,b) make_pair((a),(b))
typedef long long ll;
typedef pair<int,int> pii;

void solve(int p1) {
    int n;
    scanf("%d",&n);
    vector<pair<int,int> > H;
    For(i,n) {
        int d,h,m;
        scanf("%d %d %d",&d,&h,&m);
        For(j,h) H.push_back(mp(d,m+j));
    }
    vector<vector<double> > C;
    C.resize(H.size());
    For(i,H.size()) {
        For(j,4) {
            int vz=360-H[i].first+360*j;
            double v=H[i].second/360.0;
            C[i].push_back(vz/v);
        }
    }
    bool t=false;
    if(C.size()>1) {
        if(C[0][0]>C[1][0]) swap(C[0],C[1]);
        if(C[0][1]+0.000000001<C[1][0]) t=true;
    }
    int res=0; if(t) res++;
    printf("Case #%d: %d\n",p1,res);
}

int main() {
    int t;
    scanf("%d",&t);
    For(i,t) solve(i+1);
}
