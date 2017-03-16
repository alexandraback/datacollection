#include <iostream>
#include <algorithm>
using namespace std;
int motes[105];
int main(){
    int t;
    cin >> t;
    for (int kk = 1; kk <= t; ++kk){
        int a, n;
        cin >> a >> n;
        for (int i = 0; i < n; ++i){
            cin >> motes[i];
        }
        sort(motes, motes+n);
        int ans = n, count = 0;
        for (int i = 0; i < n; ++i){
            while (count<=ans && motes[i]>=a){
                a = a * 2 - 1;
                ++count;
            }
            if (motes[i]<a){
                a+=motes[i];
                if (count+n-i-1 < ans){
                    ans = count+n-i-1;
                }
            }
        }
        cout << "Case #" << kk << ": " << ans << endl;
    }
}
