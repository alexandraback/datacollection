#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>
#include <string>
#include <random>
#include <chrono>

#include <gmpxx.h>

using namespace std;

void addFactor(vector<int> &primes, int &psqrt) {
    int lookat = primes[primes.size() - 1];
    while (true) {
        lookat += 2;
        if (psqrt * psqrt < lookat)
            ++psqrt;
        for (int j = 0;; ++j) {
            if (lookat % primes[j] == 0)
                break;
            if (primes[j] >= psqrt) {
                primes.push_back(lookat);
                return;
            }
        }
    }
}

int getFactor(mpz_class n, vector<int> &primes) {
    int until = sqrt(n.get_d());
    int i = 0;
    while (primes[i] <= until) {
        if (n % primes[i] == 0)
            return primes[i];
        if (++i >= (int) primes.size())
            break;
    }
    return 0;
}

typedef unsigned long mint;

int main() {
    vector< pair<long long, int> > factors;
    vector<int> primes;
    primes.push_back(2);
    primes.push_back(3);
    int psqrt = 2;
    while (psqrt < 10000)
        addFactor(primes, psqrt);
    cerr << "Got factors." << endl;
    int T, base;
    cin >> T;
    mpz_class n;
    std::mt19937 rnd(std::chrono::system_clock::now().time_since_epoch().count());
    string s;
    vector<int> res;
    unordered_map<mint, vector<int> > found(1000);
    for (int i = 0; i < T;) {
        int N, J;
        cin >> N >> J;
        while (found.size() < J) {
            s = "1";
            while (s.length() < N - 1)
                s += (rnd() & 1 ? "1" : "0");
            s += "1";
            mint current = mpz_class(s, 2).get_ui();
            if (found.find(current) != found.end())
                continue;
            cerr << "A" << endl;
            for (base = 2; base <= 10; ++base) {
                n = mpz_class(s, base);
                if (mpz_probab_prime_p(n.get_mpz_t(), 15))
                    break;
            }
            if (base <= 10)
                continue;
            cerr << "B" << endl;
            res.clear();
            for (base = 2; base <= 10; ++base) {
                n = mpz_class(s, base);
                int f = getFactor(n, primes);
                if (!f)
                    break;
                res.push_back(f);
            }
            if (base <= 10)
                continue;
            found[current] = res;
            cerr << "Found " << found.size() << endl;
        }
        cout << "Case #" << (++i) << ":" << endl;
        for (const pair<mint, vector<int> > &p : found) {
            cout << mpz_class(p.first).get_str(2);
            for (const int &i : p.second)
                cout << " " << i;
            cout << endl;
        }
    }
    return 0;
}
