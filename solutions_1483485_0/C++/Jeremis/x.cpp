#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
using namespace std;



int main() {

	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);

	string x[] = {
		"ejp mysljylc kd kxveddknmc re jsicpdrysi",
		"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
		"de kr kd eoya kw aej tysr re ujdr lkgc jv",
		"y",
		"e",
		"q",
	};

	string y[] = {
		"our language is impossible to understand",
		"there are twenty six factorial possibilities",
		"so it is okay if you want to just give up",
		"a",
		"o",
		"z",
	};

	set <char> a,b;
	for (int i='a';i<='z';i++) {
		a.insert(i);
		b.insert(i);
	}
	map <char,char> z;
	for (int i=0;i<6;i++) {
		for (int j=0;j<x[i].length();j++) {
			if (isalpha(x[i][j])) {
				z[x[i][j]] = y[i][j];
				a.erase(x[i][j]);
				b.erase(y[i][j]);
			}
		}
	}
	z[*a.begin()] = *b.begin();

	int n;
	cin >> n;
	string t;
	getline(cin,t);
	for (int i=0;i<n;i++) {
		getline(cin,t);
		for (int j=0;j<t.length();j++) {
			if (isalpha(t[j]))
				t[j] = z[t[j]];
		}
		cout << "Case #" << i+1 << ": " << t << endl;
	}
}