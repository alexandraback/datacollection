#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Class {
public:
    vector<int> children;
    
    bool isDiamont(Class * classes) {
        set<int> p;
        return getPs(p, classes);
    }
    bool getPs(set<int>& p, Class * classes) {
        for (int i=0; i<children.size(); i++) {
            if (p.find(children[i]) != p.end()) {
                return true;
            }
            p.insert(children[i]);
            if (classes[children[i]].getPs(p, classes)) {
                return true;
            }
        }
        return false;
    }
};


int main() {
    int T;
    cin >> T;
    
    for (int t=0; t<T; t++) {
        cout << "Case #" << (t+1) << ": ";
        int N;
        cin >> N;
        Class classes[N];
        for (int a=0; a<N; a++) {
            classes[a].children.empty();
        }
        
        for (int cl=0; cl<N; cl++) {
            int n_parents;
            cin >> n_parents;
            for (int c=0; c<n_parents; c++) {
                int parent;
                cin >> parent;
                parent--;
                classes[parent].children.push_back(cl);
            }
        }
        bool found = false;
        for (int cl=0; cl<N; cl++) {
            if (classes[cl].children.size() > 1) {
                if (classes[cl].isDiamont(classes)) {
                    found = true;
                    break;
                }
            }
        }
        if (found)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}



