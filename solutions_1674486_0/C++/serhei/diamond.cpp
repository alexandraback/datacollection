/* Google Code Jam Round 1C - Diamond Inheritance */

#include <iostream>
#include <cstdio>

#include <vector>
#include <set>
#include <queue>

using namespace std;

// #define DEBUG

int main() {
        int T; cin >> T;
        for (int cT = 1; cT <= T; cT++) {
                int N; cin >> N;

                /* items in child[i] inherit from i */
                vector<set<int> > child(N);
                /* item i inherits from items in parent[i] */
                vector<set<int> > parent(N);
                /* following i to root of hierarchy gives members of root[i] */
                queue<int> roots;
                vector<set<int> > root(N);

                for (int i = 0; i < N; i++) {
                        int M; cin >> M;
                        if (M == 0) {
                                // cerr << "INIT_ROOT " << (i+1) << endl;
                                /* class i does not inherit from anyone */
                                roots.push(i);
                                root[i].insert(i);
                                continue;
                        }
                        for (int j = 0; j < M; j++) {
                                int K; cin >> K; K--;
                                child[K].insert(i);
                                parent[i].insert(K);
                        }
                }

                vector<bool> done(N, false);

                /* repeatedly take and 'delete' roots: */
                bool found = false;
                while (!roots.empty()) {
                        int i = roots.front(); roots.pop();

                        /* propagate root[i] to children of i */
                        for (set<int>::iterator it = child[i].begin();
                             it != child[i].end(); it++) {
                                /* check if *it is a root with deletion of i */
                                parent[*it].erase(i);
                                if (parent[*it].empty()) roots.push(*it);

                                /* propagate root[i] to *it */
                                for (set<int>::iterator jt = root[i].begin();
                                     jt != root[i].end(); jt++) {
                                        if (root[*it].count(*jt) > 0) {
                                                /* existing path from root */
                                                found = true;
                                                goto done;
                                        }

                                        root[*it].insert(*jt);
                                }
                        }
                }

#ifdef DEBUG
                /* if answer is no, this shows results */
                for (int i = 0; i < N; i++) {
                        cerr << (i+1) << ": ";
                        for (set<int>::iterator it = root[i].begin();
                             it != root[i].end(); it++) {
                                cerr << ((*it)+1) << " ";
                        }
                        cerr << endl;
                }
#endif

        done:
                printf("Case #%d: %s\n", cT, found ? "Yes" : "No");
        }
}
