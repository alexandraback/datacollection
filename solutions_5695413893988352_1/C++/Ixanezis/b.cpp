#include <iostream>
#include <map>
#include <algorithm>
#include <stdexcept>
#include <iomanip>

using namespace std;

long long calc(const string& x, char repl) {
    long long ret = 0;
    if (x.size() < 1) throw runtime_error("oh no no no");
    for (size_t i=0; i<x.size(); ++i) {
        ret *= 10;
        ret += x[i] == '?' ? repl - '0' : x[i] - '0';
    }
    return ret;
}

long long getmin(const string& x) {
    return calc(x, '0');
}

long long getmax(const string& x) {
    return calc(x, '9');
}

long long ten[20] = {1};

void fillequal(string& a, string& b, int until) {
    for (int i=0; i<until; ++i) {
        if (a[i] == '?' && b[i] != '?') {
            a[i] = b[i];
        } else if (a[i] != '?' && b[i] == '?') {
            b[i] = a[i];
        } else if (a[i] == '?' && b[i] == '?') {
            a[i] = b[i] = '0';
        } else if (a[i] != '?' && b[i] != '?') {
            // do nothing
        } else {
            throw runtime_error("oh no no no");
        }
    }
}

void fillequalsolution(string a, string b) {
    fillequal(a, b, a.size());
    cout << a << ' ' << b << endl;
}

void fill(string& a, int from, char c) {
    for (int i=from; i<int(a.size()); ++i)
        if (a[i] == '?')
            a[i] = c;
}

void fillmin(string& a, int from) {
    fill(a, from, '0');
}

void fillmax(string& a, int from) {
    fill(a, from, '9');
}

void solve(int e) {
    string a, b; cin >> a >> b;

    cout << "Case #" << e << ": ";

    int bad = -1;
    for (size_t i=0; i<a.size(); ++i) {
        if (a[i] != '?' && b[i] != '?' && a[i] != b[i]) {
            bad = int(i);
            break;
        }
    }

    if (bad == -1) {
        cerr << "no bad found" << endl;
        fillequalsolution(a, b);
    } else {
        cerr << "bad found at position " << bad << endl;
        char sw = a[bad] > b[bad];
        if (sw)
            swap(a, b);

        cerr << "working with " << a << ' ' << b << endl;

        long long mna = getmin(a.substr(bad));
        long long mxa = getmax(a.substr(bad));
        long long mnb = getmin(b.substr(bad));
        long long mxb = getmax(b.substr(bad));

        string aa = a;
        string bb = b;

        cerr << "mna, mxa, mnb, mxb: " << mna << ' ' << mxa << ' ' << mnb << ' ' << mxb << endl;
        long long best = mnb - mxa;
        cerr << "best: " << best << endl;
        bool done = false;
        for (int i=bad-1; i>=0; --i) {
            int curb, cura;
            if (a[i] != '0' && b[i] != '9') {
                curb = b[i] == '?' ? (a[i] == '?' ? 0 : a[i] - 1 - '0') : b[i] - '0';
                cura = a[i] == '?' ? min(9, curb + 1) : a[i] - '0';
            } else {
                cura = a[i] == '?' ? 0 : a[i] - '0';
                curb = b[i] == '?' ? 9 : b[i] - '0';
            }

            aa[i] = cura + '0';
            bb[i] = curb + '0';

            mna += ten[int(a.size()) - i - 1] * cura;
            mxb += ten[int(a.size()) - i - 1] * curb;

            cerr << "mna and mxb: " << mna << ' ' << mxb << endl;

            if (a[i] != '0' && b[i] != '9') {
                long long curbest = mna - mxb;
                cerr << "curbest at position " << i << ": " << curbest << endl;
                if (curbest < best || (curbest == best && a[i] != '?')) {
                    cerr << boolalpha << (a[i] == '?' && b[i] == '?') << endl;
                    if (a[i] == '?' && b[i] == '?' && i > 0 && b[i-1] == '?' && a[i-1] != '?' && a[i-1] != '0') {
                        cerr << "HERE" << endl;
                        aa[i] = '0';
                        bb[i] = '9';
                        bb[i-1] = aa[i-1] - 1;
                    }

                    a = aa;
                    b = bb;

                    fillequal(a, b, i);
                    fillmin(a, i);
                    fillmax(b, i);
                    done = true;
                }
                break;
            }

        }

        if (!done) {
            fillequal(a, b, bad);
            fillmax(a, bad);
            fillmin(b, bad);
        }

        if (sw)
            swap(a, b);

        cout << a << ' ' << b << endl;
    }
}

int main() {
    for (int i=1; i<19; ++i)
        ten[i] = ten[i-1] * 10;

    int t; cin >> t;
    for (int e=0; e<t; ++e)
        solve(e+1);
}
