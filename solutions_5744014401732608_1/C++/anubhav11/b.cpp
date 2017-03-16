#include<bits/stdc++.h>
#define ii pair<int,int>
#define int long long
using namespace std;

int arr[55][55];
int powers[55];


main() {

    powers[0] = 1;
    for (int t=1; t<55; t++) powers[t] = powers[t-1] * 2;

    int te;
    cin>>te;
    for (int t=1; t<=te; t++) {

        for (int i=1; i<55; i++) {
            for (int j=1; j<=i; j++) arr[i][j] = 0;
            for (int j=i+1; j<55; j++) arr[i][j] = 1;
        }

        int n, m;
        cin>>n>>m;
        int x = powers[n-2];
        int tmp = x - m;
        int cnt = n-1;

        cout<<"Case #"<<t<<": ";

        if (x < m) {
            cout<<"IMPOSSIBLE"<<endl;
            goto last;
        }
        else cout<<"POSSIBLE"<<endl;

        while (tmp > 0) {
            if (tmp % 2 == 1) {
                arr[1][cnt] = 0;
            }
            tmp/=2;
            cnt--;
        }

        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) cout<<arr[i][j];
            cout<<endl;
        }

        last:;
    }
}
