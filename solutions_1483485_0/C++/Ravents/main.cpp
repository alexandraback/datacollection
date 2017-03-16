#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <memory.h>

using namespace std;

const int mm = 205;

string data[4][2] = {{"y qee",
					  "a zoo"},
{"ejp mysljylc kd kxveddknmc re jsicpdrysi",
 "our language is impossible to understand"},
{"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
 "there are twenty six factorial possibilities"},
{"de kr kd eoya kw aej tysr re ujdr lkgc jv",
 "so it is okay if you want to just give up"}};

map<char,char> a;
int main() {
	//freopen("input.txt", "r", stdin);
	freopen("d:\\Downloads\\A-small-attempt1.in", "r", stdin);
	freopen("d:\\Downloads\\A-small-attempt1.out", "w", stdout);
	for (int i=0; i<4; i++)
		for (int j=0; j<data[i][0].length(); j++)
			a[data[i][0][j]]=data[i][1][j];
	a['z']='q';

	int N; cin>>N; 
	string s; getline(cin,s);
	for (int t=1; t<=N; t++) {
		getline(cin,s);
		cout<<"Case #"<<t<<": ";
		for(int i=0; i<s.length(); i++)
			if (!isalpha(s[i])) cout<<" ";
			else 			cout<<a[s[i]];
		cout<<"\n";
	}
	return 0;
}