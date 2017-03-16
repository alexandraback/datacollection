#include <iostream>
#include <string>
#include <cstdlib>
#include <memory.h>

using namespace std;

int main()
{
	char map['z'-'a'+1];
	int N;
	
	memset(map, 0, sizeof(map));
	
	string s;
	string in ="ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jvz";
	string out="our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give upq";
	
	for (string::size_type j=0; j<in.size(); j++) {
		if ('a' <= in[j] && in[j] <= 'z')
			map[in[j]-'a']=out[j];
	}
	
	for (int j=0; j<'z'-'a'+1; j++)
		if (map[j]==0)
			map[j]='z';
	
	getline(cin, s);
	N = atoi(s.c_str());
	for (int i=1; i<=N; i++) {
		getline(cin, s);
		
		for (string::size_type j=0; j<s.size(); j++) {
			if ('a' <= s[j] && s[j] <= 'z')
				s[j] = map[s[j] - 'a'];
		}
		
		cout << "Case #" << i << ": " << s << endl;
	}
}
