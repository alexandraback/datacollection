#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
double a[1005], b[1005];
int  main() {

    freopen("D-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;  cin>>T;
    for(int cas=1; cas<=T; cas++) {
        int n; cin>>n;
        for(int i=0; i<n; ++i) cin>>a[i];
        for(int i=0; i<n; ++i) cin>>b[i];
        int Min = 0, Max = 0;
        sort(a, a+n);
        sort(b, b+n);
        for(int i=0, j=0; i<n; ++i, ++j) {
            while(j<n&&a[j]<=b[i]) ++j;
            if(j == n) break;
            Max++;
        }
        for(int i=n-1, j=n-1; i>=0; --i, --j) {
            while(j>=0&&a[j]>=b[i]) --j;
            if( j<0 ) break;
            Min++;
        }
        cout<<"Case #"<<cas<<": "<<Max<<' '<<n-Min<<endl;
    }
    return 0;
}
