#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	int t, a;
	string s;
	string u = "abcdefghijklmnopqrstuvwxyz";
	string v = "ynficwlbkuomxsevzpdrjgthaq";
	
	scanf("%d", &t);
	getchar();
	
	for (int C = 1; C <= t; C++) {
		getline(cin, s);
		
		for (int i = 0; i < s.length(); i++)
			if ((a = v.find(s[i])) != string::npos) {
				s[i] = u[a];
			}
		
		printf("Case #%d: %s\n", C, s.c_str());
	}
	return 0;
}