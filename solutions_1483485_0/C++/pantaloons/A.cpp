#include <iostream>
#include <cstdio>
#include <map>
#include <set>

using namespace std;

int main() {
	map<char, int> m;
	set<char> s;
	m['q'] = 'z';
	m['z'] = 'q';
	m['e'] = 'o';
	m['y'] = 'a';
	string s1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
	string s2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	string s3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
	
	string r1 = "our language is impossible to understand";
	string r2 = "there are twenty six factorial possibilities";
	string r3 = "so it is okay if you want to just give up";
	
	for(int i = 0; i < s1.size(); i++) m[s1[i]] = r1[i], s.insert(r1[i]);
	for(int i = 0; i < s2.size(); i++) m[s2[i]] = r2[i], s.insert(r2[i]);
	for(int i = 0; i < s2.size(); i++) m[s3[i]] = r3[i], s.insert(r3[i]);
	
	int n;
	cin >> n;
	string line;
	getline(cin, line);
	for(int cc = 0; cc < n; cc++) {
		getline(cin, line);
		string res = "";
		for(int j = 0; j < line.size(); j++) {
			if(line[j] != ' ') res += m[line[j]];
			else res += ' ';
		}
		cout << "Case #" << cc + 1 << ": " << res << endl;
	}
}
