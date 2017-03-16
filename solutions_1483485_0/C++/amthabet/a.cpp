#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<memory.h>
using namespace std;

string src = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
string dst = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

int main()	{

	//freopen("a_sample.in","rt",stdin);
	freopen("a_small_1.in","rt",stdin);
	freopen("a_small_1.out","wt",stdout);

	map<char, char> m;
	for(int i=0;i<src.size();i++) m[src[i]] = dst[i];
	m['z'] = 'q';
	m['q'] = 'z';
	
	int t;
	cin>>t;
	string s;
	getline(cin, s);
	for(int tt=1;tt<=t;tt++) {
		getline(cin, s);
		cout<<"Case #"<<tt<<": ";
		for(int i=0;i<s.size();i++)
			cout<<m[s[i]];
		cout<<endl;
	}

	return 0;
}