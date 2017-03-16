#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

const char mapping[26] = {
'y',
'h',
'e',
's',
'o',
'c',
'v',
'x',
'd',
'u',
'i',
'g',
'l',
'b',
'k',
'r',
'z',
't',
'n',
'w',
'j',
'p',
'f',
'm',
'a',
'q'
};

int main() {
	freopen("a-small.in", "r", stdin);
	freopen("a-small.out", "w", stdout);

	int t, len;
	cin>>t; cin.ignore();
	char str[106];
	for (int i=1; i<=t; i++) {
		cout<<"Case #"<<i<<": ";
		cin.getline(str, 105);
		len = strlen(str);
		for (int i=0; i<len; i++) {
			if (isalpha(str[i]))
				cout<<mapping[ str[i]-'a' ];
			else
				cout<<str[i];
		}
		cout<<endl;
	}

	return 0;
}
