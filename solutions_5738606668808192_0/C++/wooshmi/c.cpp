#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long get_fact(long long x) {
    for (long long i = 2; i * i <= x; ++i)
        if (x % i == 0)
            return i;
    return 1;
}

long long compute(long long x, long long base) {
    long long aux = 0, mult = 1;
    while (x) {
        aux += mult * (x & 1);
        x >>= 1;
        mult *= base;
    }
    return aux;
}

int main() {
    ifstream in;
    in.open("dataset.in");
    ofstream out;
    out.open("dataset.out");

    int T;
    in >> T;

    for (int i = 0; i < T; ++i) {
        int N, J;
        in >> N >> J;
        vector < pair < long long, vector < long long > > > ans;
        for (int j = 0; j < 1 << (N - 2); ++j) {
            long long new_j = (j << 1) + 1 + (1 << (N - 1));
            vector < long long > v;
            bool ok = true;
            for (int k = 2; k <= 10; ++k) {
                long long aux = get_fact(compute(new_j, k));
                if (aux != 1)
                    v.push_back(aux);
                else
                    ok = false;
            }
            if (ok) {
                ans.push_back(make_pair(new_j, v));
                if (ans.size() >= J)
                    break;
            }
        }
        out << "Case #" << (i + 1) << ":\n";
        for (int j = 0; j < J; ++j) {
            vector < int > v;
            long long aux = ans[j].first;
            while (aux) {
                v.push_back(aux & 1);
                aux >>= 1;
            }
            for (int k = v.size() - 1; k >= 0; --k)
                out << v[k];
            out << " ";
            for (int k = 0; k < 9; ++k)
                out << ans[j].second[k] << ((k == 8) ? "\n" : " ");    
        }
    }
    
    in.close();
    out.close();
    return 0;
}
