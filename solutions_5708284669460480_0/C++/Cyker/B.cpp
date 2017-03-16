#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define FOR(i,b,e) for(int (i)=(b);(i)<(int)(e);(i)++)
#define CFOR(i,b,e) for(int (i)=(b);(i)<=(int)(e);(i)++)
#define FOREACH(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define PI 3.1415926535897932384626433832795
#define INF 0x7FFFFFFF

int T;
int K, L, S;
string keys;
string target;
string buf;
double prob;
int ans_max;
double ans_exp;

int count(string buf)
{
    int cnt = 0;
    for (int i = 0;i < buf.size();i++) {
        if (buf.substr(i, L) == target) {
            cnt++;
        }
    }
    return cnt;
}

void dfs(string buf, int times)
{
    if (times == S) {
        int cnt = count(buf);
        ans_max = max(ans_max, cnt);
        ans_exp += pow(1.0 / K, S) * (double)(cnt);
    } else {
        for (int i = 0;i < K;i++) {
            string buf2 = buf + keys[i];
            dfs(buf2, times + 1);
        }
    }
}

int main(int argc, char **argv)
{
    cin >> T;
    for (int t = 0;t < T;t++) {
        cin >> K >> L >> S;
        cin >> keys;
        cin >> target;
        buf = "";
        prob = 0.0;
        ans_max = 0;
        ans_exp = 0.0;

        dfs(buf, 0);

        cout << "Case #" << t + 1 << ": ";
        cout << fixed << setprecision(7);
        cout << (double)(ans_max) - ans_exp;
        cout << endl;
    }

    return 0;
}

