#include <bits/stdc++.h>

using namespace std;

const int PRIMES_SZ = 1000;
const int K = 11;

struct CoinJam {
  string s;
  int divisors[K];

  string string_representation() const {
    string result = s;
    for (int b = 2; b < K; b++) {
      result += ' ';
      result += to_string(divisors[b]);
    }

    return result;
  }

  bool operator<(const CoinJam &another) const {
    return s < another.s;
  }
};

bool is_prime(int x) {
  for (int d = 2; d * d <= x; d++) {
    if (x % d == 0) {
      return false;
    }
  }

  return true;
}

vector<int> primes;

void set_up() {
  srand(2318);

  for (int x = 2; primes.size() < PRIMES_SZ; x++) {
    if (is_prime(x)) {
      primes.push_back(x);
    }
  }
}

string generate_coin_jam(int n) {
  string s = "";
  for (int i = 0; i < n - 2; i++) {
    s += '0' + rand() % 2;
  }

  return "1" + s + "1";
}

int get_remainder(const string &s, int b, int m) {
  int result = 0;
  for (int i = 0; i < s.size(); i++) {
    result = (result * b + s[i] - '0') % m;
  }

  return result;
}

int get_divisor(const string &s, int b) {
  for (int p : primes) {
    if (get_remainder(s, b, p) == 0) {
      return p;
    }
  }

  return -1;
}

vector<CoinJam> produce_coin_jams(int n, int j) {
  set<string> ss;
  vector<CoinJam> result;

  while (result.size() < j) {
    string s = generate_coin_jam(n);
    if (ss.find(s) != ss.end()) {
      continue;
    }

    CoinJam coin_jam;
    coin_jam.s = s;

    bool flag = true;
    for (int b = 2; b < K; b++) {
      coin_jam.divisors[b] = get_divisor(s, b);
      if (coin_jam.divisors[b] == -1) {
        flag = false;
        break;
      }
    }

    if (!flag) {
      continue;
    }

    ss.insert(s);
    result.push_back(coin_jam);
  }

  return result;
}

void solve(int case_id) {
  int n, j; cin >> n >> j;

  vector<CoinJam> coin_jams = produce_coin_jams(n, j);

  cout << "Case #" << case_id << ":\n";
  for (const CoinJam &coin_jam : coin_jams) {
    cout << coin_jam.string_representation() << "\n";
  }
}

int main() {
  set_up();

  int cases; cin >> cases;

  for (int i = 1; i <= cases; i++) {
    solve(i);
  }

  return 0;
}