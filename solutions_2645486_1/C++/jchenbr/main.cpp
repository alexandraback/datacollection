#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int N=10000+5;
LL e, r, n, a[N];

struct node {
    LL val, pos;

    node() {
    }

    node(LL _x, LL _y) {
        val=_x;
        pos=_y;
    }
};
vector<node> g;
vector<node> f;

bool cmp(const node&x, const node &y) {
    if (x.val>y.val) return true;
    if (x.val<y.val) return false;
    return x.pos<y.pos;
}

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int total, tt=0;
    cin>>total;
    while (total--) {
        cin>>e>>r>>n;
        for (LL i=1; i<=n; i++)
            cin>>a[i];
        g.clear();
        for (LL i=1; i<=n; i++)
            g.push_back(node(a[i], i));
        sort(g.begin(), g.end(), cmp);
        LL pre= -1;
        f.clear();
        for (LL i=0; i<g.size(); i++) {
            if (pre== -1) {
                f.push_back(g[i]);
                pre=i;
            } else if (g[i].pos>g[pre].pos) {
                f.push_back(g[i]);
                pre=i;
            }
        }
        LL cur=e, ans=0, pp;
        for (LL i=0; i<f.size(); i++) {
            if (i==0) pp=1;
            else pp=f[i-1].pos+1;
            for (LL p=pp; p<f[i].pos; p++) {
                if (cur+r>e) {
                    ans+=a[p]*(cur+r-e);
                    cur=e;
                } else {
                    cur+=r;
                }
            }
            ans+=cur*f[i].val;
            cur=r;
        }
        if (f.size()>0)
            for (LL p=f[f.size()-1].pos+1; p<=n; p++) {
                if (cur+r>e) {
                    ans+=a[p]*(cur+r-e);
                    cur+=r-e;
                } else {
                    cur+=r;
                }
            }
        cout<<"Case #"<<++tt<<": "<<ans<<endl;
    }
    return 0;
}
