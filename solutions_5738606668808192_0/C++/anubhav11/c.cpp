#include<bits/stdc++.h>
#define int long long
using namespace std;

void printbinary(int x) {
    if (x/2 != 0) printbinary(x/2);
    cout<<x%2;
}

main() {

    int t, n, k;
    cin>>t;
    cin>>n>>k;
    cout<<"Case #1: "<<endl;
    int num = (1LL<<(n-1)) + (1LL<<(n-2)) + (1LL<<1LL) + 1LL;

    for (int i=0; i<k; i++) {
        int tmp = num;
        for (int j=0; j<15; j++) {
            if ((1<<j)&i) tmp += (1<<(2*j+2)) + (1<<(2*j+3));
        }
        printbinary(tmp);
        for (int j=2; j<=10; j++) cout<<" "<<j+1;
        cout<<endl;
    }
}
