#include <iostream>
#include <string>
#include <bitset>

using namespace std;

long long tobase(string s, long long b) {
    long long nxt = 1;
    long long res = 0;
    for (int i = s.length()-1; i >= 0; --i) {
        if (s[i] == '1') {
            res += nxt;
        }
        nxt = nxt*b;
    }
    return res;
}

long long isprime(long long i)
{
    for (long long x = 2; x*x <= i; ++x) {
        if (i % x == 0)
            return x;
    }
    return 1;
}

int main()
{
    int t;
    cin >> t;
    int n,jj;
    cin >> n >> jj;
    cout << "Case #1:" << endl;
    for (int i = 32769; i < 65536; i+=2)
    {
//        cout << "=====" <<i<< "====";
        string s = bitset<16>(i).to_string();
//        cout << s << endl;
        bool p = false;
        long long divs[11];
        for (int j = 2; j <= 10; ++j) {
            long long x = tobase(s,j);
//            cout << "asdgasdg: " << x << endl;
            divs[j] = isprime(x);
            if (divs[j] == 1) {
                p = true;
                break;
            }
        }
        if (p)
            continue;
        else {
            jj--;
            cout << s << " ";
            for (int j = 2; j <= 10; ++j)
                cout << divs[j] << " ";
            cout << endl;
            if (jj == 0)
                break;
        }
    }
}
