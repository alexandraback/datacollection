#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int idx;
    int count;
    vector<node*> parents;
};

typedef vector<node>::iterator nit;

bool navigate(node& n) {
    //cout << "Visisting " << n.idx << " with count " << n.count << endl;
    n.count++;
    if (n.count > 1)
        return true;
    else {
        for (vector<node*>::iterator a = n.parents.begin(); a != n.parents.end(); a++) {
            if (navigate(*(*a)))
                return true;
        }
    }

    return false;
}

void doCase(int caseNum) {
    int N;
    cin >> N;

    vector<node> classes(N);
    for (int i = 0; i < N; i++) {
        int M;
        cin >> M;
        node& now = classes[i];
        now.idx = i;
        for (int j = 0; j < M; j++) {
            int p;
            cin >> p;
            now.parents.push_back(&classes[p-1]);
        }
    }

    bool diamond = false;
    for (nit a = classes.begin(); a != classes.end(); a++) {
        for (nit b = classes.begin(); b != classes.end(); b++) {
            (*b).count = 0;
        }

        //cout << "Starting " << (*a).idx << endl;
        if (navigate(*a)) {
            diamond = true;
            break;
        }
    }

    cout << "Case #" << caseNum << ": " << (diamond ? "Yes" : "No") << endl;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        doCase(i+1);
    }
}
