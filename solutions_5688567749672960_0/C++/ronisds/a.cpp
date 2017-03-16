#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <limits>
#include <iomanip>

#define INF 1000000000
#define Inf 1000000000000000000
#define mp make_pair
#define pb push_back
#define EPS 1e-9

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

#define MAXN 1000010

int pd[MAXN], n;

int main() {
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    int t;
    cin >> t;
    for(int cas = 1; cas <= t; ++cas)
    {
        memset(pd,-1,sizeof(pd));
        cin >> n;
        int a = n;
        pd[a] = 1;
        for(int i = n; i > 1; --i)
        {
            pd[i - 1] = (pd[i - 1] == -1) ? 1 + pd[i] : min(pd[i - 1], 1 + pd[i]);
            if (i % 10) {
                char num[20];
                int idx = 0, aa = i;
                while(aa) {
                    num[idx++] = (char)('0' + (int)(aa % 10));
                    aa /= 10;
                }
                aa = 0;
                for(int i = 0; i < idx; ++i)
                    aa = aa * 10 + (num[i] - '0');
                pd[aa] = (pd[aa] == -1) ? 1 + pd[i] : min(pd[aa], 1 + pd[i]);
            }
        }
        cout << "Case #" << cas << ": " << pd[1] << endl;

    }
    return 0;
}
