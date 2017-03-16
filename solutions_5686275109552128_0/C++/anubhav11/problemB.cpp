#include<bits/stdc++.h>
#define cin file
#define cout file2
using namespace std;

int dp[1010][1010];

main() {

    for (int i=1; i<1010; i++) {
        for (int j=1; j<1010; j++) {
            if (i<=j) dp[i][j] = 0;
            else dp[i][j] = 1 + dp[i-j][j];
        }
    }

    ifstream file("B-small-attempt1.in");
    ofstream file2("B-small-attempt1.out");

    int t;
    cin>>t;

    for (int test=1; test<=t; test++) {

        int arr[1010], d, ans=1000000000;
        cin>>d;
        for (int i=1; i<=d; i++) cin>>arr[i];

        for (int i=1; i<1010; i++) {
            int tmp =0;
            for (int j=1; j<=d; j++) tmp += dp[arr[j]][i];
            ans = min(ans, tmp + i);
        }

        cout<<"Case #"<<test<<": "<<ans<<endl;
    }
}
