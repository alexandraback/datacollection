#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <fstream>
using namespace std;

char cmap[30] = {0};

int readMap() {
	ifstream fin("1.txt");
	string s[3];
	string g[3];
	string temp;
	getline(fin, temp);
	
	for(int i = 0; i < 3; ++i) {
		getline(fin, s[i]);
		//cout << s[i] << endl;
	}
	for(int i = 0; i < 3; ++i) {
		getline(fin, g[i]);
		//cout << g[i] << endl;
	}
	
	int count = 0;
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < s[i].length(); ++j) {
			if(cmap[s[i][j]-'a'] == 0) {
				count++;
			}
			cmap[s[i][j]-'a'] = g[i][j+9];
			//cout << (s[i][j]-'a') << " " << s[i][j] << " " << g[i][j+9] << endl;
		}
	}
	
	//for(int i = 0; i < 26; ++i) {
		//cout << i << " " << char('a'+i) << ' ' << cmap[i] << endl;
	//}
	cmap['z'-'a'] = 'q';
	cmap['q'-'a'] = 'z';
	//cout << count << endl;
	
	return count;
}

int main() {
	readMap();
	
	string s[1000];
	int test;
	
	cin >> test;
	//fflush(stdin);
	string temp;
	getline(cin, temp);
	for(int i = 1; i <= test; ++i) {
		getline(cin, s[i]);
		//cout << "String " << s[i] << endl;
		cout << "Case #" << i << ": ";
		for(int j = 0; j < s[i].length(); ++j) {
			cout << cmap[s[i][j]-'a'];
		}
		cout << endl;
		//cout << s[i] << endl;
	}
	
	
	return 0;
}
