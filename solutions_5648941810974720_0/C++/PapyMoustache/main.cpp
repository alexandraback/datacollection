#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <boost/foreach.hpp> //BOOST_FOREACH( single, sequence ) {}

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


string process(string s){
	stringstream ss;
	vector<int> repart(200, 0);
	vector<int> result(10, 0);
	for(int i = 0 ; i < s.size() ; i++)
		repart[s[i]]++;
	while(repart['Z'] > 0){
		result[0]++;
		repart['Z']--; repart['E']--; repart['R']--; repart['O']--;
	}
	while(repart['G'] > 0){
		result[8]++;
		repart['E']--; repart['I']--; repart['G']--; repart['H']--; repart['T']--;
	}
	while(repart['X'] > 0){
		result[6]++;
		repart['S']--; repart['I']--; repart['X']--;
	}
	while(repart['U'] > 0){
		result[4]++;
		repart['F']--; repart['O']--; repart['U']--; repart['R']--;
	}
	while(repart['H'] > 0){
		result[3]++;
		repart['T']--; repart['H']--; repart['R']--; repart['E']-=2;
	}
	while(repart['W'] > 0){
		result[2]++;
		repart['T']--; repart['W']--; repart['O']--;
	}
	while(repart['F'] > 0){
		result[5]++;
		repart['F']--; repart['I']--; repart['V']--; repart['E']--;
	}
	while(repart['V'] > 0){
		result[7]++;
		repart['S']--; repart['E']--; repart['V']--; repart['E']--; repart['N']--;
	}
	while(repart['I'] > 0){
		result[9]++;
		repart['N']-=2; repart['I']--; repart['E']--;
	}
	while(repart['O'] > 0){
		result[1]++;
		repart['O']--;
	}
	for(int i = 0 ; i < 10 ; i++)
		for(int j = 0 ; j < result[i] ; j++)
			ss << i;
	return ss.str();
}

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
