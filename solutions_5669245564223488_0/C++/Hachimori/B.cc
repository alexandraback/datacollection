#include<iostream>
#include<algorithm>
using namespace std;
const int BUF = 15;

int n;
string s[BUF];

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
}

void work(int cases) {
    int order[BUF];
    for (int i = 0; i < n; ++i) order[i] = i;

    int ans = 0;

    do {
        string tot = "";
        for (int i = 0; i < n; ++i)
            tot += s[order[i]];

        bool used[26] = {};

        bool valid = true;
        for (int i = 0; i < tot.size(); ++i) {
            if (used[tot[i] - 'a']) {
                valid = false;
                break;
            }
            int nexi = i;
            while (nexi < tot.size() && tot[nexi] == tot[i]) nexi++;
            used[tot[i] - 'a'] = true;
            i = nexi - 1;
        }

        ans += valid;

    } while(next_permutation(order, order + n));

    cout << "Case #" << cases << ": " << ans << endl;
}


int main() {
    int cases;
    cin >> cases;
    
    for (int i = 0; i < cases; ++i) {
        read();
        work(i + 1);
    }
    return 0;
}
