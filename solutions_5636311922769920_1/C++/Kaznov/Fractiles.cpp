//============================================================================
// Name        : Fractiles.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

long long int k, c, s;
vector<int> kolejka;

long long int pozycja(int poziom){
	if(poziom == 0) return 0;
	long long int zgarniany;
	if(!kolejka.empty()){
		zgarniany = kolejka.back();
		kolejka.pop_back();
	}
	else zgarniany = 0;
	return pozycja(poziom - 1) * k + zgarniany;
}

int main() {
	int t;
	cin >> t;
	for(int it=0; it<t; ++it){
		kolejka.clear();

		cin >> k >> c >> s;
		cout << "Case #" << it+1 << ":";
		int uzyci = 0;
		for(int i = k-1; i>=0; --i) kolejka.push_back(i);
		vector<long long int> pozycje;
		while(!kolejka.empty()){
			pozycje.push_back(pozycja(c));
			++uzyci;
		}
		if(uzyci>s){
			cout << " IMPOSSIBLE\n";
		}
		else{
			for(int i = 0; i<pozycje.size(); ++i)
				cout << " " << pozycje[i] + 1;
			cout << "\n";
		}

	}

	return 0;
}
