#include <iostream>
#include <vector>
#include <set>
#include <string>



using namespace std;

long long sn(long long a) {
    return (a * (a + 1LL)) / 2LL;
}

long long solve(string s, int nn) {
    long long n = nn;
    vector<pair<int, int> > valid;
    int ccnt = 0, beg = -1;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'e' || s[i] == 'a' || s[i] == 'o' || s[i] == 'i' || s[i] == 'u') {
            if(ccnt) {
                if(ccnt >= n) {
                    valid.push_back(pair<int, int>(beg, beg + ccnt - 1));
                }
                ccnt = 0;
                beg = -1;
            }

        } else {
            ccnt++;
            if(beg == -1) {
                beg = i;
            }
        }
    }
    if(ccnt) {
        if(ccnt >= n) {
            valid.push_back(pair<int, int>(beg, beg + ccnt - 1));
        }
        ccnt = 0;
        beg = -1;
    }
    long long res = 0, f = s.size();
//    cout << s << " " << f << endl;
    for(int i = 0; i < valid.size(); i++) {
        long long l, r, s, ll;
        l = valid[i].first;
        r = valid[i].second;
        s = r - l + 1;

        ll = i ? valid[i - 1].second - (n - 2) : 0;
//        cout << l << " " << r << endl;
//        cout << ll << endl;
        res += (l - ll + 1) * (f - r + s - n);
//        cout << (l - ll + 1) * (f - r + s - n) << endl;
        if ( s > n) {
            res += sn(f - l - n );
            res -= sn(f - l - s );
        }
//        cout << sn(f - l - n - 1) - sn(f - l - s - 1) << endl << endl;
    }

    return res;
}

void input(string &s, int &n) {
    cin >> s >> n;
}

void output(int t, long long res) {
    cout << "Case #" << t << ": " << res << endl;
}


int main() {
    int t, n;
    long long r;
    string s;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        input(s, n);
        r = solve(s, n);
        output(i, r);
    }
    return 0;
}