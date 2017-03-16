#include <bits/stdc++.h>
#include <gmpxx.h>
using namespace std;

const int MAX = 1e6;
bool compo[MAX];
vector<int> primes;

void init() {
    for (int i = 2; i < MAX; i++) {
        for (int j = i + i; j < MAX; j += i)
            compo[j] = true;
    }
    for (int i = 2; i < MAX; i++)
        if (!compo[i]) {
            primes.push_back(i);
        }
}

int main() {
    init();

    int cases;
    scanf("%d", &cases);
    for (int cs = 1; cs <= cases; cs++) {
        int n, j;
        scanf("%d%d", &n, &j);
        printf("Case #%d:\n", cs);

        string cstr = "1";
        for (int i = 0; i < n - 2; i++)
            cstr += "0";
        cstr += "1";

        mpz_class cand = 0;
        for (int ns = 0; ns < j; ns++) {
            while (true) {
                cand++;
                string tmp = cand.get_str(2);
                assert(tmp.size() <= n - 2);
                cstr.replace(n - tmp.size() - 1, tmp.size(), tmp);

                bool ok = true;
                vector<int> div;
                for (int b = 2; ok && b <= 10; b++) {
                    mpz_class test(cstr, b);
                    for (int i = 0; i < primes.size() && test > primes[i]; i++) {
                        if (test % primes[i] == 0) {
                            div.push_back(primes[i]);
                            break;
                        }
                    }
                    if (div.size() < b - 1)
                        ok = false;
                }
                if (ok) {
                    cout << cstr;
                    for (auto d: div)
                        cout << " " << d;
                    cout << endl;
                    break;
                }
            }
        }
    }
}
