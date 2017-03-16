#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int f(int n){
    vector<int> a(10);
    int cnt = 0, cur = n;
    for(int i = 1; ; i++){
        int m = cur;
        while(m > 0){
            if(a[m % 10] == 0){
                cnt++;
                if(cnt == 10) return cur;
                a[m % 10] = 1;
            }
            m /= 10;
        }
        cur += n;
    }
}

int main() {
    int T, n; cin >> T;
    for(int i = 1; i <= T; i++){
        cin >> n;
        if(n == 0) cout << "Case #" << i << ": INSOMNIA" << endl;
        else cout << "Case #" << i << ": " << f(n) << endl;
    }
    return 0;
}

