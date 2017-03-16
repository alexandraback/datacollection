#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vs> vvs;

#define pb(x) push_back(x)
#define all(c) (c).begin(),(c).end()
#define ins(c) inserter((c),(c).begin())
#define mp(x,y) make_pair((x),(y))
#define mt(x,y,z) make_tuple((x),(y),(z))
#define INF (1e9)
const double PI = 2 * acos(0.0);

ostream& operator<<(ostream& out, vi v)
{
    for (auto a: v)
        out << a << " ";
    return out;
}

#define maxn (1000005)

int rev(int n)
{
    stringstream ss;
    ss << n;
    string str = ss.str();
    reverse(all(str));
    ss.clear();
    ss.str("");
    ss << str;
    int ans;
    ss >> ans;
    return ans;
}

int main()
{
    int T, cas = 0;

    vi D(maxn, 0);
    vvi P(maxn, vi());

    for (int i = 2; i < maxn; i++) { 
        P[i].pb(i-1);
        int s = rev(i);
        if (s > i && s < maxn) {
            P[s].pb(i);
        }
    }

    D[1] = 1;

    for (int i = 2; i < maxn; i++) {
        D[i] = INF;
        for (auto s: P[i]) {
            D[i] = min(D[i], D[s] + 1);
        }
    }

    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << "Case #" << ++cas << ": " << D[n] << endl;
    }

	return 0; 
}
