#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

void main2(int p) {
    int n, x;

    cin >> n;

    unordered_map<int, int> mp;

    for (int i = 1; i < 2 * n; ++i) {
        for (int j = 0 ; j < n; ++j) {
            cin >> x;
            mp[x] = (mp.find(x) != mp.end() ? mp[x] : 0) + 1;
        }
    }

    int arr[n] = {0};
    int i = 0;
    for (unordered_map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
        // cout << it->first << ' ' << it->second << '\n';
        if (it->second % 2 == 1)
            arr[i++] = it->first;
    }
    
    sort(arr, arr + n);

    for (int i = 0; i < n; ++i)
        cout << ' ' << arr[i];
    cout << '\n';
}
