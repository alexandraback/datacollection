#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	int T;
	cin >> T;
	//cout << T;
	cin.get();
	for (int t = 1; t<=T; t++) {

		string name;
		int n=0;
		
		//getline(cin, name);
		getline(cin, name);
		
		string::iterator it = name.begin()+name.find_first_of(" ",0)+1;
		
		for (; it!=name.end(); it++) {
			n=n*10+(*it)-48;
		}
		
		//n=name[name.length()-1]-48;
		name.resize(name.find_first_of(" ",0));
		//cout << n << endl;
		//cout << name << endl;
		
		long long int last = n-2;
		long long  ans = 0;
		long long int cons_row = 0;
		
		for (long long int i = 0; i<name.length(); i++) {
			switch (name[i]) {
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
					cons_row = 0;
					break;
				default:
					cons_row++;
			}
			
			if (cons_row >= n) {
				//cout << (i-last) << " " << (name.length()-i) << endl;
				ans+=(i-last)*(name.length()-i);
				last = i;
			}
			
		}
		
		cout << "Case #" << t << ": " << ans << endl;
		
	}
	
	return 1;
}
