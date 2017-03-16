#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define pb push_back
#define mp make_pair

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define DWN(i,h,l) for(int i=(h);i>=(l);--i)
#define MEM(arr, v) memset(arr, v, sizeof(arr))

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> pii;

int f[1010][26];

char ret[1010];
int main()
{
	freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int casnum;
    cin >> casnum;
    FOR(casid, 1, casnum) {
        memset(f, 0, sizeof(f));
        string s;
        cin >> s;
        FOR(i, 1, s.size()) {
            REP(j, 26) f[i][j] += f[i-1][j];
            int c = s[i-1] - 'A';
            ++f[i][c];
        }
        int l = 0, r = s.size() - 1; DWN(i, s.size(), 1) {
             int c = s[i-1] - 'A';
             int flag = -1;
             DWN(j, 25, c + 1) if(f[i][j]) {
                flag = j;
                break;
             }

             if(flag != -1) ret[r--] = 'A' + c;
             else ret[l++] = 'A' + c;
        }
        ret[s.size()] = 0;
        printf("Case #%d: ", casid);

        cout << ret << endl;
    }

    return 0;
}

