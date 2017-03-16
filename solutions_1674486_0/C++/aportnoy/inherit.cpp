#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <queue>
#include <algorithm>
#include <functional>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <list>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

using namespace std;
using namespace boost::numeric::ublas;

ostream& operator<<(ostream& os, const std::vector<int>& v) {
    for (int i = 0; i < v.size() - 1; ++i) {
        os << v[i] << " , ";
    }
    if (v.size() > 0) {
        os << v[v.size()];
    }
    return os;
}

struct inheritance {

    int n;
    const matrix<int>& graph;

    inheritance(int _n, const matrix<int>& _graph)
        : n(_n), graph(_graph) {}

    bool solve() {

        // find nodes without edge in
        std::vector<int> terms;
        for (int t = 0; t < n; ++t) {
            bool inh = false;
            for (int f = 0; f < n; ++f) {
                if (graph(f,t) != 0) {
                    inh = inh || true;
                }
            }
            if (!inh) {
                terms.push_back(t);
            }
        }
        // cout << terms << endl;

        while (!terms.empty()) {

            std::vector<bool> seen(n);
            std::fill(seen.begin(),seen.end(),false);

            int start = terms.back();
            terms.pop_back();

            std::vector<int> path;
            path.push_back(start);

            while (!path.empty()) {
                int next = path.back();
                path.pop_back();
                if (seen[next]) {
                    return true;
                } else {
                    seen[next] = true;
                    for (int parent = 0; parent < n; ++parent) {
                        if (graph(next,parent) != 0) {
                            path.push_back(parent);
                        }
                    }
                }
            }

        }

        return false;

    }

};

int main(int argc, char *argv[]) {

    ifstream in;
    ofstream out;
 
    in.open(argv[1]);
    out.open(argv[2]);
    
    int T;
    in >> T;
    for (int i = 0; i < T; ++i) {
        int N;
        in >> N;
        matrix<int> graph = zero_matrix<int>(N,N);
        for (int j = 0; j < N; ++j) {
            int M;
            in >> M;
            for (int k = 0; k < M; ++k) {
                int target;
                in >> target;
                graph(j,target-1) = 1;
            }
        }
        // cout << graph << endl;
        if (inheritance(N,graph).solve()) {
            out << "Case #" << i+1 << ": " << "Yes" << endl;
        } else {
            out << "Case #" << i+1 << ": " << "No" << endl;
        }
    }

    in.close();
    out.close();
    
    return 0;

}
