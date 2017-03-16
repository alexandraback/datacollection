#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <set>

using namespace std;

string toRString(int k) {
    string s = "";
    while (k > 0) {
        s += ('0' + (k % 10));
        k /= 10;
    }
    return s;
}

int toInt(string s) {
    int k = 0, i;
    for (i = 0; i < s.size(); ++i) {
        k *= 10;
        k += (s[i] - '0');
    }
    return k;
}

int doIt(int k) {
    return toInt(toRString(k));
}

// void slow() {
//     int n;
//     cin >> n;

//     int i = 1, ans = 1, a, b;
//     while (i != n) {
//         a = i + 1;
//         b = toInt(toRString(i));
//         if (b > a && b <= n)
//             i = b;
//         else
//             i = a;
//         ++ans;
//     }

//     cout << ans << "\n";
// }

void slow() {

    long long n;
    cin >> n;

    queue<pair<long long, int>> Q;
    Q.push(make_pair(n, 1));

    set<long long> S;
    S.insert(n);

    pair<long long, int> p;
    long long k, k1, k2;
    int d;

    while(true) {
        p = Q.front();
        Q.pop();
        k = p.first;
        d = p.second;
        if (k == 1) {
            cout << d << "\n";
            return;
        }
        k1 = k - 1;
        k2 = doIt(k);
        if (S.find(k1) == S.end()) {
            S.insert(k1);
            Q.push(make_pair(k1, d + 1));
        }
        if (k % 10 != 0 && S.find(k2) == S.end()) {
            S.insert(k2);
            Q.push(make_pair(k2, d + 1));
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int _T, T;
    scanf("%d", &T);
    for (_T = 1; _T <= T; ++_T) {
        printf("Case #%d: ", _T);
        slow();
    }
    return 0;
}