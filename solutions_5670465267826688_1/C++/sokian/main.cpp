#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef int itn;
typedef pair<int, int> PII;

struct InputData {
    int l;
    long long n;
    string s;
};

struct OutputData {
    bool result;

    void print() {
        if (result) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    }
};


InputData readInputData() {
    InputData ret;
    cin >> ret.l >> ret.n >> ret.s;
    return ret;
}

InputData generateInputData() {
    InputData ret;
    return ret;
}


OutputData solve(InputData);

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(4524234);

    ld cl0 = clock();

    int t;
    cin >> t;
    future<OutputData> fu[t];

    cerr << "Reading input..." << endl;
    for (int i = 0; i < t; ++i) {
        InputData inputData = readInputData();
        fu[i] = async(launch::async, solve, inputData);
    }

    OutputData res[t];
    cerr << "Waiting for threads..." << endl;
    for (int i = 0; i < t; ++i) {
        res[i] = fu[i].get();
    }


    cerr << "Printing results..." << endl;
    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ": ";
        res[i].print();
        cout << endl;
    }


    cerr << setprecision(3) << fixed;
    cerr << "Time elapsed: " << (clock() - cl0) / (CLOCKS_PER_SEC) << " sec." << endl;
    return 0;
}

const
int ids[][4]   = {{0,1,2,3},
                  {1,0,3,2},
                  {2,3,0,1},
                  {3,2,1,0}};
const
int signs[][4] = {{0,0,0,0},
                  {0,1,0,1},
                  {0,1,1,0},
                  {0,0,1,1}};

struct num {
    int id;
    int sign;
    num(int id = 0, int sign = 0) : id(id), sign(sign) {}
    num(const num &r) : id(r.id), sign(r.sign) {}
    num & operator = (const num &r) {
        if (this == &r) return *this;
        id = r.id;
        sign = r.sign;
        return *this;
    }

    num operator * (const num &r) const {
        num ret;
        ret.sign = sign ^ r.sign ^ signs[id][r.id];
        ret.id = ids[id][r.id];
        return ret;
    }

    bool operator == (const num &r) const {
        return sign == r.sign && id == r.id;
    }
    bool operator != (const num &r) const {
        return sign != r.sign || id != r.id;
    }
};

const num I = num(1);
const num J = num(2);
const num K = num(3);

num getNum(char c) {
    switch (c) {
    case 'i':
        return num(1);
    case 'j':
        return num(2);
    case 'k':
        return num(3);
    }
    return num();
}

num getNum(const string &s) {
    num ret = num();
    for (size_t i = 0; i < s.length(); ++i) {
        ret = ret * getNum(s[i]);
    }
    return ret;
}

bool solve(const string &s) {
    num curl = num();
    int l = 0;
    int n = s.length();
    while (l < n && curl != I) {
        curl = curl * getNum(s[l]);
        ++l;
    }
    num curr = num();
    int r = n - 1;
    while (r >= 0 && curr != K) {
        curr = getNum(s[r]) * curr;
        --r;
    }
    if (l > r) {
        return false;
    }
    num curmid = num();
    for (int i = l; i <= r; ++i) {
        curmid = curmid * getNum(s[i]);
    }
    return curmid == J;
}

num getNum(long long n, const string &s) {
    num ret = num();
    num a = getNum(s);
    n %= 4;
    for (int i = 0; i < n; ++i) {
        ret = ret * a;
    }
    return ret;
}

bool solve(long long n, const string &s) {
    if (n <= 8) {
        string t;
        for (int i = 0; i < n; ++i) {
            t += s;
        }
        return solve(t);
    }
    int len = s.length();
    num le = num();
    int l = 0;
    for (l = 0; l < 4 * len; ++l) {
        if (le == I) {
            break;
        }
        le = le * getNum(s[l % len]);
    }
    if (l == 4 * len) {
        return false;
    }
    num ri = num();
    int r = 4 * len - 1;
    for (r = 4 * len - 1; r >= 0; --r) {
        if (ri == K) {
            break;
        }
        ri = getNum(s[r % len]) * ri;
    }
    if (r < 0) {
        return false;
    }
    num addle = num();
    for (;l < 4 * len; ++l) {
        addle = addle * getNum(s[l % len]);
    }
    num addri = num();
    for (; r >= 0; --r) {
        addri = getNum(s[r % len]) * addri;
    }
    num mid = addle * getNum(n - 8, s);
    mid = mid * addri;
    return mid == J;
}

OutputData solve(InputData in) {
    OutputData out;
    out.result = solve(in.n, in.s);
    return out;
}

