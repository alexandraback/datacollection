#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T;
int N; //number of classes
int M[1001]; // number of i's parent classes
int A[1001][11]; // adjacency list A[i][...] is the list of parents of A[i]
bool reachable_from[1001][1001];
//bool is_starting_node[1001];
vector<int> pending_nodes;

bool diamond = false;

void reset_data()
{
    for (int i=0; i<1001; ++i) M[i] = 0;
    for (int i=0; i<1001; ++i)
    {
        //is_starting_node[i] = true;
        for (int j=0; j<11; ++j)
            A[i][j] = 0;

        for (int j=0; j<1001; ++j)
            reachable_from[i][j] = false;
    }

}


/*
void find_starting_nodes()
{
    starting_nodes.clear();
    for (int i=1; i<=1000; ++i)
        if (is_starting_node[i]) pending_nodes.push_back(i);
}
*/

void go(int initial_node, int current_node)
{
    if (reachable_from[initial_node][current_node]) {
        diamond = true;
        return;
    }
    reachable_from[initial_node][current_node] = true;
    for(int i=0; i<M[current_node]; i++) {
        go(initial_node, A[current_node][i]);
        if (diamond) return;
    }
}


int main()
{
    cin >> T;
    for (int test_case=1; test_case<=T; ++test_case)
    {
        reset_data();
        cin >> N;
        for (int i=1; i<=N; ++i) {
            cin >> M[i];
            for (int j=0; j<M[i]; ++j) {
                int node;
                cin >> node;
                A[i][j] = node;
            }
        }

        diamond = false;
        for (int i=1; i<=N; ++i) {
            pending_nodes.clear();
            go(i, i);
        }

        cout << "Case #" << test_case << ": " << (diamond ? "Yes" : "No") << endl;
    }

}

