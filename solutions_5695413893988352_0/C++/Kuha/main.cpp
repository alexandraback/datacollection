#include <bits/stdc++.h>

#define pii pair<int, int>
#define pdd pair<double, double>
#define ull unsigned long long
#define uint unsigned int
#define ll long long
#define INF 999999999
#define LINF 999999999999999999
#define M 1000000007
#define E 0.0000001
#define N (1<<17)

using namespace std;



int main() {
    ifstream in("google.in");
    ofstream out("google.out");

    int n;
    in>>n;

    for (int c = 1; c <= n; c++) {
        string s, t;
        in>>s>>t;

        int ts, tj;
        int x = 1;
        for (int i = 0; i < s.length(); i++) {
            x *= 10;
        }

        int ans = INF;
        int ai = 0, aj = 0;
        for (int i = 0; i < x; i++) {
            int ti = i;
            bool b = true;
            for (int p = s.length() - 1; p >= 0; p--) {
                //if (s[p] != '?') cout<<"xD "<<i<<" "<<(ti % 10)<<" "<<(int)(s[p] - '0')<<endl;
                if (s[p] != '?' && ti % 10 != s[p] - '0') {
                    //cout<<"TTETT"<<endl;
                    b = false;
                    break;
                }
                ti /= 10;
            }
            if (b) {
                for (int j = 0; j < x; j++) {
                    int tj = j;
                    b = true;
                    for (int p = s.length() - 1; p >= 0; p--) {
                        if (t[p] != '?' && tj % 10 != t[p] - '0') {
                            b = false;
                            break;
                        }
                        tj /= 10;
                    }
                    if (b) {
                        if (abs(i - j) < ans) {
                            ans = abs(i - j);
                            ai = i;
                            aj = j;
                        }
                    }
                }
            }
            //cout<<i<<endl;
        }

        out<<"Case #"<<c<<": ";
        vector<int> vi;
        while (ai) {
            vi.push_back(ai % 10);
            ai /= 10;
        }
        vector<int> vj;
        while (aj) {
            vj.push_back(aj % 10);
            aj /= 10;
        }
        for (int i = s.length(); i > 0; i--) {
            if (vi.size() < i) out<<0;
            else out<<vi[i - 1];
        }
        out<<" ";
        for (int i = s.length(); i > 0; i--) {
            if (vj.size() < i) out<<0;
            else out<<vj[i - 1];
        }
        out<<endl;
    }

    out.close();
    return 0;
}
