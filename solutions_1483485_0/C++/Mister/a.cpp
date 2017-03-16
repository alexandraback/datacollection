#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
using namespace std;
char mp[26];
string s;
string inp[3] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi","rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd","de kr kd eoya kw aej tysr re ujdr lkgc jv"};
string outp[3] = {"our language is impossible to understand","there are twenty six factorial possibilities","so it is okay if you want to just give up"};
int main() {
	for(int i=0;i<3;++i)
		for(int j=0;j<inp[i].length();++j) {
			if(inp[i][j] == ' ') continue;
			mp[inp[i][j]-'a'] = outp[i][j];
		}
	// try both
	mp['q'-'a'] = 'z';
	mp['z'-'a'] = 'q';
	int T;
	scanf("%d",&T);
	cin.ignore();
	for(int cn=1;cn<=T;++cn) {
		getline(cin,s);
		printf("Case #%d: ",cn);
		for(int i=0;i<s.length();++i) {
			if(s[i] == ' ') printf(" ");
			else printf("%c",mp[s[i]-'a']);
		}
		printf("\n");
	}
}
