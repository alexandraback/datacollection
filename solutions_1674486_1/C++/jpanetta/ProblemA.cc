////////////////////////////////////////////////////////////////////////////////
// ProblemA.cc
////////////////////////////////////////////////////////////////////////////////
/*! @file
//        Solves Google Code Jam 2012 Round 1C Problem A
*/ 
//  Author:  Julian Panetta (jpanetta), julian.panetta@gmail.com
//  Company:  New York University
//  Created:  05/06/2012 5:00:00
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <iomanip>

using namespace std;
typedef unsigned int uint;

////////////////////////////////////////////////////////////////////////////////
/*! Program entry point
//  @param[in]  argc    Number of arguments
//  @param[in]  argv    Argument strings
//  @return     status  (0 on sucess)
*///////////////////////////////////////////////////////////////////////////////
int main(int argc, const char *argv[])
{
    int numTests;
    cin >> numTests;
    for (int t = 1; t <= numTests; ++t)  {
        unsigned int N;
        cin >> N;
        vector<list<int> > adj(N, list<int>());
        for (unsigned int i = 0; i < N; ++i) {
            unsigned int M;
            cin >> M;
            for (unsigned int j = 0; j < M; ++j) {
                int adj_j;
                cin >> adj_j;
                --adj_j;
                adj[i].push_back(adj_j);
            }
        }

        cout << "Case #" << t << ": ";
        for (unsigned int D = 0; D < N; ++D) {
            // Compute number of paths from D into each vertex in topological sort order
            vector<int> numPaths(N, 0);
            vector<int> inBlockers(N, 0);
            for (unsigned int i = 0; i < N; ++i) {
                for (list<int>::iterator it = adj[i].begin(); it != adj[i].end(); ++it)
                    ++inBlockers[*it];
            }

            queue<int> ready;
            for (unsigned int i = 0; i < N; ++i) {
                if (inBlockers[i] == 0) {
                    ready.push(i);
                    numPaths[i] = 0;
                }
            }

            // Only count paths from D
            numPaths[D] = 1;

            while (!ready.empty()) {
                int s = ready.front();
                ready.pop();
                for (list<int>::iterator it = adj[s].begin(); it != adj[s].end(); ++it) {
                    int d = *it;
                    numPaths[d] += numPaths[s];
                    if (numPaths[d] > 1) {
                        cout << "Yes" << endl;
                        goto done;
                    }
                    if(--inBlockers[d] == 0)
                        ready.push(d);
                }
            }
        }

        cout << "No" << endl;
done:
        continue;
    }

    return 0;
}
