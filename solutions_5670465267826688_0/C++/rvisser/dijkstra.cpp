#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fr first
#define sc second

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string ctos(char c) {
    stringstream ss;
    string s;
    ss << c;
    ss >> s;
    return s;
}

string neg(string a) {
    //cout << "NEG: " << a << endl;

    if (a.size() == 1) {
        string ans = "-" + a;
        return ans;
    } else {
        return ctos(a[1]);
    }
}

string qm(string a, string b) {
    //cout << "QM: " << a << ' ' << b << endl;

    if (a=="1") {
        if (b=="1") {
            return "1";
        } else if (b=="i") {
            return "i";
        } else if (b=="j") {
            return "j";
        } else if (b=="k") {
            return "k";
        }
    } else if (a=="i") {
        if (b=="1") {
            return "i";
        } else if (b=="i") {
            return "-1";
        } else if (b=="j") {
            return "k";
        } else if (b=="k") {
            return "-j";
        }
    } else if (a=="j") {
        if (b=="1") {
            return "j";
        } else if (b=="i") {
            return "-k";
        } else if (b=="j") {
            return "-1";
        } else if (b=="k") {
            return "i";
        }
    } else if (a=="k") {
        if (b=="1") {
            return "k";
        } else if (b=="i") {
            return "j";
        } else if (b=="j") {
            return "-i";
        } else if (b=="k") {
            return "-1";
        }
    }
}

string qmul(string a, string b) {
    //cout << "QMUL: " << a << ' ' << b << endl;

    if ((a.size() == 1) && (b.size() == 1)) {
        return qm(a, b);
    } else if ((a.size() == 1) && (b.size() == 2)) {
        return neg(qm(a, ctos(b[1])));
    } else if ((a.size() == 2) && (b.size() == 1)) {
        return neg(qm((ctos(a[1])), b));
    } else {
        return qm(ctos(a[1]), ctos(b[1]));
    }
}

int main()
{
    ios::sync_with_stdio(false);

    ifstream fin ("dijkstra.in");
    ofstream fout ("dijkstra.out");

    int t;
    fin >> t;

    int l, x;
    string line, full;
    for (int test = 0; test < t; test++) {
        fin >> l >> x;
        fin >> line;

        // CONSTRUCT ENTIRE LINE
        full = "";
        for (int i = 0; i < x; i++) {
            full = full + line;
        }

        //cout << "TEST " << (test+1) << " " << full << endl;

        //FIND IF FULL STRING IS -1
        string whole = "1";
        for (int i = 0; i < full.size(); i++) {
            //cout << "QMUL " << whole << ' ' << ctos(full[i]) << endl;
            whole = qmul(whole, ctos(full[i]));
        }
        if (whole != "-1") {
            fout << "Case #" << (test+1) << ": " << "NO" << "\n";
            continue;
        }


        //FIND IF PREFIX IS "i"
        string pre = "1";
        int ipos = -1;
        for (int i = 0; i < full.size(); i++) {
            pre = qmul(pre, ctos(full[i]));
            if (pre == "i") {
                ipos = i;
                break;
            }
        }

        //FIND PREFIX IS 'K'
        string suf = "1";
        int kpos = -1;
        for (int i = full.size()-1; i >= 0; i--) {
            suf = qmul(ctos(full[i]), suf);
            if (suf == "k") {
                kpos = i;
                break;
            }
        }

        if ((ipos != -1) && (kpos != -1)) {
            if (ipos < kpos) {
                fout << "Case #" << (test+1) << ": " << "YES" << "\n";
            } else {
                fout << "Case #" << (test+1) << ": " << "NO" << "\n";
            }
        } else {
            fout << "Case #" << (test+1) << ": " << "NO" << "\n";
        }
    }

    return 0;
}
