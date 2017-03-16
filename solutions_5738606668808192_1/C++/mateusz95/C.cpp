#include <bits/stdc++.h>

using namespace std;

const int MAX_PRIME = 1000007;

bool prime[MAX_PRIME + 5];
vector<int> primes;
vector<string> ans;

string randomBits(int l) {
    string ret = "";
    ret += 1;
    for (int i = 2; i < l; i++) {
        ret += (char)(rand() % 2);
    }
    ret += 1;
    return ret;
}

long long stringToInt(string &x, int base) {
    long long ret = 0;
    for (int i = 0; i < x.size(); i++) {
        ret = base * ret + x[i];
    }
    return ret;
}

bool divisible(int p, string &number, int base) {
    int val = 0;
    for (int i = 0; i < number.size(); i++) {
        val = (val * base + number[i]) % p;
    }
    return val == 0;
}

bool good(string &number, int pos) {
    for (int i = 0; i < pos - 1; i++) {
        if (ans[i] == number) {
            return false;
        }
    }

    for (int base = 2; base <= 10; base++) {
        bool isPrime = true;
        for (int j = 0; j < primes.size(); j++) {
            if (divisible(primes[j], number, base)) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            return false;
        }
    }
    return true;
}

vector<int> getDivisors(string &number) {
    vector<int> ret;
    for (int base = 2; base <= 10; base++) {
        for (int j = 0; j < primes.size(); j++) {
            if (divisible(primes[j], number, base)) {
                ret.push_back(primes[j]);
                break;
            }
        }
    }
    return ret;
}

void test() {
    ans.clear();
    int n = 32;
    int k = 500;
    string number;
    for (int i = 1; i <= k; i++) {
        do {
           number = randomBits(n);
        } while (good(number, i) == false);
        ans.push_back(number);
        vector<int> divisors = getDivisors(number);

        for (int i = 0; i < number.size(); i++) {
            number[i] += 48;
        }
        printf("%s ", number.c_str());

        assert(divisors.size() == 9);
        for (int j = 0; j < divisors.size(); j++) {
            printf("%d ", divisors[j]);
        }
        printf("\n");
    }
}

void generatePrimes() {
    for (int i = 2; i <= MAX_PRIME; i++) {
        if (prime[i] == false) {
            primes.push_back(i);
            for (int j = 2 * i; j <= MAX_PRIME; j += i) {
                prime[j] = true;
            }
        }
    }
}

int main() {
    srand(time(0));
    generatePrimes();
    int t;
    scanf("%d", &t);
    for (int tests = 1; tests <= t; tests++) {
        printf("Case #%d:\n", tests);
        test();
    }
    return 0;
}