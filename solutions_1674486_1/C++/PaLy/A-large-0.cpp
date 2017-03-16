#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstring>
#include <climits>

#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <forward_list>

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <cmath>

#include <utility>

using namespace std;

#define FOR(i,n1,n2) for(int i = n1; i < n2; ++i)
#define FORD(i,n1,n2) for(int i = n1; i >= n2; --i)
#define FORE(e,c) for(auto& e : c)
#define SZ(i) (int) i.size()
#define PB push_back
#define MT make_tuple
#define g(c,i) get<i>(c)

int main() {
    int t;
	scanf("%d\n",&t);
	FOR(tt,1,t+1) {
		cout << "Case #" << tt << ": ";

        int n;
        cin >> n;
        vector<vector<int>> v(n);
        FOR(i,0,n) {
            int p;
            cin >> p;
            int x;
            FOR(j,0,p) { cin >> x; v[i].PB(x-1); }
        }

        bool ok=false;

        FOR(ii,0,n) {
            vector<bool> was(n,0);
            was[ii]=1;

            priority_queue<int> q;
            q.push(ii);
            while(!q.empty()) {
                int cur=q.top();
                q.pop();
                FOR(i,0,SZ(v[cur])) {
                    if (!was[v[cur][i]]) {
                        was[v[cur][i]]=1;
                        q.push(v[cur][i]);
                    } else {
                        ok=true;
                        goto next;
                    }
                }
            }
        }

        next:;
        if (ok) cout << "Yes"; else cout << "No";
		cout << endl;
	}
    return 0;
}

