#include <algorithm>
#include <cassert>
#include <deque>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
enum vertexState {Unexplored, Explored};

// Tables for BFS
vertexState* vState;
unsigned int* parrent;
unsigned int** ResGF;

deque<unsigned int> BFSQueue;

void BFS (unsigned int** const G, unsigned int source, unsigned int n, unsigned int t);
bool FordFulkerson (unsigned int n, unsigned int s, unsigned int t);

int main() {
    unsigned int N, M, T, c, **C;
    bool found;

    // Allocate edge-capacity table. (Directed Weighted Graph)
    C = new (nothrow) unsigned int* [1001];
    assert(C != NULL);

    // Allocate residual graph flow.
    ResGF = new (nothrow) unsigned int* [1001];
    assert(ResGF != NULL);

    for (unsigned int i = 0; i < 1001; ++i) {
        C[i] = new (nothrow) unsigned int [1001];
        assert(C[i] != NULL);

        ResGF[i] = new (nothrow) unsigned int [1001];
        assert(ResGF[i] != NULL);
    }

    vState = new (nothrow) vertexState [1001];
    parrent = new (nothrow) unsigned int [1001];

    cin >> T;
    for (unsigned int i = 1; i < T + 1; ++i) {
        cin >> N;
        for (unsigned int j = 0; j < N; ++j) {
            cin >> M;
            fill(C[j], C[j] + N, 0);
            fill(ResGF[j], ResGF[j] + N, 0);
            for (unsigned int k = 0; k < M; ++k) {
                cin >> c;
                --c; /* Fix for 0-array */
                ResGF[j][c] = C[j][c] = 1; // Capacity = 1 && No initial flow
            }
        }
        
        found = false;
        for (unsigned int j = 0; !found && j < N; ++j) {
            for (unsigned int k = 0; k < N; ++k) {
                if (j == k) {
                    continue;
                }
                for (unsigned int l = 0; l < N; ++l) {
                    copy(C[l], C[l] + N, ResGF[l]);
                }
                if (FordFulkerson(N, k, j)) {
                    found = true;
                    break;
                }
            }   
        }
        cout << "Case #" << i << ((found) ? ": Yes" : ": No") << endl;
    }

    // Release memory.
    for (unsigned int i = 0; i < 1001; ++i) {
        delete [] C[i];
        delete [] ResGF[i];
    }

    delete [] C;
    delete [] ResGF;
    delete [] vState;
    delete [] parrent;
}

void BFS (unsigned int** const G, unsigned int source, unsigned int n, unsigned int t) {

    // Null-initialize
    BFSQueue.clear();
    fill(vState, vState + n, Unexplored);
    fill(parrent, parrent + n, n); // GUARD value : n : NULL (vertex range [0..n-1])

    vState[source] = Explored;
    BFSQueue.push_back(source);

    unsigned int v; // next-to-be-processed vertex
    while (!BFSQueue.empty()) {
        v = BFSQueue.front();
        if (v == t) // path to target vertex has been constructed
            return;
        for (unsigned int i = 0; i < n; ++i) // Visit neighbours of v
            if ((vState[i] == Unexplored) && (G[v][i] != 0)) {
                    vState[i] = Explored;
                    parrent[i] = v;
                    BFSQueue.push_back(i);
            }

        BFSQueue.pop_front();
    }
    return;
}

bool FordFulkerson (unsigned int n, unsigned int s, unsigned int t) {

    /** Ford-Fulkerson! */
    unsigned int flow = 0, minCap;

    // Improve flow, while there is an augmenting path
    for (;;) {
        BFS(ResGF, s, n, t); /* FIXME */
        if (parrent[t] == n) // No path reaches sink
            break;
        else { // Flow augmentation possible

            // Find minimum residual capacity in s-t path
            minCap = ResGF[parrent[t]][t];
            for (unsigned int i = parrent[t]; i != s; i = parrent[i])
                minCap = min(minCap, ResGF[parrent[i]][i]);

            // Update flow in the edges of augmenting path.
            for (unsigned int i = t; i != s; i = parrent[i]) {
                ResGF[parrent[i]][i] -= minCap;
                ResGF[i][parrent[i]] += minCap;
            }

            flow += minCap;
        }
    }

    /** Results! */

    // Total flow.
//A_    cout << "Flow between " << s << " and " << t << " :" << flow << endl;
    if (flow > 1) {
        return true;
    }
    return false;
}
