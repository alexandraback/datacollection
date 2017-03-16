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
    int n;
    vector<int> a;
};

struct OutputData {
    int result;

    void print() {
        cout << result;
    }
};


InputData readInputData() {
    InputData ret;
    cin >> ret.n;
    ret.a.assign(ret.n, 0);
    for (int i = 0; i < ret.n; ++i) {
        cin >> ret.a[i];
    }
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




OutputData solve(InputData in) {
    OutputData out;

    int ans = INT_MAX;
    for (int i = 1; i <= 1000; ++i) {
        multiset<int, greater<int> > s(in.a.begin(), in.a.end());
        int cnt = 0;
        while (!s.empty() && *s.begin() > i && cnt < 1000) {
            int v = *s.begin();
            s.erase(s.begin());
            s.insert(v - i);
            ++cnt;
        }
        ans = min(ans, i + cnt);
    }
    out.result = ans;
    return out;
}

