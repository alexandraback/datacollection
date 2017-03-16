#include <bits/stdc++.h>
using namespace std;

const int MAGIC = 13;

typedef long long ll;
typedef vector<int> poly;

int T;
int N, J;

int proofLength;
int diviLength;
int total;

set<poly> res;
map<poly, vector<ll>> proofsMap;
poly proof, divi;

poly multiply(const poly& a, const poly& b) {
    poly c(N);
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            c[i+j] += a[i] * b[j];
        }
    }
    return c;
}

bool is_binary(const poly& p) {
    for (int c : p) {
        if (c != 0 && c != 1) {
            return false;
        }
    }
    return true;
}

void print_solutions() {
    for (const poly& p : res) {
        for (int i = N-1; i >= 0; i--) {
            cout << p[i];
        }
        vector<ll> proofNums = proofsMap[p];
        for (ll proofNum : proofNums) {
            cout << " " << proofNum;
        }
        cout << endl;
    }
}

void check_candidate() {
    poly divii = divi;
    divii[diviLength-1] = 1;
    poly candidate = multiply(proof, divii);

    if (candidate.back() == 1 && candidate[0] == 1 && is_binary(candidate)) {
        if (res.insert(candidate).second) {
            vector<ll> proofNums;
            for (ll base = 2; base <= 10; base++) {
                ll proofNum = 0;
                for (int i = N-1; i >= 0; i--) {
                    proofNum = proofNum * base + proof[i];
                }
                proofNums.push_back(proofNum);
            }
            proofsMap[candidate] = proofNums;
        }
        if (res.size() == J) {
            print_solutions();
            exit(0);
        }
    }
}

void gen(int k) {
    check_candidate();
    if (k == MAGIC || k == diviLength) {
        return;
    }

    for (int c = -1; c <= 1; c++) {
        divi[k] = c;
        gen(k+1);
        divi[k] = 0;
    }
}

int main() {
    cin >> T;
    cin >> N >> J;
    cout << "Case #1:" << endl;

    for (int mask = 2;; mask++) {
        proof.clear();
        proofLength = 0;
        for (int i = 0; i < N; i++) {
            if (mask & (1<<i)) {
                proof.push_back(1);
                proofLength = i+1;
            } else {
                proof.push_back(0);
            }
        }
        if (proofLength == N) {
            break;
        }
        diviLength = N - proofLength + 1;
        divi.resize(diviLength);
        gen(0);
    }
}
