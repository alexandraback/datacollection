#include <cassert>
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <utility>
#include <set>

using namespace std;

int gcd(int m, int n) {
    return m==0 ? n : gcd(n%m, m);
}
bool doit(int di, int dj, int m, int n, int xi, int xj, int D, set< pair<int, int> > &S) {
    int i = di*m;
    int j = dj*n;
    if (di & 1) {
        i += m - xi;
    } else {
        i += xi;
    }
    if (dj & 1) {
        j += n - xj;
    } else {
        j += xj;
    }
    
    int dr = i - xi;
    int dc = j - xj;
    if (dr*dr + dc*dc > D*D) {
        return false;
    }
    int sgnr = (dr<0 ? -1 : 1);
    int sgnc = (dc<0 ? -1 : 1);
    int g = gcd(sgnr*dr, sgnc*dc);
    dr /= g;
    dc /= g;
    S.insert(make_pair(dr, dc));
    return true;
}
int main() {
    cin.sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t=1; t<=T; ++t) {
        int m, n, D;
        cin >> m >> n >> D;
        int xi=-1, xj=-1;
        string s;
        getline(cin, s); // \n
        for (int i=0; i<m; ++i) {
            getline(cin, s);
            string::size_type p = s.find('X');
            if (p != string::npos) {
                xi = i - 1;
                xj = int(p) - 1;
            }
        }
        assert(xi != -1);
        m -= 2;
        n -= 2;
        m *= 2;
        n *= 2;
        xi = 2*xi + 1;
        xj = 2*xj + 1;
        D *= 2;
        int k = 0;
        set< pair<int, int> > S;
        while (1) {
            ++k;
            bool next = false;
            for (int di=-k; di<=k; di+=2*k) {
                for (int dj=-k; dj<=k; ++dj) {
                    if (doit(di, dj, m, n, xi, xj, D, S)) {
                        next = true;
                    }
                }
            }
            for (int dj=-k; dj<=k; dj+=2*k) {
                for (int di=-k+1; di<k; ++di) {
                    if (doit(di, dj, m, n, xi, xj, D, S)) {
                        next = true;
                    }
                }
            }
            if (!next) {
                break;
            }
        }
        
        cout << "Case #" << t << ": " << S.size() << '\n';
    }
	return 0;
}
