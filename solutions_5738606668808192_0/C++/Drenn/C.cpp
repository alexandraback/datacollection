#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <limits>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <unordered_set>

#define all(c) (c).begin(),(c).end()

using namespace std;

typedef long long llong;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

int caseNum=1;
ifstream fin("C.in");
ofstream fout("C.out");

#define gout fout << "Case #" << caseNum++ << ": ", fout

llong MAX_PRIMES = 4294967296;

void genPrimes() {
    vector<bool> primeList(MAX_PRIMES, true);

    ofstream out("primes", ios::binary);
    out.put(2);
    out.put(0);
    out.put(0);
    out.put(0);

    for (llong i=3; i<MAX_PRIMES; i+=2) {
        if (primeList[i]) {
            out.write((char*)&i, 4);
            llong mult = i*2;
            for (llong j=3; mult<MAX_PRIMES; j+=2)  {
                primeList[mult] = false;
                mult = i*j;
            }
        }
    }

    out.close();
}

vector<bool> loadPrimes() {
    ifstream in("primes", ios::binary);

    vector<bool> primes(MAX_PRIMES, false);

    while (!in.eof()) {
        llong i = 0;
        in.read((char*)&i, 4);
        primes[i] = true;
    }

    in.close();

    return primes;
}

llong toBase(llong n, int b) {
    llong ret = 0;
    llong mult = 1;
    while (n != 0) {
        int digit = n%2;
        n /= 2;
        ret += digit*mult;
        mult *= b;
    }

    return ret;
}

string toBin(int n) {
    string s;

    while (n != 0) {
        s += to_string(n%2);
        n/=2;
    }

    reverse(all(s));
    return s;
}

vector<bool> primes;

bool checkPrime(llong n) {
    if (n >= MAX_PRIMES) {
        if ((n&1) == 0)
            return false;
        for (llong i=3; i<=sqrt(n); i++) {
            if (n%i == 0)
                return false;
        }
        return true;
    }
    return primes[n];
}

int main (int argc, char* argv[]) {
    int T;
    fin >> T;

    primes = loadPrimes();

    while (T--) {
        int N,J;
        fin >> N >> J;

        cout << "Begin\n";

        llong start = pow(2,N-1);

        int count=0;

        gout << "\n";
        for (llong n=start+1; count<J; n+=2) {
            bool good=true;
            for (int b=2; b<=10; b++) {
                llong num = toBase(n, b);
                if (checkPrime(num)) {
                    good = false;
                    break;
                }
            }

            if (good) {
                count++;
                fout << toBin(n);
                for (int b=2; b<=10; b++) {
                    llong val = toBase(n, b);
                    for (int i=2;; i++) {
                        if (val%i == 0) {
                            fout << ' ' << i;
                            break;
                        }
                    }
                }
                fout << '\n';
                cout << n << '\n';
            }
        }
    }

    fin.close();
    fout.close();
    return 0;
}
