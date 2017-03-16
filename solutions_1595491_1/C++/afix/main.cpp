#include <fstream>

using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

bool cansurp(int t, int p) {
    int res, i[3] = {3, 4, 2};
    if (t <= 2) res = t;
    else if (t == 3) res = 2;
    else res = (t - i[t%3])/3 + 2;
    return res >= p;
}

bool cannonsurp(int t, int p) {
    return (t/3 + ((t%3) > 0)) >= p;
}

int T, s, p, so, nso, sns, t, n, res;

int main() {
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        sns = so = nso = res = 0;
        cin >> n >> s >> p;
        for (int j = 0; j < n; ++j) {
            cin >> t;
            if (cansurp(t, p) && cannonsurp(t, p)) ++sns;
            else if (cansurp(t, p)) ++so;
            else if (cannonsurp(t, p)) ++nso;
        }
        //cout << so << ' ' << nso << ' ' << sns << ' ';
        res = max(min(so, s), 0);
        so -= res; s -= res;
        int dres = max(min(s, sns), 0);
        res += dres;
        s -= dres; sns -= dres;
        res += max(nso + sns - s, 0);
        cout << "Case #" << i << ": " << res << endl;
    }
}
