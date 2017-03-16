#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

bool mark(const vector<vector<unsigned int> >& neighbours, vector<bool>& marked, const unsigned int currentIndex) {
    if (marked[currentIndex]) return true;
    else {
        marked[currentIndex] = true;
        for (unsigned int i=0;i<neighbours[currentIndex].size();++i) {
            if (mark(neighbours,marked,neighbours[currentIndex][i])) return true;
        }
        return false;
    }
}

bool test(const vector<vector<unsigned int> >& neighbours, vector<bool>& seen, const unsigned int currentIndex) {
    unsigned int N = neighbours.size();
    vector<bool> marked(N,false);
    bool result = mark(neighbours,marked,currentIndex);
    for (unsigned int i=0;i<N;++i) {
        if (marked[i]) seen[i] = true;
    }
    return result;
}

void main_1C_A() {
    unsigned int T;

    cin >> T;
    for (unsigned int i=0;i<T;++i) {
        unsigned int N;
        vector<vector<unsigned int> > neighbours;

        cin >> N;
        neighbours.resize(N);

        for(unsigned int j=0;j<N;++j) {
            unsigned int nNeighbours;
            cin >> nNeighbours;
            neighbours[j].resize(nNeighbours);
            for (unsigned int k=0;k<nNeighbours;++k) {
                cin >> neighbours[j][k];
                --neighbours[j][k];
            }
        }

        bool diamond = false;
        vector<bool> seen(N,false);
        unsigned int nextIndex = 0;
        while (nextIndex < N) {
            if (test(neighbours,seen,nextIndex)) {
                diamond = true;
                break;
            }
            nextIndex = N;
            for (unsigned int j=0;j<N;++j) {
                if (!seen[j]) {
                    nextIndex = j;
                    break;
                }
            }
        }

        cout << "Case #" << (i+1) << ": " << (diamond?"Yes":"No") << endl;
    }
}
