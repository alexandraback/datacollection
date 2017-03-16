#include<cstdio>
#include<cassert>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<map>
#include<set>

using namespace std;

int main(){
    int t; cin >> t;
    //freopen("A-small.in", "r", stdin);
    freopen("A-small.out", "w", stdout);
    for(int T = 1; T <= t; T++){
        int a, n; cin >> a >> n;
        int arr[n+1];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        sort(arr, arr+n);
        long long ans = 10000000;
        for(int i = 0; i <= n; i++){
            long long cur = a;
            long long cnt = 0;
            for(int j = 0; j < i; j++){
                if(cur == 1){
                    cnt+= n;
                    break;
                }
                while(cur <= arr[j]){
                    cur += (cur-1);
                    cnt++;
                }
                cur += arr[j];
            }

            cnt += (n-i);

            ans = min(cnt, ans);
        }
        cout << "Case #" << T << ": " << ans << endl;
    }
}
