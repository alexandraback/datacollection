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
int Coin[105], v;

void CountUnique(int *nway, int d) {
	int i, n, j, c;
	nway[0] = 1;

    int cn[105];
    for (int i = 0; i < d; i++)
        cn[i] = Coin[i];
    sort(cn, cn + d);
    for (int i = 0; i < d; i++)
        for (int j = v - 1; j >= 0; j--)
            if (nway[j])
                nway[j + cn[i]] = 1;
}
int cnt(int d) {
    int nway[1005] = {0}, idx;
    CountUnique(nway, d);
    for (idx = 1; idx <= v; idx++)
        if (nway[idx] == 0)
            break;
    if (idx == v + 1)
        return 0;
    int res = INT_MAX;
    for (int i = idx; i >= 1; i--) {
        Coin[d] = i;
        res = min(res, cnt(d + 1));
        if (res == 0) break;
    }
    return res + 1;
}
int main()
{
    int T;
    
    ifstream fp ("/Users/aviral.gupta/Downloads/in.txt");
    ofstream ofp ("/Users/aviral.gupta/Downloads/out.txt");
    
    fp >> T;
    int nway[1005] = {0};
    for(int k = 1; k <= T; k++) {
        long long res = 0, c, d;
        fp >> c >> d >> v;
        for (int i = 0; i < d; i++)
            fp >> Coin[i];
        
        if (c == 1) {
            res = cnt(d);
        }
    
        ofp << "Case #" << k << ": " << res << endl;
    }
    fp.close();
    ofp.close();
    cout << "done" << endl;
    return 0;
}
