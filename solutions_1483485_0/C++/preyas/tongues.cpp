#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

int main()
{
	map<char, char> m;
	m['a'] = 'y';
	m['o'] = 'e';
	m['z'] = 'q';

	string s = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
	string o = "our language is impossible to understand";
	s += "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	o += "there are twenty six factorial possibilities";
	s += "de kr kd eoya kw aej tysr re ujdr lkgc jv";
	o += "so it is okay if you want to just give up";

	int n = s.length();
	assert(o.length() == n);

	for(int i =0; i<n;i++)
		m[s[i]] = o[i];

	bool takenin[26], takenout[26];
	for(int i = 0; i<26; i++)
		takenin[i] = takenout[i] = false;
	for(map<char, char>::iterator it = m.begin(); it!= m.end(); it++)
	{
		char in = it ->first;
		char out = it -> second;
		takenin[in - 'a'] = true;
		takenout[out - 'a'] = true;
	}

	char missingin, missingout;
	for(int i =0; i<26; i++)
	{
		if(!takenin[i])
			missingin = 'a' + i;
		if(!takenout[i])
			missingout = 'a' + i;
	}
	m[missingin] = missingout;
	int T;
	cin>>T;
	getline(cin,s);
	for(int i =1; i<=T; i++)
	{
		getline(cin, s);
		n = s.length();
		for(int j = 0; j<n; j++)
			if(m.find(s[j]) == m.end())
			{
				cout<<s[j]<<endl;
				return 1;
			}
			else
				s[j] = m[s[j]];
		cout<<"Case #"<<i<<": "<<s<<endl;
	}

	return 0;
}
