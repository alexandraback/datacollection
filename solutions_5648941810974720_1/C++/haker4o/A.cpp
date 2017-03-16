#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>

#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int T, NT;
    int i, j;
    cin>>NT;
    for(T=1; T<=NT; ++T) {
        string s;
        cin>>s;
        int a[128];
        memset(a, 0, sizeof(a));
        vector<int> res;
        res.clear();
        res.resize(10, 0);
        for(i=0; i<s.size(); ++i) {
            a[s[i]]++;
            res[0] = a['Z'];
            res[2] = a['W'];
            res[4] = a['U'];
            res[6] = a['X'];
            res[8] = a['G'];
            res[1] = a['O'] - res[2] - res[4] - res[0];
            res[3] = a['H'] - res[8];
            res[5] = a['F'] - res[4];
            res[7] = a['S'] - res[6];
            res[9] = a['I'] - res[5] - res[6] - res[8];
        }
        string resS = "";
        for(i=0; i<10; ++i) {
            for(j=0; j<res[i]; ++j) {
                resS += ('0' + i);
            }
        }
        cout<<"Case #"<<T<<": "<<resS<<endl;
    }
    return 0;
}
