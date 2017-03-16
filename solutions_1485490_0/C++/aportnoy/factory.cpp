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

template <typename T>
ostream& operator<<(ostream& os, const std::vector<T>& v) {
    for (int i = 0; i < v.size() - 1; ++i) {
        os << v[i] << " , ";
    }
    if (v.size() > 0) {
        os << v[v.size() - 1 ];
    }
    return os;
}

struct toys {

    std::vector<long int> boxn;
    std::vector<int> boxt;
    std::vector<long int> toyn;
    std::vector<int> toyt;

    toys(const std::vector<long int>& _boxn,
         const std::vector<int>& _boxt,
         const std::vector<long int>& _toyn,
         const std::vector<int>& _toyt)
    : boxn(_boxn), boxt(_boxt), toyn(_toyn), toyt(_toyt) {}

    long int solve()
    {
        if (boxn.empty() || toyn.empty()) {
            return 0;
        }
        if (boxt.back() == toyt.back()) {
            long int match = min(boxn.back(),toyn.back());
            if (boxn.back() == match) {
                boxt.pop_back();
                boxn.pop_back();
            } else {
                boxn.back() -= match;
            }
            if (toyn.back() == match) {
                toyt.pop_back();
                toyn.pop_back();
            } else {
                toyn.back() -= match;
            }
            return match + toys(boxn,boxt,toyn,toyt).solve();
        } else {
            return std::max(
                    toys(boxn,boxt,toyn,toyt).pop_boxes().solve(),
                    toys(boxn,boxt,toyn,toyt).pop_toys().solve()
            );
        }
    }

    toys& pop_boxes() {
        boxt.pop_back();
        boxn.pop_back();
        return *this;
    }

    toys& pop_toys() {
        toyt.pop_back();
        toyn.pop_back();
        return *this;
    }

};

int main(int argc, char *argv[]) {

    ifstream in;
    ofstream out;
 
    in.open(argv[1]);
    out.open(argv[2]);
    
    int T;
    in >> T;
    cout << T << endl;
    for (int i = 0; i < T; ++i) {
        int N, M;
        in >> N >> M;
        cout << N << " " << M << endl;
        std::vector<long int> boxn(N);
        std::vector<int> boxt(N);
        std::vector<long int> toyn(M);
        std::vector<int> toyt(M);
        for (int j = 0; j < N; ++j) {
            in >> boxn[N-1-j];
            in >> boxt[N-1-j];
        }
        for (int j = 0; j < M; ++j) {
            in >> toyn[M-1-j];
            in >> toyt[M-1-j];
        }
        cout << boxn << endl;
        cout << boxt << endl;
        cout << toyn << endl;
        cout << toyt << endl;
        out << "Case #" << i+1 << ": " << toys(boxn,boxt,toyn,toyt).solve() << endl;
    }

    in.close();
    out.close();
    
    return 0;

}
