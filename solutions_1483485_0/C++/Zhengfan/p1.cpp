#include <iostream>
#include <fstream>
#include <map>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]) {
	const string a1 = "our language is impossible to understand";
	const string b1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
	
	const string a2 = "there are twenty six factorial possibilities";
	const string b2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	
	const string a3 = "so it is okay if you want to just give up";
	const string b3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
	
	const string a4 = "a zoo";
	const string b4 = "y qee";
	
	map<char, char> d;
	for (int i=0; i<a1.length(); i++) d[b1[i]] = a1[i];
	for (int i=0; i<a2.length(); i++) d[b2[i]] = a2[i];
	for (int i=0; i<a3.length(); i++) d[b3[i]] = a3[i];
	for (int i=0; i<a4.length(); i++) d[b4[i]] = a4[i];
	
	int k = 0;
	char p;
	for (int i=0; i<26; i++)
		if (d.find('a'+i) != d.end()) k += d['a'+i]-'a';
		else p = i+'a';
	d[p] = 26*25/2-k+'a';
	
	ifstream f;
	f.open(argv[1]);
	int T;
	f >> T;
	char s[1];
	f.getline(s, 1);
	for (int t=0; t<T; t++) {
		char s[101];
		f.getline(s, 101);
		cout << "Case #" << t+1 << ": ";
		for (int i=0; i<strlen(s); i++) {
			cout << d[s[i]];
		}
		cout << endl;
	}
}
