#include <iostream>
#include <vector>
using namespace std;

char digit[64];
vector<int> vec;
vector<int> prime;

int N, J;
int cc;

bool isPrime(long long x) {
    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void init() {
    for (int i = 2; i < 65536; i++) {
        if (isPrime(i))
            prime.push_back(i);
    }
}

int getAnyFac(int base) {
    long long x = 0;
    for (int i = 0; i < N; i++) {
        x = x * base + (digit[i] - '0');
    }
    for (const auto &e : prime) {
        if (e >= x) break;
        if (x % e == 0) return e;
    }
    return -1;
}


void dfs(int pos) {
    if (cc >= J) return;
    if (pos == N - 1) {
        digit[0] = digit[N - 1] = '1';
        vec.clear();
        for (int i = 2; i <= 10; i++) {
            int ret = getAnyFac(i);
            if (ret == -1) break;
            vec.push_back(ret);
        }
        if (vec.size() == 9) {
            cc++;
            digit[N] = 0;
            cout << digit;
            for (const auto &e : vec) {
                cout << " " << e;
            }
            cout << endl;
        }
        return;
    }
    digit[pos] = '0';
    dfs(pos + 1);
    if (cc >= J) return;
    digit[pos] = '1';
    dfs(pos + 1);
}

int main() {
    ios::sync_with_stdio(false);
    init();
    int T, Case = 1;
    cin >> T;
    while (T--) {
        cin >> N >> J;
        cout << "Case #" << Case++ << ":" << endl;
        cc = 0;
        dfs(1);
    }
    return 0;
}
