#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(){
	int t;
	cin >> t;

	//for each case
	for (int i = 1; i <= t; ++i){
		unsigned long long n;
		cin >> n;
		cout << "Case #" << i << ": ";

		//only 0 causes insomnia
		if (!n){
			cout << "INSOMNIA" << endl;
			continue;
		}

		set<char> digs;					//storage for characters seen
		unsigned long long nOrig = n;					//original number

		//first seen characters
		string num = to_string(n);
		for (int j = num.length() - 1; j >= 0; j--){
			digs.insert(num[j]);
		}

		//keep counting till seeing them all
		while (digs.size() < 10){
			n += nOrig;
			num = to_string(n);
			for (int j = num.length() - 1; j >= 0; j--){
				digs.insert(num[j]);
			}
		}
		cout << n << endl;
	}

	return 0;
}
