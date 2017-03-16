#include <iostream>
#include <string>
using namespace std;

string decode;
bool hit[256];

int main() {
	decode = "yhesocvxduiglbkrztnwjpfmaq";
	/*for (char c = 'a'; c <= 'z'; c++)
		hit[decode[c-'a']] = true;
	for (char c = 'a'; c <= 'z'; c++)
		if (!hit[c])
			cout << c << endl;
	cout << decode.size() << endl;*/
	
	string line;
	int ncases;
	cin >> ncases;
	cin.ignore();
	for (int icase = 1; icase <= ncases; icase++) {
		getline(cin, line);
		/*cout << line << endl;*/
		for (int i = 0; i < (int)line.size(); i++)
			if ('a' <= line[i] && line[i] <= 'z')
				line[i] = decode[line[i]-'a'];
		cout << "Case #" << icase << ": " << line << endl;
		/*
		cin.get(coded, 200);
		for (int i = 0; line[i] != '\n'; i++) {
			cout << icase << " " << i << line[i] << endl;
			if (line[i] != ' ')
				decode[coded[i]] = line[i];
		}
		*/
	}
	return 0;
}
