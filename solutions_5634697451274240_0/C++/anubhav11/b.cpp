#include<bits/stdc++.h>
#define int long long
using namespace std;

char arr[110];

main() {

    int t;
    cin>>t;
    for (int test = 1; test<=t; test++) {
        cin>>arr;
        cout<<"Case #"<<test<<": ";
        int n = strlen(arr);

        int ans = 0;
        for (int i=1; i<n; i++) {
            if (i==n-1 && arr[i] == '-') ans++;
            if (arr[i] != arr[i-1]) ans++;
        }
        if (n==1 && arr[0] == '-') ans++;
        cout<<ans<<endl;
    }
}
