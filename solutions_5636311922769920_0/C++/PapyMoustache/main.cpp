#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
//#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
//using namespace boost::multiprecision;
//int process(string N);

int main() {
	string s;
	int i = 1, T;
	int K, C, S;
	cin >> T;
	for(int l = 0 ; l < T ; l++) {
		cin >> K >> C >> S;
		//TRAITEMENT
		cout << "Case #" << i++ << ":";
		if(K > S) cout << " IMPOSSIBLE" << endl;
		else{
			for(int i = 0 ; i < S ; i++)
				cout << " " << i+1;
			cout << endl;
		}
		///////////
	}
	return 0;
}

