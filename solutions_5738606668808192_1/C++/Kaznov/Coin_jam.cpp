//============================================================================
// Name        : Coin_jam.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

vector<string> slowa; //polowy liczb

void generuj(int a){
	if(slowa.empty()){
		string slowo;
		slowo+="1";
		for(int i=0; i<a; ++i) slowo+="0";
		slowo+="1";
		slowa.push_back(slowo);
	}
	else{
		string slowo= slowa.back();
		int r = slowo.size() - 2;
		++slowo[r];
		while(slowo[r]=='2'){
			slowo[r]='0';
			--r;
			++slowo[r];
		}
		slowa.push_back(slowo);
	}
}

long long int zamiana(int podstawa, string s){
	long long int p = 1;
	long long int liczba = 0;
	for(int i=s.size()-1; i>=0; --i){
		liczba+= p*(s[i]-48);
		p*=podstawa;
	}
	return liczba;
}

int main() {
	int t;

	cin >> t;

	int n, j;

	cin >> n;
	cin >> j;

	for(int i = 0; i<j; ++i){
		generuj(n/2 - 2);
	}

	cout << "Case #1:\n";

	for(int i=0; i<j; ++i){
		cout << slowa[i] << slowa[i];
		for(int k=2; k<=10; ++k){
			cout << " "  << zamiana(k, slowa[i]);
		}
		cout << "\n";
	}



	return 0;
}
