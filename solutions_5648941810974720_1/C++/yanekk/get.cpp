#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int M = 30;

vector <int> Cyfry;

int Ile[M];


void Czysc(){
	int i;
	Cyfry.clear();
	for(i=0; i<M; i++) Cyfry.clear();
}

void Odejmij(string s,char znak,int cyfra){
	int i;
	while(Ile[(int)znak-(int)'A'] > 0){
		for(i=0; i<s.size(); i++) {
			Ile[ (int)s[i]-(int)'A' ]--;
		}
		Cyfry.push_back( cyfra );
	}
}

int main(){
	int i,j,n;
	string s;
	cin >> n;
	for(i=0; i<n; i++){
		Czysc();
		cin >> s;
		for(j=0; j<s.size(); j++) Ile[(int)s[j]-(int)'A']++;
		Odejmij("ZERO", 'Z', 0);
		Odejmij("SIX", 'X', 6);
		Odejmij("EIGHT", 'G', 8);
		Odejmij("SEVEN", 'S', 7);
		Odejmij("FIVE", 'V', 5);
		Odejmij("FOUR", 'F', 4);
		Odejmij("THREE", 'R', 3);
		Odejmij("TWO", 'T', 2);
		Odejmij("ONE", 'O', 1);
		Odejmij("NINE", 'I', 9);
		cout << "Case #" << i+1 << ": ";
		sort(Cyfry.begin(),Cyfry.end());
		for(j=0; j<Cyfry.size(); j++) cout << Cyfry[j];
		cout << "\n";
	}
	return 0;
}
