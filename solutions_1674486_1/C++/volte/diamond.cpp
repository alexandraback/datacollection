#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

typedef map<int, set<int> > int_graph;

bool diamond_from(int_graph& inherits, int cls) {
    map<int, bool> marked;
    queue<int> to_visit;

    to_visit.push(cls);
    while (!to_visit.empty()) {
        int next = to_visit.front();
        to_visit.pop();

        if (marked[next]) return true;
        for (set<int>::iterator it = inherits[next].begin(); it != inherits[next].end(); ++it) {
            to_visit.push(*it);
        }
        marked[next] = true;
    }

    return false;
}

bool diamond(int_graph& inherits) {
    for (int_graph::iterator it = inherits.begin(); it != inherits.end(); ++it) {
        if (diamond_from(inherits, (*it).first))
            return true;
    }
    return false;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Usage:\n" << argv[0] << " [input]";
        exit(1);
    }

    ifstream file;
    file.open(argv[1]);
    if (!file.is_open()) {
        cout << "Failed to open file " << argv[1] << "\n";
        exit(1);
    }

    int cases;
    file >> cases;

    for (int i = 0; i < cases; ++i) {
        int classes;
        map<int, set<int> > inherits;

        file >> classes;
        for (int j = 1; j <= classes; ++j) {
            int inherit_count, parent;
            set<int> parents;
            file >> inherit_count;
            for (int k = 0; k < inherit_count; ++k) {
                file >> parent;
                parents.insert(parent);
            }
            inherits[j] = parents;
        }

        cout << "Case #" << i + 1 << ": " << (diamond(inherits) ? "Yes" : "No") << "\n";
    }

    return 0;
}

