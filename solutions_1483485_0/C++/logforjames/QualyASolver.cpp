/*
 * The "ExampleParsed" it's just the example, without the first int, and the "Case #x: " stuff. Just words.
 */ 

#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

#define forsn(i,s,n) for(int i = (s);i < (int)(n);i++)
#define forn(i,n) forsn(i,0,n)
#define esta(x,c) (c.find(x) != c.end())
#define all(v) v.begin(),v.end()

char mapeo[26];

int main(){
	fstream example("QualyAExampleParsed.in",fstream::in);
	vector<string> word;
	string t;
	while(example >> t){
		word.push_back(t);
	}
	forn(i, 26)
		mapeo[i] = -1;
	mapeo['q' - 'a'] = 'z';
	mapeo['z' - 'a'] = 'q';
	int s = word.size() / 2;
	forn(i, s){
		forn(j, word[i].size()){
			mapeo[word[i][j] - 'a'] = word[s + i][j];
		}
	}
	freopen("QualyA.in","r",stdin);
	freopen("QualyA.out","w",stdout);
	int n;
	scanf("%d\n", &n);
	forn(i,n){
		cout << "Case #" << (i + 1) << ": ";
		string s;
		getline(cin, s);
		istringstream line(s);
		string t;
		bool space = false;
		while(line >> t){
			if(space) cout << ' ';
			space = true;
			forn(j, t.size()){
				cout << mapeo[t[j] - 'a'];
			}
		}
		cout << endl;
	}
}
