#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t,n,x;
    int arr[10000];
    vector<int> res;
    set<int> num;
    cin >> t;
    for(int caso = 1;caso<=t;caso++){
        res.clear();
        num.clear();
        memset(arr, 0, sizeof arr);

        cin >> n;
        for(int i=0;i<2*n-1;i++){
            for(int j=0;j<n;j++){
                cin >> x;
                num.insert(x);
                arr[x]++;
            }
        }
        for(int i:num){
            if(arr[i]%2 == 1) res.push_back(i);
        }
        sort(ALL(res));
        cout << "Case #" << caso << ":";
        for(int i:res){
            cout <<" " << i;
        }
        cout << "\n";
    }
    return 0;
}
