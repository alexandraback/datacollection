#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum BASE {
    ONE = 0,
    I = 1,
    J = 2,
    K = 3,
};

struct Quat {
    int Sign;
    BASE Base;

    Quat(BASE base = ONE)
        : Sign(1)
        , Base(base)
    {}

    Quat(int sign, BASE base)
        : Sign(sign)
        , Base(base)
    {}

    Quat(char c)
        : Sign(1)
        , Base(ONE)
    {
        if (c == 'i')
            Base = I;
        else if (c == 'j')
            Base = J;
        else
            Base = K;
    }

    Quat& operator *= (const Quat& other);

    bool operator == (const Quat& other) {
        return Sign == other.Sign && Base == other.Base;
    }
};

Quat NEG_ONE(-1, ONE);

vector<vector<Quat>> tr = {
    { ONE, I, J, K },
    { ONE, NEG_ONE, K, Quat(-1, J) },
    { J, Quat(-1, K), NEG_ONE, I },
    { K, J, Quat(-1, I), NEG_ONE }
};

Quat& Quat::operator *= (const Quat& other) {
    Quat mul = tr[int(Base)][int(other.Base)];
    Sign *= mul.Sign * other.Sign;
    Base = mul.Base;
    return *this;
}

Quat calc(const string& expr) {
    Quat res;
    for (char c: expr) {
        res *= c;
    }
    return res;
}

int findQ(Quat start, Quat value, const string& expr) {
    for (int i = 0; i < expr.length(); ++i) {
        start *= expr[i];
        if (start == value) {
            return i;
        }
    }
    return -1;
}

string YES = "YES";
string NO = "NO";

string solveSmall(int x, const string& L) {
    string e;
    for (int i = 0; i < x; ++i)
        e += L;
    if (calc(e) == Quat(-1, ONE)) {
        int k1 = findQ(ONE, I, e);
        //cout << k1 << endl;
        if (k1 != -1) {
            e = e.substr(k1 + 1);
            int k2 = findQ(ONE, J, e);
            //cout << k2 << endl;
            if (k2 != -1) {
                return YES;
            }
        }
    }
    return NO;
}

string solveLarge(int x, const string& L) {
    return NO;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int testId = 1; testId <= T; ++testId) {
        int n, x;
        string L;
        cin >> n >> x >> L;
        cout << "Case #" << testId << ": ";
        if (x < 20)
            cout << solveSmall(x, L);
        else
            cout << solveSmall(x, L); // FIXME
        cout << "\n";
    }

    return 0;
}
