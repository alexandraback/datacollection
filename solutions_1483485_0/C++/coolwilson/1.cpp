#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
	map<char, char> mp;
	string s1="ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
	string s2="our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

	for(int i=0; i<s1.length(); i++) {
		mp[s1[i]] = s2[i];
	}

	mp['q'] = 'z';
	mp['z'] = 'q';

	int T;
	string G;
	cin>>T;
	string tmp;
	getline(cin, tmp);

	for(int i=1; i<=T; i++) {
		getline(cin, G);
		cout<<"Case #"<<i<<": ";
		for(int j=0; j<G.length(); j++) {
			cout<<mp[G[j]];
		}
		cout<<endl;
	}

	return 0;
}
