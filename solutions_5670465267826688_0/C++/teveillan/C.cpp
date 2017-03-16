#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

#define FOR(i,l,r)  for(int i=(l); i<=(r); ++i)
#define REP(i,r)    for(int i=0; i<(r); ++i)
#define DWN(i,r,l)  for(int i=(r);i>=(l);--i)

#define pb push_back

typedef long long ll;
typedef pair<int, int>pii;

int f[4][4]= {
    {0, 1, 2, 3},
    {1, 0, 3 ,2},
    {2, 3, 0, 1},
    {3, 2, 1, 0}
};

bool g[4][4] = {
    {0, 0, 0, 0},
    {0, 1, 0, 1},
    {0, 1, 1, 0},
    {0, 0, 1, 1}
};


int main() {
    freopen("C-small-attempt3.in", "r", stdin);
    freopen("C-small-out", "w", stdout);
    int casnum, casid = 0;
    cin >> casnum;
    while(casnum--) {
         ll len, x;
         cin >> len >> x;
         vector<int>vec, tmp_vec;
         string str;
         cin >> str;
         REP(i, len) {
             if(str[i] == 'i')  tmp_vec.pb(1);
             else if(str[i] == 'j') tmp_vec.pb(2);
             else tmp_vec.pb(3);
         }

         if(x > 24)  {
             x = (x - 24) % 4 + 24;
         }

         REP(i, x)  vec.insert(vec.end(), tmp_vec.begin(), tmp_vec.end());

         bool flag = 0;
         int tmp = 0;
         bool ans = 0;
             set<pair<int, bool> > s;

             REP(i, vec.size()) {
                 flag ^= g[tmp][vec[i]];
                 tmp = f[tmp][vec[i]];

                 if(i != vec.size() - 1 && flag == 0 && tmp == 3 && s.find(make_pair(0, 1)) != s.end()) {
                     ans = 1;
                 }
                 s.insert(make_pair(flag, tmp));
             }
        if(tmp != 0 || flag != 1)   ans = 0;
         printf("Case #%d: %s\n", ++casid, ans?"YES":"NO");
    }
    return 0;
}

