#include <iostream>
#include <algorithm>
using namespace std;

const int nmax = 100, amax = 100;
int l[nmax][nmax];
int n, m;
int cr[nmax], cc[nmax];
bool vr[nmax], vc[nmax], ml[nmax][nmax];
const bool deb = false;

int linemax(int r, int c, int dr, int dc, int n) {
    int m = 0;

    if (deb) cout << "linemax(" << r << ',' << c << ',' << dr << ',' << dc << ',' << n << ")=";
    for (int i = 0; i < n; i++) {
        if (!ml[r][c]) m = max(m, l[r][c]);
        r += dr, c += dc;
    }
    if (!m) m = amax;
    
    if (deb) cout << m << endl;
    return m;
}

void update() {
    int i, j, lmin = amax;
    
    for (i = 0; i < n; i++) for (j = 0; j < m; j++) {
        if (!ml[i][j]) lmin = min(lmin, l[i][j]);
    }
    if (deb) cout << "lmin=" << lmin << endl;
    for (i = 0; i < n; i++) if (linemax(i, 0, 0, 1, m) == lmin) cr[i] = 100;
    for (i = 0; i < m; i++) if (linemax(0, i, 1, 0, n) == lmin) cc[i] = 100;
}

void mow(int r, int c, int dr, int dc, int n) {
    if (deb) cout << "mow(" << r << ',' << c << ',' << dr << ',' << dc << ',' << n << ')' << endl;
    for (int i = 0; i < n; i++) {
        if (!ml[r][c]++) ; //cr[r]++, cc[c]++;
        r += dr, c += dc;
    }
}

int main() {
    int nt, it;

    cin >> nt;
    for (it = 1; it <= nt; it++) {
        int i, j;

        cin >> n >> m;
        for (i = 0; i < n; i++) for (j = 0; j < m; j++) {
            cin >> l[i][j];
            fill(ml[i], ml[i] + m, false);
        }
        fill(cr, cr + n, 0);
        fill(cc, cc + m, 0);
        fill(vr, vr + n, false);
        fill(vc, vc + m, false);

        bool change;
        int nm = 0;

        do {
            update();
            change = false;
            //for (i = 0; i < n; i++) cout << cr[i] << ' '; cout << endl;
            for (i = 0; i < n; i++) if (cr[i] >= 100) if (!vr[i]++) mow(i, 0, 0, 1, m), change++, nm++;
            //for (i = 0; i < m; i++) cout << cc[i] << ' '; cout << endl;
            for (i = 0; i < m; i++) if (cc[i] >= 100) if (!vc[i]++) mow(0, i, 1, 0, n), change++, nm++;
        } while (change);
        
        cout << "Case #" << it << ": " << (nm == n + m ? "YES" : "NO") << endl;
    }
}
