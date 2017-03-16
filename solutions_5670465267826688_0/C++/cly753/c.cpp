#include <iostream>

using namespace std;

#define QI 2
#define QJ 3
#define QK 4

#define abs(x) ((x) > 0 ? (x) : -(x))

int qrule[5][5];

long long l, x;
string s;
string xs;
int value[140002];
int rValue[140002];

void init() {
    qrule[ 1][ 1] =   1;
    qrule[ 1][QI] =  QI;
    qrule[ 1][QJ] =  QJ;
    qrule[ 1][QK] =  QK;

    qrule[QI][ 1] =  QI;
    qrule[QI][QI] =  -1;
    qrule[QI][QJ] =  QK;
    qrule[QI][QK] = -QJ;

    qrule[QJ][ 1] =  QJ;
    qrule[QJ][QI] = -QK;
    qrule[QJ][QJ] =  -1;
    qrule[QJ][QK] =  QI;

    qrule[QK][ 1] =  QK;
    qrule[QK][QI] =  QJ;
    qrule[QK][QJ] = -QI;
    qrule[QK][QK] =  -1;
}

int mul(int a, int b) {
    int neg = a * b / abs(a * b);
    return neg * qrule[abs(a)][abs(b)];
}

int get(char q) {
    switch (q) {
        case 'i': return QI;
        case 'j': return QJ;
        case 'k': return QK;
    }
}

string push(int q) {
    switch (q) {
        case   1: return " 1";
        case  QI: return " i";
        case  QJ: return " j";
        case  QK: return " k";
        case  -1: return "-1";
        case -QI: return "-i";
        case -QJ: return "-j";
        case -QK: return "-k";
    }
}

bool sol() {
    if (x > 14) {
        for (int i = 14; i > 0; i--) {
            if ((x - i) % 4 == 0) {
                x = i;
                break;
            }
        }
    }

    xs = "";
    for (int i = 0; i < x; i++)
        xs += s;

    // cout << "xs: " << xs << endl;

    int QIINDEX = -1;
    value[0] = get(xs[0]);
    if (value[0] == QI)
        QIINDEX = 0;
    else
        for (int i = 1; i < xs.length(); i++) {
            value[i] = mul(value[i - 1], get(xs[i]));

            if (value[i] == QI) {
                QIINDEX = i;
                break;
            }
        }

    if (QIINDEX == -1)
        return false;

    // cout << "value: " << endl;
    // for (int i = 0; i < xs.length(); i++)
    //     // cout << value[i] << " ";
    //     cout << push(value[i]) << " ";
    // cout << endl;
    
    rValue[xs.length() - 1] = get(xs[xs.length() - 1]);
    for (int i = xs.length() - 2; i >= 0; i--)
        rValue[i] = mul(get(xs[i]), rValue[i + 1]);

    // cout << "rValue: " << endl;
    // for (int i = 0; i < xs.length(); i++)
    //     // cout << rValue[i] << " ";
    //     cout << push(rValue[i]) << " ";
    // cout << endl;

    int cur = 1;
    for (int j = QIINDEX + 1; j < xs.length() - 1; j++) {
        // cout << "j = " << j << ", xs[j] = " << xs[j] << ", get(s[j]) = " << push(get(xs[j])) << endl;
        cur = mul(cur, get(xs[j]));

        // cout << "j = " << j << ", cur = " << push(cur) << endl;

        if (cur != QJ)
            continue;

        if (rValue[j + 1] == QK)
            return true;
        return false;
    }
    return false;
}

int main(int argc, char const *argv[]) {
    init();

    int t;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        cin >> l >> x >> s;
        if (sol())
            cout << "Case #" << c << ": YES" << endl;
        else
            cout << "Case #" << c << ": NO" << endl;
    }
}