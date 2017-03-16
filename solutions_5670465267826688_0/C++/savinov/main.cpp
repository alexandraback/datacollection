#include "bits/stdc++.h"

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define in(x) int (x); input((x));
#define x first
#define y second
typedef int itn;

#define next next12345
#define prev prev12345
#define left lefdsf232
#define right rig43783
#define x1 x12345
#define y1 y12345

using namespace std;

template<typename T>
T gcd(T x, T y) {
    while (y > 0) {
        x %= y;
        swap(x, y);
    }
    return x;
}

template<class _T>
inline _T sqr(const _T &x) {
    return x * x;
}

template<class _T>
inline string tostr(const _T &a) {
    ostringstream os("");
    os << a;
    return os.str();
}

random_device device;
mt19937 generator(device());

unsigned int nextRandom() {
    return generator();
}

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const long double PI = 3.1415926535897932384626433832795L;

template<typename T>
inline void input(T &a) {
    static int c;
    a = 0;
    while (!isdigit(c = getchar()) && c != '-') {}
    char neg = 0;
    if (c == '-') {
        neg = 1;
        c = getchar();
    }
    while (isdigit(c)) {
        a = 10 * a + c - '0';
        c = getchar();
    }
    if (neg) a = -a;
}

template<typename T = int>
inline T nxt() {
    T res;
    input(res);
    return res;
}

inline string next() {
    static int c;
    string res;
    while (isspace(c = getchar())) {}
    while (!isspace(c)) {
        res = res + (char)c;
        c = getchar();
    }
    return res;
}


long long pw(long long a, long long n, long long mod) {
    long long res = 1;
    while (n) {
        if (n & 1ll) {
            res = res * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

void solve4() {
    int t;
    cin >> t;
    int c = 0;
    while (t--) {
        int d;
        cin >> d;

        vector <int> p(d);

        for (int i = 0; i < d; ++i) {
            cin >> p[i];
        }

        cout << "Case #" << ++c << ": ";

        int l = 0, r = *max_element(all(p));

        while (l < r) {
            int mid = (l + r) / 2;

            priority_queue<int> q(all(p));

            char ok = false;

            for (int pause = 0; pause < mid; ++pause) {
                if (q.top() + pause <= mid) {
                    ok = true;
                    break;
                }
                int x = q.top();
                q.pop();
                q.push(x / 2);
                q.push((x + 1) / 2);
            }

            if (ok) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        cout << l << "\n";
    }
}

struct data {
    int x, y, z, w;

    friend data operator*(const data & q1, const data & q2) {
        data res;
        res.x =  q1.x * q2.w + q1.y * q2.z - q1.z * q2.y + q1.w * q2.x;
        res.y = -q1.x * q2.z + q1.y * q2.w + q1.z * q2.x + q1.w * q2.y;
        res.z =  q1.x * q2.y - q1.y * q2.x + q1.z * q2.w + q1.w * q2.z;
        res.w = -q1.x * q2.x - q1.y * q2.y - q1.z * q2.z + q1.w * q2.w;
        return res;
    }

    bool operator==(const data & r) const {
        return x == r.x && y == r.y && z == r.z && w == r.w;
    }

};



void solve() {
    int t;
    cin >> t;
    int c = 0;

    data I = data{1, 0, 0, 0};
    data J = data{0, 1, 0, 0};
    data K = data{0, 0, 1, 0};
    data E = data{0, 0, 0, 1};


    while (t--) {

        long long l;
        cin >> l;

        long long x;
        cin >> x;


        string s;
        cin >> s;

        data mul[l * x + 1];

        int can[l * x + 1];

        can[0] = 0;

        data cur = E;

        data need = I * J * K;

        for (int i = 0; i < l * x; ++i) {
            data X;
            if (s[i % l] == 'i') {
                X = I;
            }
            if (s[i % l] == 'j') {
                X = J;
            }
            if (s[i % l] == 'k') {
                X = K;
            }
            cur = cur * X;
            can[i + 1] = can[i] + (cur == I);
        }

        char ok = false;
        if (need == cur) {
            cur = E;
            for (int i = l * x - 1; i >= 0; --i) {
                data X;
                if (s[i % l] == 'i') {
                    X = I;
                }
                if (s[i % l] == 'j') {
                    X = J;
                }
                if (s[i % l] == 'k') {
                    X = K;
                }
                cur = X * cur;
                if (can[i] && cur == K) {
                    ok = true;
                    break;
                }
            }
        }

        //cout << need.x << " " << need.y << " " << need.z << " " << need.w << "\n";
        //cout << mul[l * x].x << " " << mul[l * x].y << " " << mul[l * x].z << " " << mul[l * x].w << "\n";

        cout << "Case #" << ++c << ": ";
        if (ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int rec(vector <int> x) {
    if (*max_element(all(x)) == 0) {
        return 0;
    }
}

int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define fname "a"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
    solve();
    //cout << bestScore << "\n";
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}  