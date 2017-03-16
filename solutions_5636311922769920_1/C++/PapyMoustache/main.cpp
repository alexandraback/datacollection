#include <cstdlib>
#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;
void process(int K, int C, int S, vector<cpp_int>& res);
void test(int K, int C, vector<int>& res);
list<int> makeInstance(list<int> orig, list<int> gold, list<int> current, int C);

int main() {
	string s;
	int i = 1, T;
	int K, C, S;
	vector<cpp_int> res;
	cin >> T;
	for(int l = 0 ; l < T ; l++) {
		cin >> K >> C >> S;
		//TRAITEMENT
		cout << "Case #" << i++ << ":";
		if(S < ceil((float)K/2.) || (C == 1 && S<K)) cout << " IMPOSSIBLE" << endl;
		else{
			process(K, C, S, res);
			for(int i = 0 ; i < res.size() ; i++)
				cout << " " << res[i] + 1;
			//test(K, C, res);
			cout << endl;
		}
		///////////
	}
	return 0;
}

void process(int K, int C, int S, vector<cpp_int>& res){
	if(C == 1){
		res.resize(K);
		for(int i = 0 ; i < K; i++)
			res[i] = i;
		return; }
	res.resize(ceil((float)K/2.));
	cpp_int K2 = K, C2 = C;
	cpp_int puis = pow(K2, C);
	for(int i = 0 ; i < res.size() ; i++){
		res[i] = puis - (i+1)*K2 + i;
	}
	int i = 0;
	while(res.size() < S)
		res.push_back(res[i++]);
}

void test(int K, int C, vector<int>& res){
	list<int> orig;
	list<int> gold;
	bool isOne;
	for(int i = 0 ; i < K ; i++){
		orig.push_back(rand()%2);
		if(orig.back() == 1)
			isOne = true;
		gold.push_back(1);}
	list<int> instance = makeInstance(orig, gold, orig, C);
	vector<int> instanceV{instance.begin(), instance.end()};
	bool found = false;
	for(int i = 0 ; i < res.size() ; i++)
		if(instanceV[res[i]] == 1)
			found = true;
	if(found != isOne){
		cout << " FAILED" << endl;
		exit(EXIT_FAILURE);
	}
	cout << ((found == isOne) ? " PASSED" : " FAILED") << endl;
}

list<int> makeInstance(list<int> orig, list<int> gold, list<int> current, int C){
	if(C <= 1) return current;
	list<int> newI;
	while(!current.empty()){
		if(current.front() == 1)
			newI.insert(newI.end(), gold.begin(), gold.end());
		else newI.insert(newI.end(), orig.begin(), orig.end());
		current.pop_front();
	}
	return makeInstance(orig, gold, newI, C-1);
}
