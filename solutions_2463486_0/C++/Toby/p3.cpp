#include <iostream>
#include <cstring>

using namespace std;

#define LEN_MAX 120

class Num {
public:
    int v[LEN_MAX];
    int len;

    Num() {
        memset(v, 0, sizeof(v));
        len = 0;
    }

    Num(const string &value) {
        Set(value);
    }

    void Set(const string &value) {
        memset(v, 0, sizeof(v));
        len = value.size();
        for (int i = 0; i < len; i++) {
            v[i] = value[len - i - 1] - '0';
        }
    }

    Num& operator+=(int x) {
        v[0] += x;
        Normalize();
        return *this;
    }

    bool operator>(const Num &other) const {
        if (len > other.len)
            return true;
        if (len < other.len)
            return false;
        for (int i = len - 1; i >= 0; i--) {
            if (v[i] > other.v[i])
                return true;
            if (v[i] < other.v[i])
                return false;
        }
        return false;
    }
    
    bool operator==(const Num &other) const {
        return !(*this > other) && !(other > *this);
    }
    bool operator!=(const Num &other) const {
        return (*this > other) || (other > *this);
    }
    bool operator<=(const Num &other) const {
        return !(*this > other);
    }

    Num Sqrt() const {
        Num r;
        r.len = (len + 1) / 2;
        for (int i = r.len - 1; i >= 0; i--) {
            for (r.v[i] = 9; r * r > *this; r.v[i]--) { }
        }
        return r;
    }
    
    int ToInt() const {
        int r = 0;
        int pos = 1;
        for (int i = 0; i < len; i++) {
            r += v[i] * pos;
            pos *= 10;
        }
        return r;
    }

    friend Num operator*(const Num &a, const Num &b);

    void Dump() {
        for (int i = len - 1; i >= 0; i--)
            cout << v[i];
        // cout << '(' << len << ')';
        cout << endl;
    }

    void Normalize() {
        int remain = 0;
        for (int i = 0; i < LEN_MAX - 1; i++) {
            remain += v[i];
            if (remain > 0)
                len = i + 1;
            v[i] = remain % 10;
            remain /= 10;
        }
    }
};

Num operator*(const Num &a, const Num &b) {
    Num r;
    for (int i = 0; i < a.len; i++) {
        for (int j = 0; j < b.len; j++)
            r.v[i + j] += a.v[i] * b.v[j];
    }
    r.Normalize();
    return r;
}

Num A, B;
Num RootA, RootB;

Num X;
int answer;

void search(int pos, int mid) {
// cout << "! " << X.ToInt() << " " << pos << " " << mid << " " << answer << endl;
    if (pos * 2 >= X.len) {
        if (RootA <= X && X <= RootB) {
            answer++;
        }
        return;
    }
    if (pos * 2 == X.len - 1) {
        for (int digit = 0; digit*digit + mid < 10; digit++) {
            X.v[pos] = digit;
            if (RootA <= X && X <= RootB) {
                answer++;
            }
        }
        return;
    }

    for (int digit = (pos==0?1:0); digit*digit*2 + mid < 10; digit++) {
        X.v[pos] = digit;
        X.v[X.len - pos - 1] = digit;
        search(pos + 1, digit*digit*2 + mid);
    }
}

void count(int length) {
    X.Set("0");
    X.len = length;
    search(0, 0);
}

int solve() {
    RootA = A.Sqrt();
    RootB = B.Sqrt();
    if (A > RootA * RootA)
        RootA += 1;

    answer = 0;
    for (int i = RootA.len; i <= RootB.len; i++) {
        count(i);
    }

    return answer;
}

int main() {
    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        string s1, s2;
        cin >> s1 >> s2;
        A.Set(s1);
        B.Set(s2);
        cout << "Case #" << testcase << ": " << solve() << endl;
    }
    return 0;
}
