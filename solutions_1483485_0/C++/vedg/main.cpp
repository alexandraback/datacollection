//#define IDBG
#undef IDBG

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <sstream>

using namespace std;


int main() {
#ifdef IDBG
    freopen("cin", "r", stdin);
#endif
	
	vector<string> fromS;
	vector<string> toS;
	fromS.push_back("y qee");
	toS.push_back("a zoo");
	
	fromS.push_back("ejp mysljylc kd kxveddknmc re jsicpdrysi");
	toS.push_back("our language is impossible to understand");
	
	fromS.push_back("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
	toS.push_back("there are twenty six factorial possibilities");
	
	fromS.push_back("de kr kd eoya kw aej tysr re ujdr lkgc jv");
	toS.push_back("so it is okay if you want to just give up");
		
	
	vector<char> from(256);
	
	for (int i = 0; i < fromS.size(); ++i) {
		for (int j=0;j<fromS[i].size(); ++j)
			from[fromS[i][j]] = toS[i][j];
	}
	char pos=0;
	vector<signed char> used(256);
	for (char i='a';i<='z';++i) {
		if (from[i] == 0)
			pos=i;
		else
			used[from[i]] = 1;
	}
	if (pos != 0){
		for (char i='a';i<='z';++i)
			if (used[i] == 0)
				from[pos] = i;
	}
	
	int cases;
	cin>>cases;
	for (int cas=1;cas<=cases;++cas){
		string s;
		getline(cin,s);
		string t;
		istringstream is(s);
		if (! (is>>t)){
			--cas;
			continue;
		}
		cout<<"Case #"<<cas<<": ";
		for (int i=0;i<s.size();++i){
			if (s[i] != ' ')
				s[i] = from[s[i]];
			cout<<s[i];
		}
		cout<<endl;
	}
		
#ifdef IDBG
    fclose(stdin);
    putchar('\n');
#endif
}

