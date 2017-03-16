#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <cassert>
#include <cstring>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <climits>
#include <iomanip>
using namespace std;
typedef long long ll;
char tr[105], sr[105];
int slen, mxc = 0;
long long cnt (char *t, char *s) {
    int l1 = strlen(s);
    int l2 = strlen(t);
    int res = 0;
    for (int i = 0; i <= l1 - l2; i++) {
        int j;
        for (j = 0; j < l2; j++)
            if (t[j] != s[i + j])
                break;
        if (j == l2) res++;
    }
    if (res > mxc) mxc = res;
    return res;
}
long long rec (char *s, int idx, int n) {
    int res = 0;
    if (idx >= n) {
        return cnt(tr, s);
    }
    for (int i = 0; i < slen; i++) {
        s[idx] = sr[i];
        res += rec(s, idx + 1, n);
    }
    return res;
}
int main()
{
    int T;
    
    ifstream fp ("/Users/aviral.gupta/Downloads/in.txt");
    ofstream ofp ("/Users/aviral.gupta/Downloads/out.txt");
    
    fp >> T;
    
    for(int k = 1; k <= T; k++) {
        long long kk, l, s;
        double res = 0.0;
        char tmp[105];
        fp >> kk >> l >> s;
        fp >> sr >> tr;
        slen = strlen(sr);
        mxc = 0;
        long long ct = rec (tmp, 0, s);
        cout << ct << endl;
        
        int b = 1;
        for (int i = 0; i < s; i++)
            b = b * kk;
        res = (double)mxc - (double)ct / (double)b;

        ofp << "Case #" << k << ": " <<  setprecision(11) << res << endl;
    }
    fp.close();
    ofp.close();
    cout << "done" << endl;
    return 0;
}
