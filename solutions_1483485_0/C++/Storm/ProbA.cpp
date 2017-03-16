#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>

using namespace std;

int main()
{
	freopen("C:\\Projects\\gcj\\input.txt", "r", stdin);
	freopen("C:\\Projects\\gcj\\output.txt", "w", stdout);

	map<char, char> m;
	vector<string> orig;
	vector<string> replaced;
	orig.push_back("our language is impossible to understand");
	orig.push_back("there are twenty six factorial possibilities");
	orig.push_back("so it is okay if you want to just give up");
	orig.push_back("a zoo");

	replaced.push_back("ejp mysljylc kd kxveddknmc re jsicpdrysi");
	replaced.push_back("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
	replaced.push_back("de kr kd eoya kw aej tysr re ujdr lkgc jv");
	replaced.push_back("y qee");

	for (int i=0;i<orig.size();i++) {
		for (int j=0;j<orig[i].size();j++) {
			m[replaced[i][j]] = orig[i][j];
		}
	}

	m['z'] = 'q';
	//cout << m.size() << endl;
	for (map<char, char>::iterator it = m.begin(); it != m.end(); it++) {
		//cout << it->first << " -> " << it->second << endl;
	}

	string temp;
	getline(cin, temp);
	stringstream stream(temp);

	int n;
	stream >> n;

	for (int i=0;i<n;i++) {
		cout << "Case #" << (i+1) << ": ";

		string str;
		getline(cin, str);
		//cout << "input = " << str << endl;
		for (int i=0;i<str.size();i++) {
			cout << m[str[i]];
		}
		cout << endl;
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}