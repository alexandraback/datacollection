#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

void solve() 
{
    int a[124][124];
    int c[4096];
    int n;

    for(int i =0; i<124; i++) {
        for(int j =0; j<124; j++) {
            a[i][j] = 0;
        }
    }
    for(int i =0; i<4096; i++) {
        c[i] = 0;
    }

    cin >> n;
    for(int i =0; i<2*n-1; i++) {
        for(int j=0; j<n; j++) {
            cin >> a[i][j];
            c[a[i][j]]++;
        }
    }
    vector<int> ans;
    for(int i=0; i<2*n-1; i++) {
        for(int j=0; j<n; j++) {
            if(c[a[i][j]] % 2) {
                ans.push_back(a[i][j]);
            }
        }
    }
    sort(ans.begin(), ans.end());
    int last_x = -1;
    for(auto x : ans) {
        if(x != last_x) {
            cout << " " << x;
        }
        last_x = x;
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cout << "Case #" << i << ":";
        solve();
        cout << endl;
    }
    return 0;
}
