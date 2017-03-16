#include <iostream>
#include <string>

using namespace std;

int main() {
	int lang[26];
	for(int i=0; i<26; ++i) {
		lang[i] = -1;
	}
	string in = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv q";
	string out = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up z";
	for(int i=0; i<in.length(); ++i) {
		if(in[i] != ' ')
		lang[in[i] - 'a'] = out[i] - 'a';
	}
	int sum = 0;
	int mySum = 0;
	int missI = -1;
	for(int i=0; i<26; ++i) {
		if(lang[i] != -1) {
			mySum+=lang[i];
		} else {
			missI = i;
		}
		sum+=i;
	}
	if(missI != -1)
	lang[missI] = sum-mySum;
	
	
	
	
	
	// cout << endl;
	// 	
	// 	for(int i=0; i<26; ++i) {
	// 		cout << char(i+'a') << " : " << char(lang[i] + 'a') <<endl; 
	// 	}
	// 	
		
	int T;
	cin >> T;
	getline(cin,in);
	for(int i=0; i<T; ++i) {
		getline(cin,in);
		cout << "Case #"<< i+1 <<": ";
		for(int i=0; i<in.length(); ++i) {
			if(in[i] != ' ') {
				cout << char(lang[in[i]-'a'] + 'a');
			} else {
				cout << " ";
			}
		}
		cout << endl;
		
	}
	
	
	
	
	
	
	return 0;
}

