#include <bits/stdc++.h>
using namespace std;

int g[20];
int n;
int v[1005];
int s;
int mx;

void gg(vector<int> zz) {
    int f=1;
    int a[11] = {0};
    a[zz[0]]++;
    a[zz[zz.size()-1]]++;
    for(int i=1 ; i< zz.size()-1 ; i++) {
        a[zz[i]]++;
        if (g[zz[i]]!= zz[i+1] && g[zz[i]]!=zz[i-1]) {
            f = 0;
        }
    }
    if (g[zz[0]]!= zz[zz.size()-1] && g[zz[0]]!=zz[1]) {
        f=0;
    }
    if (g[zz[zz.size()-1]]!= zz[0] && g[zz[zz.size()-1]]!=zz[zz.size()-2]) {
        f=0;
    }
    for(int i=0 ; i< 11 ; i++) {
        if (a[i]>1) {
            f=0;
            break;
        }
    }
    
    if (f) {
        mx = max(mx, (int)zz.size());
    }
    for(int i=1 ; i< n ; i++) {
        if(!v[i]) {
            v[i] = 1;
            zz.push_back(i);
            gg(zz);
            zz.pop_back();
            v[i] = 0;
        }
    }
}

void solve() {
    cin>>n;
    mx = 0;
    for(int i=1 ; i<= n ; i++) {
        int x;
        cin>>x;
        g[i] = x;
    }
    vector<int> b;
    for(int i=1 ; i<= n ; i++) {
        b.emplace_back(i);
        memset(v, 0, sizeof(v));
        gg(b);
        b.pop_back();
    }
    cout<<mx<<endl;
}

int main(int argc, const char **argv) {
    if(argc>=2) {
        freopen(argv[1], "r", stdin);
        freopen(argv[2], "w", stdout);
    }
    
    int T;
    cin>>T;
    for(int t=1 ; t<=T ; t++) {
        printf("Case #%d: ",t);
        fprintf(stderr,"Case #%d: Done\n",t);
        solve();
    }
}
