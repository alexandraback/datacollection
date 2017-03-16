#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

const char ONE_n = 0;
const char I_n = 1;
const char J_n = 2;
const char K_n = 3;
struct Quad {
    static const Quad ONE;
    static const Quad I;
    static const Quad J;
    static const Quad K;

    char sign;
    char type;
    Quad(char sign, char type) :sign(sign), type(type) {}
    Quad() :Quad(0, ONE_n) {}

    const char *str() const {
        if (sign) {
            switch (type) {
            case ONE_n:
                return "-1";
            case I_n:
                return "-i";
            case J_n:
                return "-j";
            case K_n:
                return "-k";
            }
        }

        switch (type) {
        case ONE_n:
            return "1";
        case I_n:
            return "i";
        case J_n:
            return "j";
        case K_n:
            return "k";
        }
    }

    bool operator==(const Quad &o) const {
        return sign == o.sign && type == o.type;
    }
    bool operator!=(const Quad &o) const {
        return !(*this == o);
    }
};
const Quad Quad::ONE = Quad(0, ONE_n);
const Quad Quad::I = Quad(0, I_n);
const Quad Quad::J = Quad(0, J_n);
const Quad Quad::K = Quad(0, K_n);

Quad mul(const Quad &left, const Quad &right) {
    switch (left.type) {
    case ONE_n:
        return Quad(left.sign^right.sign, right.type);

    case I_n:
        switch (right.type) {
        case ONE_n:
            return Quad(left.sign^right.sign, I_n);
        case I_n:
            return Quad(1 ^ left.sign^right.sign, ONE_n);
        case J_n:
            return Quad(left.sign^right.sign, K_n);
        case K_n:
            return Quad(1 ^ left.sign^right.sign, J_n);
        }

    case J_n:
        switch (right.type) {
        case ONE_n:
            return Quad(left.sign^right.sign, J_n);
        case I_n:
            return Quad(1 ^ left.sign^right.sign, K_n);
        case J_n:
            return Quad(1 ^ left.sign^right.sign, ONE_n);
        case K_n:
            return Quad(left.sign^right.sign, I_n);
        }

    case K_n:
        switch (right.type) {
        case ONE_n:
            return Quad(left.sign^right.sign, K_n);
        case I_n:
            return Quad(left.sign^right.sign, J_n);
        case J_n:
            return Quad(1 ^ left.sign^right.sign, I_n);
        case K_n:
            return Quad(1 ^ left.sign^right.sign, ONE_n);
        }
    }
}
Quad operator*(const Quad &left, const Quad &right) {
    return mul(left, right);
}
Quad div(Quad res, Quad left) {
    for (int s = 0; s <= 1; s++)
        for (int t = 0; t <= 3; t++)
            if (mul(left, Quad(s, t)) == res)
                return Quad(s, t);
}

template<typename T>
T pow(const T &base, ll e) {
    if (e == 1)
        return base;
    if (e % 2 == 0) {
        T tmp = pow(base, e / 2);
        return tmp*tmp;
    }
    return pow(base, e / 2)*pow(base, e / 2 + 1);
}

Quad toQuad(char c) {
    switch (c) {
    case 'i':
        return Quad::I;
    case 'j':
        return Quad::J;
    case 'k':
        return Quad::K;
    }
}

bool solve(istream &in) {
    ll L, X;
    in >> L >> X;
    string s;
    in >> s;

    // Compute base
    Quad base = Quad::ONE;
    for (char c : s) {
        base = mul(base, toQuad(c));
    }
    Quad powered = pow(base, X);
    if (powered != Quad(1, ONE_n))
        return false;

    // Find i and then j
    bool iFound = 0;
    Quad accm = Quad::ONE;
    for (int i = 0; i < min(16ll, X) * L; i++) {
        accm = mul(accm, toQuad(s[i%L]));
        if (!iFound && accm == Quad::I) {
            iFound = true;
            accm = Quad::ONE;
        }
        if (iFound && accm == Quad::J)
            return true;
    }
    return false;
}


int main(int argc, char **args) {
    if (argc != 3) {
        cout << "Usage: StandingOvation file.in file.out" << endl;
        return 0;
    }
    ifstream fin(args[1]);
    ofstream fout(args[2]);

    int t;
    fin >> t;
    for (int i = 0; i < t; i++) {
        fout << "Case #" << i + 1 << ": " << (solve(fin) ? "YES" : "NO") << '\n';
        cout << i;
    }

    fout.close();
    fin.close();
}