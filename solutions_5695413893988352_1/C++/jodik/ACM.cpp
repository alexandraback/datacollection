//============================================================================
// Name        : ACM.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <curl/curl.h>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <map>
#include <cstdio>
#include <cmath>
#include <fstream>

using namespace std;

vector<pair<string, string> > dic;
vector<int> permutation;
int couples;
int res = 0;

string prvy, druhy, bestPrvy, bestDruhy;
unsigned long long vF = 0, vS = 0;
unsigned long long bestDifference = ULLONG_MAX;
unsigned long long bestP = ULLONG_MAX, bestD = ULLONG_MAX;

long long dajDoCisla(string cislo){
	long long res = 0;
	long long pow = 1;
	for(int i = cislo.size() - 1; i >=0; i--){
		res+=(cislo[i]-'0') * pow;
		pow*=10;
	}
	return res;
}

void dajNarovnako(string& prvy, string& second, int po){
	for(int i = 0; i < po; i++){
		if(prvy[i] != '?'){
			if(second[i] == '?'){
				second[i] = prvy[i];
			}
		}
		if(second[i] != '?'){
			if(prvy[i] == '?'){
				prvy[i] = second[i];
			}
		}
		if(prvy[i] == '?' && second[i] == '?'){
			second[i] = '0';
			prvy[i] = '0';
		}
	}
}

void checkTwoNumbers(string prvyC, string druhyC){
	unsigned long long difference = 0;
	difference = abs(dajDoCisla(prvyC) - dajDoCisla(druhyC));
	if(difference < bestDifference){
		bestDifference = difference;
		bestPrvy = prvyC;
		bestDruhy = druhyC;
		bestP = dajDoCisla(prvyC);
		bestD = dajDoCisla(druhyC);
	}
	else if (difference == bestDifference){
		if(dajDoCisla(prvyC) < bestP || (dajDoCisla(prvyC) == bestP && dajDoCisla(druhyC) < bestD)){
			bestDifference = difference;
			bestPrvy = prvyC;
			bestDruhy = druhyC;
			bestP = dajDoCisla(prvyC);
			bestD = dajDoCisla(druhyC);
		}
	}
}

void maximalizuj(int od, string& word){
	for(int i = od; i < word.size(); i++){
		if(word[i] == '?'){
			word[i] = '9';
		}
	}
}

void minimalizuj(int od, string& word){
	for(int i = od; i < word.size(); i++){
		if(word[i] == '?'){
			word[i] = '0';
		}
	}
}

void check(int j, string prvy, string druhy){
	dajNarovnako(prvy, druhy, j);
	if(prvy[j] != '?' && druhy[j] != '?'){
		string prvyC = prvy;
		string druhyC = druhy;
		maximalizuj(j+1, prvyC);
		minimalizuj(j+1, druhyC);
		checkTwoNumbers(prvyC, druhyC);

		prvyC = prvy;
		druhyC = druhy;
		minimalizuj(j+1, prvyC);
		maximalizuj(j+1, druhyC);
		checkTwoNumbers(prvyC, druhyC);

		prvyC = prvy;
		druhyC = druhy;
		maximalizuj(j+1, prvyC);
		maximalizuj(j+1, druhyC);
		checkTwoNumbers(prvyC, druhyC);

		prvyC = prvy;
		druhyC = druhy;
		minimalizuj(j+1, prvyC);
		minimalizuj(j+1, druhyC);
		checkTwoNumbers(prvyC, druhyC);
	}
	else if (prvy[j] == '?' && druhy[j] == '?'){
		prvy[j] = '0';
		druhy[j] = '0';
		check(j, prvy, druhy);
		prvy[j] = '1';
		druhy[j] = '0';
		check(j, prvy, druhy);
		prvy[j] = '0';
		druhy[j] = '1';
		check(j, prvy, druhy);
	}
	else if (prvy[j] == '?'){
		prvy[j] = druhy[j];
		check(j, prvy, druhy);
		if(druhy[j] != '0'){
			prvy[j] = druhy[j];
			prvy[j]--;
			check(j, prvy, druhy);
		}
		if(druhy[j] != '9'){
			prvy[j] = druhy[j];
			prvy[j]++;
			check(j, prvy, druhy);
		}
	}
	else if (druhy[j] == '?'){
		druhy[j] = prvy[j];

		//cout<<"check:"<<prvy<<", "<<druhy<<endl;
		//cout<<"najlepsi: "<<bestPrvy<<", "<<bestDruhy<<" "<<bestDifference<<endl;
		//cout<<"dajDoCisla: "<<dajDoCisla(bestPrvy)<<", "<<dajDoCisla(bestDruhy)<<" "<<bestDifference<<endl;
		check(j, prvy, druhy);
		if(prvy[j] != '0'){
			druhy[j] = prvy[j];
			druhy[j]--;
			check(j, prvy, druhy);
		}
		if(prvy[j] != '9'){
			druhy[j] = prvy[j];
			druhy[j]++;
			check(j, prvy, druhy);
		}
	}
}

int main() {
	int cases;
	cin>>cases;
	for(int i = 0; i < cases; i++){
		prvy = ""; druhy = ""; bestPrvy = ""; bestDruhy = "";
		vF = 0; vS = 0;
		bestDifference = ULLONG_MAX;
		bestP = ULLONG_MAX; bestD = ULLONG_MAX;
		cin>>prvy;
		cin>>druhy;

		for(int j = 0; j < prvy.size(); j++){
			check(j, prvy, druhy);
			if(prvy[j] != '?' && druhy[j] != '?'){
				if(prvy[j] != druhy[j]){
					break;
				}
			}
		}

		cout<<"Case #"<<i+1<<": "<<bestPrvy<<" "<<bestDruhy<<endl;
	}
}
