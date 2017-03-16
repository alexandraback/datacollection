#include <iostream>
#include <string>
#include <map>
using namespace std;

int n, arr[500], t;

void print_subset(int a) {
    bool f = true;
    for(int i = 0; i < n; i ++) {
        if((1 << i) & a) {
            if(!f) cout << " ";
            cout << arr[i];
            f = false;
        }
    }
    cout << endl;
}

int main() {
    cin >> t;
    for(int I = 1; I <= t; I ++) {
        cin >> n;
        for(int i = 0; i < n; i ++) {
            cin >> arr[i];
        }
        map<int, int> mp;
        int a = -1, b  = -1;
        for(int i = 0; i < (1 << n); i ++) {
            int sum = 0;
            for(int  j = 0; j < n; j ++) {
                if(i & (1 << j)) {
                    sum += arr[j];
                }
            }
            if(mp.count(sum)) {
                a = mp[sum];
                b = i;
                break;
            }
            mp[sum] = i;
        }
        cout << "Case #" << I << ":" << endl;
        if(a == -1) {
            cout << "Impossible" << endl;
        } else {
            print_subset(a);
            print_subset(b);
        }
    }
    return 0;
}