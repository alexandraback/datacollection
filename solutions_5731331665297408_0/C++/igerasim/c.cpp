#include <iostream>
#include <iomanip>
#include <vector>
#include <array>
#include <algorithm>
#include <hash_map>
#include <string>
#include <map>
#include <set>
#include <queue>

#if 0
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
typedef int256_t lll;
typedef uint256_t ulll;
#endif

using namespace std;
using namespace std::tr1;
using namespace stdext;

typedef __int64 ll;
typedef unsigned __int64 ull;

int T, N, M;
map<int, list<int> > g;
int zip[100];

string solve(int r, set<int> p) {
    list<int> adj = g[r];
    vector<pair<int, int> > azip;
    for (list<int>::iterator it = adj.begin(); it != adj.end(); ++it) {
        if (p.find(*it) != p.end()) continue;
        azip.push_back(make_pair(zip[*it], *it));
    }
    sort(azip.begin(), azip.end());
    string s1;
    p.insert(r);
    for (vector<pair<int, int> >::iterator it = azip.begin(); it != azip.end(); ++it) {
        s1 += solve(it->second, p);
    }
    char buff[16];
    sprintf(buff, "%05d", zip[r]);
    return string(buff) + s1;
}

int main(int argc, char* argv[]) {
    cin >> dec >> T;
    for (int t = 0; t != T; ++t) {
        g.clear();
        cout << "Case #" << (t + 1) << ": ";
        cin >> N >> M;
        for (int n = 0; n != N; ++n) {
            cin >> zip[n + 1];
        }
        for (int m = 0; m != M; ++m) {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int min_zip_n = 1;
        for (int n = 1; n <= N; ++n)
            if (zip[min_zip_n] > zip[n])
                min_zip_n = n;
        string s = solve(min_zip_n, set<int>());
        cout << s << "\n";
        cerr << "Done #" << (t + 1) << std::endl;
    }
    return 0;
}
