/************************************************
 *Author        :mathon
 *Created Time  :六  4/16 09:06:15 2016
 *Problem class:
*************************************************/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stack>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
vector<int> vi;
#define xx first
#define yy second
#define sa(n) scanf("%d", &(n))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define vep(c) for(decltype((c).begin() ) it = (c).begin(); it != (c).end(); it++)
#define pr(x) cout << #x << " " << x << " "
#define prln(x) cout << #x << " " << x << endl
const int mod = int(1e9) + 7, INF = 0x3f3f3f3f, maxn = 1e5 + 12;



int main(void)
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for (int Cas = 1; Cas <= T; Cas++) {
        string str;
        deque<char> ans;
        cin >> str;
        ans.push_back(str[0]);
        for (int i = 1; i < (int)str.size(); i++) {
            char c = str[i];
            if(c >= ans.front()) {
                ans.push_front(c);
            } else ans.push_back(c);
        }
        printf("Case #%d: ", Cas);
        while(!ans.empty()) {
            printf("%c", ans.front());
            ans.pop_front();
        }
        printf("\n");
    }
    return 0;
}
