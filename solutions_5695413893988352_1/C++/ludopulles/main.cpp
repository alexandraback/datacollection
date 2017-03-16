#include <bits/stdc++.h>

using namespace std;

#define INF 2147483647
#define MOD 1000000007
#define MAX 100000

typedef long long ll;
typedef pair<ll, ll> pii;

ll pow10(int n)
{
    ll r = 1LL;
    while (n--) r *= 10LL;
    return r;
}

inline bool valid(const string &s, ll num)
{
    int n = s.size();
    vector<int> digits;
    while ((int) digits.size() < n) {
        digits.push_back((int) (num % 10LL));
        num /= 10LL;
    }
    reverse(digits.begin(), digits.end());
    for (int i = 0; i < n; i++) {
        if (s[i] != '?' && (s[i] - '0') != digits[i]) {
            return false;
        }
    }
    return true;
}

void print_num(ll num, int len)
{
    vector<int> digits;
    while ((int) digits.size() < len) {
        digits.push_back((int) (num % 10LL));
        num /= 10LL;
    }
    reverse(digits.begin(), digits.end());
    for (int i : digits) {
        cout << i;
    }
}

string a, b;

bool isBetter(pii solA, pii solB)
{
    ll da = abs(solA.first - solA.second);
    ll db = abs(solB.first - solB.second);
    if (da != db) return da < db;
    if (solA.first != solB.first) return solA.first < solB.first;
    return solA.second < solB.second;
}

pii minLmaxR(ll cura, ll curb, int idx, int len)
{
    assert(cura > curb);
    for ( ; idx < len; idx++) {
        ll numA = a[idx] == '?' ? 0 : (a[idx] - '0');
        ll numB = b[idx] == '?' ? 9 : (b[idx] - '0');
        cura = cura * 10 + numA;
        curb = curb * 10 + numB;
    }
    return pii(cura, curb);
}

pii maxLminR(ll cura, ll curb, int idx, int len)
{
    assert(cura < curb);
    for ( ; idx < len; idx++) {
        ll numA = a[idx] == '?' ? 9 : (a[idx] - '0');
        ll numB = b[idx] == '?' ? 0 : (b[idx] - '0');
        cura = cura * 10 + numA;
        curb = curb * 10 + numB;
    }
    return pii(cura, curb);
}

pii minDiff(ll cura, ll curb, int idx, int len)
{
    if (idx == len) {
        return pii(cura, curb);
    }

    assert(cura == curb);

    char cl = a[idx], cr = b[idx];
    if (cl == '?') {
        if (cr == '?') {
            // fill 0, 0
            pii best = minDiff(cura * 10, curb * 10, idx + 1, len), alt;

            alt = maxLminR(cura * 10, curb * 10 + 1, idx + 1, len);
            if (isBetter(alt, best)) best = alt;

            alt = minLmaxR(cura * 10 + 1, curb * 10, idx + 1, len);
            if (isBetter(alt, best)) best = alt;

            return best;
        } else {
            // cr is number

            ll d = cr - '0', nxtb = curb * 10 + d;
            pii best = minDiff(nxtb, nxtb, idx + 1, len);
            if (d > 0) {
                pii alt = maxLminR(nxtb - 1, nxtb, idx + 1, len);
                if (isBetter(alt, best)) best = alt;
            }
            if (d < 9) {
                pii alt = minLmaxR(nxtb + 1, nxtb, idx + 1, len);
                if (isBetter(alt, best)) best = alt;
            }

//            int nxtb = curb * 10 + (cr - '0');
//            pii best(-1, -1);
//
//            for (int dd = -1; dd <= 1; dd++) {
//                int d = (cr - '0') + dd;
//                if (d < 0 || d > 9) continue;
//
//                int nxta = cura * 10 + d;
//                pii alt;
//
//                if (nxta == nxtb) {
//                    alt = minDiff(nxta, nxtb, idx + 1, len);
//                } else if (nxta < nxtb) {
//                    alt = maxLminR(nxta, nxtb, idx + 1, len);
//                } else {
//                    alt = minLmaxR(nxta, nxtb, idx + 1, len);
//                }
//
//                if (best == pii(-1, -1) || isBetter(alt, best)) {
//                    best = alt;
//                }
//            }
            return best;
        }
    } else {
        if (cr != '?') {
            // both numbers
            ll nxta = cura * 10 + (cl - '0');
            ll nxtb = curb * 10 + (cr - '0');

            if (cl == cr) {
                return minDiff(nxta, nxtb, idx + 1, len);
            } else if (cl > cr) {
                return minLmaxR(nxta, nxtb, idx + 1, len);
            } else {
                return maxLminR(nxta, nxtb, idx + 1, len);
            }
        } else {
            // cl is number
            ll d = cl - '0', nxta = cura * 10 + d;
            pii best = minDiff(nxta, nxta, idx + 1, len);
            if (d > 0) {
                pii alt = minLmaxR(nxta, nxta - 1, idx + 1, len);
                if (isBetter(alt, best)) best = alt;
            }
            if (d < 9) {
                pii alt = maxLminR(nxta, nxta + 1, idx + 1, len);
                if (isBetter(alt, best)) best = alt;
            }

//            for (int dd = -1; dd <= 1; dd++) {
//                int d = (cl - '0') + dd;
//                if (d < 0 || d > 9) continue;
//
//                int nxtb = curb * 10 + d;
//                pii alt;
//
////                cerr << "Possible: " << nxta << " " << nxtb << endl;
//
//                if (nxta == nxtb) {
//                    alt = minDiff(nxta, nxtb, idx + 1, len);
//                } else if (nxta < nxtb) {
//                    alt = maxLminR(nxta, nxtb, idx + 1, len);
//                } else {
//                    alt = minLmaxR(nxta, nxtb, idx + 1, len);
//                }
//
////                cerr << "Giving " << alt.first << ", " << alt.second << endl;
//
//                if (best == pii(-1, -1) || isBetter(alt, best)) {
//                    best = alt;
//                }
////                cerr << " -> " << best.first << " " << best.second << endl;
//            }
            return best;
        }
    }
}

void run()
{
    cin >> a >> b;
    int len = a.size();
    assert(len == (int) b.size());

    pii result = minDiff(0, 0, 0, len);

    print_num(result.first, len);
    cout << " ";
    print_num(result.second, len);
}

/*
void run()
{
    cin >> a >> b;
    int len = a.size();
    assert(len == (int) b.size());
    int pow = pow10(len);

    for (int diff = 0; diff < pow; diff++) {
        for (int i = 0; i < pow; i++) {
            if (!valid(a, i)) {
                continue;
            }

            int j = i - diff;
            if (j >= 0 && valid(b, j)) {
                print_num(i, len);
                cout << " ";
                print_num(j, len);
                return;
            }
            j = i + diff;
            if (j < pow && valid(b, j)) {
                print_num(i, len);
                cout << " ";
                print_num(j, len);
                return;
            }
        }
    }

    cout << a << " " << b;
}
*/

int main()
{
#ifdef LOCAL
    assert(freopen("input2.txt", "r", stdin));
    freopen("output3.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif // LOCAL

    int n;
    cin >> n;
    for (int tc = 1; tc <= n; tc++) {
        cout << "Case #" << tc << ": ";
        run();
        cout << endl;
    }
    return 0;
}
