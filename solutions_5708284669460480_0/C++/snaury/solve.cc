#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

template<class T>
inline T read() {
    T value;
    std::cin >> value;
    return value;
}

int repeatFactor(const std::string& L) {
    for (int i = 1; i < L.size(); ++i) {
        auto a = L.substr(i);
        auto b = L.substr(0, a.size());
        if (a == b)
            return i;
    }
    return L.size();
}

double solve(const std::string& K, const std::string& L, int S) {
    // probabily for producing each letter in K
    std::unordered_map<char, double> P;
    for (char k : K) {
        P[k] += 1.0;
    }
    for (auto& kv : P) {
        kv.second /= K.size();
    }
    // probability to see L letters
    double Lp = 1.0;
    std::vector<double> LLp;
    for (char l : L) {
        LLp.push_back(Lp);
        auto it = P.find(l);
        if (it == P.end())
            return 0.0; // don't bother with the impossible
        Lp *= it->second;
    }
    LLp.push_back(Lp);
    int R = repeatFactor(L); // when L starts to repeat itself
    int bananas = 0; // worst case scenario of required bananas
    for (int i = 0; (i + L.size()) <= S; i += R) {
        ++bananas;
    }
    // probability of requiring a banana starting at a position
    std::vector<double> Sp(S + 1, 0.0);
    for (int i = S - L.size(); i >= 0; --i) {
        double p = 0.0; // maximum probability of requiring a banana at this position
        for (int j = i + R; j <= i + L.size(); ++j) {
            double pp = LLp[j - i] + Sp[j];
            if (p < pp)
                p = pp;
        }
        Sp[i] = p;
#if 0
        int best = S; // position where the best number of bananas lie
        for (int j = i + R; j < S; ++j) {
            if (p < Sp[j]) {
                p = Sp[j];
                best = j;
            }
        }
        int t = best - i;
        if (t < L.size())
            Sp[i] = LLp[t] + p;
        else
            Sp[i] = Lp + p;
#endif

    }
    fprintf(stderr, "%d bananas: %f\n", bananas, Sp[0]);
    return bananas - Sp[0];
}

int main() {
    int T = read<int>();
    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        int Kn = read<int>();
        int Ln = read<int>();
        int S = read<int>();
        std::string K = read<std::string>();
        std::string L = read<std::string>();
        printf("Case #%d: %f\n", caseNum, solve(K, L, S));
    }
    return 0;
}
