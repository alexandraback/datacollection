#include <iostream>
using namespace std;

class Quaternion {
  private:
    char val;
    int sign;
  public:
    Quaternion() : val('1'), sign(1) {}
    Quaternion(char val) : val(val), sign(1) {}
    Quaternion(char val, int sign) : val(val), sign(sign) {}
    Quaternion operator * (Quaternion q) {
        if (val == '1')
            return Quaternion(q.val, sign * q.sign);
        if (q.val == '1')
            return Quaternion(val, sign * q.sign);
        if ((val == 'i') && (q.val == 'j')) {
            return Quaternion('k', sign * q.sign);
        }
        if ((val == 'j') && (q.val == 'k')) {
            return Quaternion('i', sign * q.sign);
        }
        if ((val == 'k') && (q.val == 'i')) {
            return Quaternion('j', sign * q.sign);
        }
        if ((val == 'j') && (q.val == 'i')) {
            return Quaternion('k', -1 * sign * q.sign);
        }
        if ((val == 'k') && (q.val == 'j')) {
            return Quaternion('i', -1 * sign * q.sign);
        }
        if ((val == 'i') && (q.val == 'k')) {
            return Quaternion('j', -1 * sign * q.sign);
        }
        if (val == q.val) {
            return Quaternion('1', -1 * sign * q.sign);
        }
        return Quaternion('0', 0);
    }
    bool operator == (Quaternion q) {
        return ((val == q.val) && (sign == q.sign)); 
    }
    bool operator != (Quaternion q) {
        return !((*this) == q);
    }
    friend ostream& operator << (ostream& os, Quaternion q);
};

ostream& operator << (ostream& os, Quaternion q) {
    if (q.sign == -1)
        os << '-';
    os << q.val;
    return os;
}

const int MAX_L = 16 * 100000 + 500;
Quaternion a[MAX_L];
long long L, X;

int nFactors(int start, Quaternion res) {
    int i = start;
    Quaternion current_product = Quaternion('1', 1);
    while ((i < L * X) && (current_product != res)) {
        current_product = current_product * a[i];
        ++i;
    }
    if (current_product == res)
        return i - start;
    return -1;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> L >> X;
        X = X % 16 + 16 * (X >= 16);
        Quaternion current_product = Quaternion('1', 1);
        for (int i = 0; i < L; ++i) {
            char ch;
            cin >> ch;
            a[i] = Quaternion(ch);
        }
        for (int i = L; i < L * X; ++i) {
            a[i] = a[i % L];
        }
        //for (int i = 0; i < L * X; ++i) {
        //    cout << a[i];
        //}
        //cout << endl;
        for (int i = 0; i < L * X; ++i) {
            //cout << current_product << "*" << a[i] << "=" << (current_product * a[i]) << endl;
            current_product = current_product * a[i];
        }
        if (   (current_product == Quaternion('1', -1))
            && (nFactors(0,                                   Quaternion('i', 1)) != -1)
            && (nFactors(0 + nFactors(0, Quaternion('i', 1)), Quaternion('j', 1)) != -1)) {
            cout << "Case #" << t << ": YES" << endl;
        } else {
            cout << "Case #" << t << ": NO"  << endl;
        }
    }
    return 0;
}