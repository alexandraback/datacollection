#include <iostream>

using namespace std;

string decode = "yhesocvxduiglbkrztnwjpfmaq";

int main(){
	int t; cin >> t; string temp; getline(cin,temp);
	for (int zz = 1; zz <= t; zz++){
		string s; getline(cin,s);
		cout << "Case #" << zz << ": ";
		for (int i = 0; i < s.length(); i++){
			if (s[i] >= 'a' && s[i] <= 'z')
				cout << decode[s[i]-'a'];
			else cout << s[i];
		}
		cout << endl;
	}	
	
	return 0;
}
