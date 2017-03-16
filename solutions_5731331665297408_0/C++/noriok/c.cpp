#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

typedef vector<int> vi;

const int N = 10;


bool calc_1(int p, const vi& path, bool trip[][N], vi stack) {
    if (p == path.size()-1) return true;

    int node = path[p];
    int next = path[p+1];

    if (trip[node][next]) {        
        trip[node][next] = false;
        trip[next][node] = false;
        vi st = stack;
        st.push_back(node);

        bool ok = calc_1(p+1, path, trip, st);
        trip[node][next] = true;
        trip[next][node] = true;
        if (ok) return true;
    }

    while (!stack.empty()) {
        node = stack.back();
        stack.pop_back();
        if (trip[node][next]) {
            trip[node][next] = false;
            trip[next][node] = false;
            vi st = stack;
            st.push_back(node);
            
            bool ok = calc_1(p+1, path, trip, st);
            trip[node][next] = true;
            trip[next][node] = true;
            if (ok) return true;
        }
    }
    return false;
}


bool calc(const vi& path, bool trip[][N]) {
    vi stack;
    int node = path[0];
    return calc_1(0, path, trip, stack);
}

int main() {
    int ncases;
    scanf("%d", &ncases);


    for (int cc = 0; cc < ncases; cc++) {
        int n, m;
        scanf("%d %d", &n, &m);

        vi zips(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &zips[i]);
        }

        bool trip[N][N] = {};
        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            trip[a-1][b-1] = true;
            trip[b-1][a-1] = true;
        }

        vi path;
        for (int i = 0; i < n; i++) {
            path.push_back(i);
        }

        vi best;
        string ans = "";
        do {

            bool tmp[N][N];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    tmp[i][j] = trip[i][j];
                }
            }

            bool ok = calc(path, tmp);
            if (ok) {
                stringstream ss;
                for (int i = 0; i < path.size(); i++) {
                    // printf(" %d", path[i]+1);
                    ss << zips[path[i]];
                }
                // printf("\n");

                string s = ss.str();
                if (ans.length() == 0 || s < ans) ans = s;
            }
        } while (next_permutation(path.begin(), path.end()));

        printf("Case #%d: %s\n", cc+1, ans.c_str());

    }
}
