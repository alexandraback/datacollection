#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#define D(x) cout<<#x "is : "<<x<<" in line "<<__LINE__<<endl;

using namespace std;


string fr("ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv");



string t("our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up");
char mape (char c) {
	//D(fr.size());
	//D(t.size());
	int x = fr.size();
	for (int i = 0; i<x; ++i) {
		if (fr[i] == c)
			return t[i];
	}
	return (c=='z')?'q':'z';
}

int main () {
	int n;
	string s;
	cin>>n;
	getline(cin,s);
	for (int cas = 1; cas <= n; ++cas) {
		getline(cin,s);
		cout<<"Case #"<<cas<<": ";
		for (int i = 0; i< (int)s.size(); ++i) {
			putchar(mape(s[i]));
		}
		cout<<endl;
	}
	
}
