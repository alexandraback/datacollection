#include <iostream>
#include <cassert>
#include <bitset>
#include <random>
#include <unordered_map>
using namespace std;

const int N = 16;

long long popcount(long long n) {
    return __builtin_popcount(n);
}

long long convert(long long bin, int base) {
    long long result = 0;
    bitset<N> b(bin);
    for (int i = N - 1; i >= 0; --i) {
        result *= base;
        result += b[i];
    }
    return result;
}

unordered_map<long long, vector<long long>> numToDivisors;

long long getRandomCandidate(int n) {
    long long result = 1;
    for (int i = 0; i < n - 2; ++i) {
        result <<= 1;
        result += rand() & 1;
    }
    return (result << 1) + 1;
}

long long maybeFindMinDivisor(long long n) {
    const static int MAGIC = 10000;
    for (int i = 2; i < MAGIC; ++i) {
        if (n % i == 0) {
            return i;
        }
    }
    return 0;
}

int main() {
    int J = 50;
    while (J > 0) {
        long long candidate = getRandomCandidate(N); 
        cerr << bitset<N>(candidate) << endl;
        if (numToDivisors.find(candidate) != numToDivisors.end()) continue;
        vector<long long> divs;
        for (int i = 2; i <= 10; ++i) {
            long long bic = convert(candidate, i);
            long long div = maybeFindMinDivisor(bic);
            if (div == 0) break;
            divs.push_back(div);
        }
        if (divs.size() != 9) continue;

        numToDivisors[candidate] = divs;
        --J;
        cerr << J << endl;
    }
    cout << "Case #1:" << endl;
    for (auto n : numToDivisors) {
        cout << bitset<N>(n.first);
        for (long long d : n.second) {
            cout << " " << d;
        }
        cout << endl;
    }
    return 0;
}
