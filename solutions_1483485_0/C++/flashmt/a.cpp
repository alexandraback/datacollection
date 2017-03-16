#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

map <char,char> d;

int main()
{
	freopen("asmall.in","r",stdin);
	freopen("asmall.out","w",stdout);
	
	string s="ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
	string t="our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
	for (int i=0;i<int(s.size());i++) d[s[i]]=t[i];
	for (char c='a';c<='z';c++)
		if (!d.count(c)) d[c]=(c=='z'?'q':'z');

	int test;
	cin >> test;
	getline(cin,s);
	for (int it=1;it<=test;it++)
	{
		getline(cin,s);
		for (int i=0;i<int(s.size());i++) s[i]=d[s[i]];
		cout << "Case #" << it << ": " << s << endl;
	}
}
