#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;


int main(int argc, char *argv[]){
	fstream fin (argv[1], fstream::in);

	int T;
	fin >> T;
	for (int i = 0; i != T; ++i){
		int out = 0;
		string A, B;
		fin >> A >> B;
		long a = atoi(A.c_str());
		long b = atoi(B.c_str());

		for(long n = a; n !=b+1; ++n){
			stringstream s (stringstream::in | stringstream::out);
			s << n;
			string J;
			s >> J;
			vector <int> dups;
			for(int k = 1; k != J.length(); ++k){
				string back = J.substr(J.length()-k, k);
				string front= J.substr(0,J.length()-k);
				string test = back + front;
				
				int m = atoi(test.c_str());
				if ( m > n && m <= b){ //n >=a
					//cout << J << " " << test << endl;
					if (find(dups.begin(), dups.end(),m) == dups.end()){
						dups.push_back(m);
						out++;
					}

				}
			}
		}
		cout << "Case #" << i+1<< ": " << out  << endl;
	}
	return 0;
}
