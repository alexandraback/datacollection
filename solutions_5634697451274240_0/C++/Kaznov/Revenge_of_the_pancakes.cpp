#include <iostream>
#include <string>
using namespace std;

string prosty(string s){
	string zwracany;
	char ostatni = 0;
	for(unsigned int i=0; i<s.size(); ++i)
		if(ostatni!=s[i]){
			ostatni = s[i];
			zwracany.push_back(s[i]);
		}
	return zwracany;
}

int main() {
	int t;
	cin >> t;

	for(int i=0; i<t; ++i){
		string s;
		cin >> s;
		s = prosty(s);
		int wynik = s.size();
		if(*s.rbegin() == '+') --wynik;
		cout << "Case #" << i+1 << ": " << wynik << "\n";
	}
	return 0;
}
