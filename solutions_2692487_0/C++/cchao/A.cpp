#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

long long A, n;
long long arr[110];
long long ans;
long long now, cost;
int solve(int x){
    while(x < n && now > arr[x]){
        now += arr[x++];
    }
    if(x==n){
        ans = min(ans, cost);
        return 1;
    }
    ans = min(ans, cost + (n-x));
    if(now==1) return 0;
    while(now <= arr[x]){
        now += now-1;
        cost++;
    }
    solve(x);
}

int main(){
    int T;
    cin >> T;
    for(int kase = 1; kase <= T; ++kase){
        cin >> A >> n;
        for(int i = 0; i < n; ++i) cin >> arr[i];
        sort(arr, arr+n);
        ans = 10000; now = A; cost = 0;
        solve(0);
        printf("Case #%d: ", kase);
        cout << ans << endl;
    }
    return 0;
}
