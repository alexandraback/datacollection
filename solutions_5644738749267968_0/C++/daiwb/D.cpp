#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

#define MAXN 10
#define _clr(x) memset(x,0xff,sizeof(int)*MAXN)

int match1[MAXN], match2[MAXN], mat[MAXN][MAXN];

int hungary(int m,int n,int mat[][MAXN],int* match1,int* match2){
	int s[MAXN],t[MAXN],p,q,ret=0,i,j,k;
	for (_clr(match1),_clr(match2),i=0;i<m;ret+=(match1[i++]>=0))
		for (_clr(t),s[p=q=0]=i;p<=q&&match1[i]<0;p++)
			for (k=s[p],j=0;j<n&&match1[i]<0;j++)
				if (mat[k][j]&&t[j]<0){
					s[++q]=match2[j],t[j]=k;
					if (s[q]<0)
						for (p=j;p>=0;j=p)
							match2[j]=k=t[j],p=match1[k],match1[k]=j;
				}
	return ret;
}

int doit1(vector<double> mm, vector<double> dd, int n) {
    REP(i,n) {
        REP(j,n) {
            if (mm[i] > dd[j]) mat[i][j] = 1;
            else mat[i][j] = 0;
        }
    }
    return hungary(n, n, mat, match1, match2);
}

int doit2(vector<double> mm, vector<double> dd, int n) {
    int res = 0;
    do {
        int win = 0;
        vector<int> used(n, false);
        REP(i,n) {
            bool found = false;
            int idx = -1;
            REP(j,n) {
                if (used[j]) continue;
                if (idx == -1) idx = j;
                if (dd[j] > mm[i]) {
                    found = true;
                    used[j] = true;
                    break;
                }
            }
            if (!found) {
                ++win;
                used[idx] = true;
            }
        }
        res = max(res, win);
    } while (next_permutation(mm.begin(), mm.end()));
    return res;
}

void run() {
    int n;
    cin >> n;
    vector<double> mm(n), dd(n);
    REP(i,n) cin >> mm[i];
    REP(i,n) cin >> dd[i];
    sort(mm.begin(), mm.end());
    sort(dd.begin(), dd.end());
    cout << doit1(mm, dd, n) << " " << doit2(mm, dd, n) << endl;
}

int main() {
    int k;
    cin >> k;
    FOR(c,1,k) {
        cout << "Case #" << c << ": ";
        run();
    }
    return 0;
}
