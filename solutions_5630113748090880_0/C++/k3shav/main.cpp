#include <bits/stdc++.h>
using namespace std;

int a[6000];

void solve() {
    int n;
    cin>>n;
    memset(a, 0, sizeof(a));
    int x;
    for(int i=0 ; i< 2*n-1 ; i++) {
        for(int j=0 ; j< n ; j++) {
            scanf("%d",&x);
            a[x]++;
    //        b[i].push_back(x);
        }
    }
    
    for(int i=1 ; i< 2501 ; i++) {
        if(a[i]%2) {
            cout<<i<< " ";
        }
    }
    cout<<endl;
    
    
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
        //fprintf(stderr,"Case #%d: Done\n",t);
        solve();
    }
}
