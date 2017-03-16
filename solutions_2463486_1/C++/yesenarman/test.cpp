#include <iostream>

using namespace std;

int64_t n;

bool fair(int64_t x) {
    char s[30];
    sprintf(s, "%lld", x);
    for (int l=0, r=strlen(s)-1; l<r; ++l, --r)
        if (s[l]!=s[r]) return false;
    return true;
}

int main() {
    cin >> n;
    cout << n << endl;
    int res=0;
    for (int64_t i=1; i*i<=n; ++i) {
        if (fair(i) && fair(i*i)) {
            //cout << i << " " << i*i << endl;
            cout << i*i << ", ";
            ++res;
        }
    }
    cout << endl;
    cout << res << endl;
    return 0;
}
