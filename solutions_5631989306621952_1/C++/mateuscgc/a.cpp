#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        string st;
        cin >> st;
        int len = st.size();
        char ans[len*2];
        int ini = len;
        int end = len;

        ans[ini] = st[0];
        for(int j = 1; j < len; j++) {
            if(st[j] >= ans[ini])
                ans[--ini] = st[j];
            else
                ans[++end] = st[j];
        }

        cout << "Case #" << i << ": ";
        for(int j = ini; j <= end; j++)
            cout << ans[j];
        cout << endl;
    }

    return 0;
}
