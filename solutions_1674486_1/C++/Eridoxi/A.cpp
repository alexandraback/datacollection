#include <cstdlib>
#include <climits>
#include <sstream>
#include <string>
#include <iostream>
#include <cstdio>

// STL
#include <algorithm>
#include <vector>
#include <map> // contains multimap
#include <set> // contains multiset
#include <queue> // contains priority_queue
#include <deque>
#include <list>
#include <stack>


using namespace std;

typedef struct _node {
    int id;
    int num_next;
    _node ** next;
    
    ~_node (){
        delete [] next;
    }
} node;

bool solve(node * nd, bool * mark, int N) {
    for  (int j = 0; j < nd->num_next; ++j) {
        node* nn = nd->next[j];
        if (mark[nn->id])
            return true;
        mark[nn->id] = true;
        if (solve(nn, mark, N))
            return true;
    }
    return false;
}

bool solve(node * nd, int N) {
    bool mark[N];
    for  (int j = 0; j < N; ++j) {
        mark[j] = false;
    }
    
    if (solve(nd, mark, N))
        return true;

    return false;
}

bool solve(int N, bool* roots, node * nd) {
    for  (int j = 0; j < N; ++j) {
        if (roots[j] && solve(&(nd[j]), N))
            return true;
    }
    return false;
}


int main() {
    int numcase, N, tmp, tmp2;

    //freopen("A-small.in", "r", stdin);
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);

    cin >> numcase;
    for (int i = 0; i < numcase; ++i) {
        cin >> N;
        node nodes[N];
        bool roots[N];
        for  (int j = 0; j < N; ++j) {
            nodes[j].id = j;
            roots[j] = true;
        }
        for  (int j = 0; j < N; ++j) {
            cin >> tmp;
            nodes[j].num_next = tmp;
            nodes[j].next = new node*[tmp];
            for (int l = 0; l < tmp; ++l) {
                cin >> tmp2;
                tmp2 -= 1;
                roots[tmp2] = false;
                nodes[j].next[l] = nodes + tmp2;
            }
        }
        cout << "Case #" << i + 1 << ": ";
        if (solve(N,roots, nodes)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
