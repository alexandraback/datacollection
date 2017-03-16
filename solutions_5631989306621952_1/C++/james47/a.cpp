/*************************************************************************
    > File Name: a.cpp
    > Author: james47
    > Mail: 
    > Created Time: Sat Apr 16 09:11:19 2016
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int T;
string f(string s){
	int len = s.length();
	if (len == 1) return s;
	string a = f(s.substr(0, len-1));
	if (a + s[len-1] > s[len-1] + a)
		return a + s[len-1];
	else
		return s[len-1] + a;
}

string s;
int main()
{
	int cas = 0;
	cin >> T;
	while(T--){
		cin >> s;
		++cas;
		cout << "Case #" << cas << ":" << ' ' << f(s) << endl;
	}
	return 0;
}
