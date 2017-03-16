#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define x first
#define y second
#define in(n) int (n) = nxt()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef int itn;
typedef pair<int, int> PII;

int nxt() {
    int res;
    scanf("%d", &res);
    return res;
}

struct InputData {
    int x, n, m;
};

struct OutputData {
    bool result;

    void print() {
        if (result) {
            cout << "GABRIEL";
        } else {
            cout << "RICHARD";
        }
    }
};


InputData readInputData() {
    InputData ret;
    cin >> ret.x >> ret.n >> ret.m;
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

bool solve(int x, int n, int m) {
    if (n > m) {
        swap(n, m);
    }
    if (x > 6) {
        return false;
    }
    if (n * m % x != 0) {
        return false;
    }
    if (n > x + 1) {
        return true;
    }
    if (m < x) {
        return false;
    }
    if (x <= 2) {
        return true;
    }
    if (x == 3) {
        if (n == 1) {
            return false;
        }
        return true;
    }
    if (x == 4) {
        if (n <= 2) {
            return false;
        }
        return true;
    }
    if (x == 5) {
        if (n <= 2) {
            return false;
        }
        if (n == 3 && m == 5) {
            return false;
        }
        return true;
    }
    if (x == 6) {
        if (n <= 3) {
            return false;
        }
        return true;
    }
    return true;
}


OutputData solve(InputData in) {
    OutputData out;
    out.result = solve(in.x, in.n, in.m);
    return out;
}

