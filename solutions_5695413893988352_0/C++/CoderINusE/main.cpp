#include <bits/stdc++.h>
#define INF 1000000000
#define MAXN 1000005
#define PI 3.14159265358979323846
using namespace std;
typedef long long ll;
typedef int char_32;
const ll mod = 1000000007;
#define INF16 1000000

int used[2005];
int d[30];
vector <int> vi;

vector <int> fir, sec;

void f(string a, int k, int d, int dec) {
    if(k == a.size() - 1) {
        if(a[k] == '?') {

            for(int i = 0; i <= 9; ++i)
                fir.push_back(d+i);

        }
        else {

            fir.push_back(d + (int)(a[k] - '0'));

        }

        return;

    }


    if(a[k] == '?') {
        for(int i = 0; i <= 9; ++i)
            f(a, k + 1, d + dec*i, dec / 10);
    }
    else {
        return f(a, k + 1, d + dec*((int)a[k]-'0'), dec / 10);

    }
}
void f2(string a, int k, int d, int dec) {
    if(k == a.size() - 1) {
        if(a[k] == '?') {

            for(int i = 0; i <= 9; ++i)
                sec.push_back(d+i);

        }
        else {

            sec.push_back(d + (int)(a[k] - '0'));

        }

        return;

    }


    if(a[k] == '?') {
        for(int i = 0; i <= 9; ++i)
            f2(a, k + 1, d + dec*i, dec / 10);
    }
    else {
        return f2(a, k + 1, d + dec*((int)a[k]-'0'), dec / 10);

    }
}

int main() {
    freopen("B-small-attempt3.in", "r", stdin);
    freopen("ancestor.out", "w", stdout);
    string a, b;
    int t, flag = 0; cin >> t;
    for(int i = 0; i < t; ++i) {
            vector <int> ansa, ansb;
            cin >> a >> b;
            fir.clear(), sec.clear();
            int dec = 1;
            for(int i = 0; i < a.size()-1; ++i) dec *= 10;
            f(a, 0, 0, dec);
            f2(b, 0, 0, dec);

            int dif = 100000;
            int is, js, firs;
            for(int i = 0; i < fir.size(); ++i)
            for(int j = 0; j < sec.size(); ++j) {

                int dd = fabs(fir[i] - sec[j]);

                if(dd < dif) {

                    dif = dd;
                    is = i;
                    js = j;
                    firs = fir[i];

                }
                if(dd == dif && fir[i] < firs) {

                    dif = dd;
                    is = i;
                    js = j;
                    firs = fir[i];

                }

            }
            cout << "Case #" << i + 1 << ": ";
            int temp = fir[is], kz = 0;
            if(temp != 0) {
            while(temp) {

                kz += 1;
                temp /= 10;

            }
            }
            else kz = 1;
            for(int i = 0; i < a.size() - kz; ++i) cout << "0";

            cout << fir[is] << " ";


            int temp2 = sec[js], kz2 = 0;
            if(temp2 != 0) {
            while(temp2) {

                kz2 += 1;
                temp2 /= 10;

            }
            }
            else kz2 = 1;

            for(int i = 0; i < b.size() - kz2; ++i) cout << "0";
            cout << sec[js] << endl;


    }
}
