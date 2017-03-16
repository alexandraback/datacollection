#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <boost/foreach.hpp> //BOOST_FOREACH( single, sequence ) {}
#include <algorithm>
#include <set>

//############################################################################

//#include <rapidcheck.h>

/*
rc::check("Test du test",
			[](const string s){ RC_ASSERT(process(s) == 1); });
*/
// rc::check("Test", [](){ const auto i = *rc::gen::inRange(0, 10); return i < 10 && i >= 0; });
//  https://github.com/emil-e/rapidcheck/blob/master/doc/generators_ref.md

//############################################################################

//#include <boost/multiprecision/cpp_int.hpp> //MULTIPRECISION
//#include <boost/algorithm/algorithm.hpp> //ALGORITHM
//#include <boost/sort/spreadsort/spreadsort.hpp> //TRI

//using namespace boost::multiprecision;
//using namespace boost::algorithm;
//using namespace boost::spreadsort;

using namespace std;

//###########################################################################

typedef struct expr expr;
struct expr {
    string s1;
    string s2;
    };


int process(vector<expr> v) {
    int N = v.size();
    int counter = 0;
    vector<int> result(N, 2);
	set<string> usedG;
	set<string> usedD;

    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            if (j == i)
                continue;

            if (v[j].s1 == v[i].s1) {
                if (result[j] == 2)
                    result[j] = 1;
                else if (result[j] == -1)
                    result[j] = 0;
                }

            if (v[j].s2 == v[i].s2) {
                if (result[j] == 2)
                    result[j] = -1;
                else if (result[j] == 1)
                    result[j] = 0;
                }
            }
        }
	for(int i = 0 ; i < N ; i++){
		if(result[i] == 0){
			usedG.insert( "G"+v[i].s1);
			usedD.insert( "D"+v[i].s2);
		}
	}
	for(int i = 0 ; i < N ; i++){
		if(result[i] != 0){
			usedG.erase("G"+v[i].s1);
			usedD.erase("D"+v[i].s2);
		}
	}
	return count(result.begin(), result.end(), 0)-max(usedG.size(), usedD.size());
    }

int main() {
    string s;
    int i = 1, T, N;
    vector<expr> v;
    cin >> T;

    for (int l = 0 ; l < T ; l++) {
        cin >> N;
        v.resize(N);

        for (int j = 0 ; j < N ; j++) {
            cin >> v[j].s1 >> v[j].s2;
            }

        cout << "Case #" << i++ << ": " << process(v) << endl;
        }

    return 0;
    }
