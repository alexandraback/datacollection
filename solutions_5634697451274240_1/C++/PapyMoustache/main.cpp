#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;
int process(string N);

int main() {
	string s;
	int i = 1, T;
	cin >> T;
	for(int l = 0 ; l < T ; l++) {
		cin >> s;
		//TRAITEMENT
		cout << "Case #" << i++ << ": " << process(s) << endl;
		///////////
	}
	return 0;
}

int process(string s){
	int sum = 0;
	char state = s[0];
	for(int i = 1 ; i < s.size() ; i++)
		if(s[i] != state){
			sum++;
			state = s[i];
		}
	return sum + (state == '-' ? 1 : 0);
}
