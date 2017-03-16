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

    ifstream fin ("C-large.in");
    ofstream fout ("dijkstra.out");

    //MOD COULD BE NEGATIVE
    //cout << (-1%3) << endl;

    int t;
    fin >> t;

    ll l, x, i;
    string line;
    for (int test = 0; test < t; test++) {
        fin >> l >> x;
        fin >> line;

        cout << "TEST " << (test+1) << " " << "DOING..." << endl;

        //FIND IF FULL STRING IS -1
        string whole = "1";
        for (int ii = 0; ii < line.size(); ii++) {
            //cout << "QMUL " << whole << ' ' << ctos(full[i]) << endl;
            whole = qmul(whole, ctos(line[ii]));
        }
        //CHECK IF WHOLE IS VALID
        if (whole == "1") {
            //CAN NEVER BE -1
            fout << "Case #" << (test+1) << ": " << "NO" << "\n";
            continue;
        } else if (whole == "-1") {
            //CAN NEVER BE -1 IF EVEN
            if (x%2 == 0) {
                fout << "Case #" << (test+1) << ": " << "NO" << "\n";
                continue;
            }
        } else if ((whole == "i") || (whole == "j") || (whole == "k")) {
            //CAN NEVER BE -1 IF EVEN
            if (x%4 != 2) {
                fout << "Case #" << (test+1) << ": " << "NO" << "\n";
                continue;
            }
        } else if ((whole == "-i") || (whole == "-j") || (whole == "-k")) {
            //CAN NEVER BE -1 IF EVEN
            if (x%4 != 2) {
                fout << "Case #" << (test+1) << ": " << "NO" << "\n";
                continue;
            }
        }

        cout << "WE GOT HERE" << endl;


        //FIND IF PREFIX IS "i"
        string pre = "1";
        ll ipos = -1;
        for (int ii = 0; ii < 100000; ii++) {
            i = ii%(line.size());
            pre = qmul(pre, ctos(line[i]));
            if (pre == "i") {
                ipos = ii;
                break;
            }
        }

        cout << "IPOS: " << ipos << endl;

        //FIND PREFIX IS 'K'
        string suf = "1";
        ll kpos = line.size();
        for (int ii = line.size()-1; ii >= -100000; ii--) {
            i = ii%(line.size());
            if (i < 0) {
                i += line.size();
            }

            suf = qmul(ctos(line[i]), suf);
            if (suf == "k") {
                kpos = ii;
                break;
            }
        }

        cout << "KPOS: " << kpos << endl;

        if ((ipos != -1) && (kpos != line.size())) {
            if (ipos < (kpos + l*x - line.size())) {
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
