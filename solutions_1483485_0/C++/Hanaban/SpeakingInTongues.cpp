#include <cstdio>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#include <stdlib.h>

void solve(int case_no)
{
	char g[26] = {
		'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l',
		'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'
	};
	char s[1024];
	
	cin.getline(s, 1024);
	string x(s);
	if (x.empty() ) {
		solve(case_no);
		return;
	}
	
	for (int i = 0; i < x.size(); ++i) {
		if (x[i] == ' ') continue;
		x[i] = g[x[i] - 'a'];
	}
	
	cout << "Case #" << case_no << ": " << x << endl;
	
	return;
}
int main()
{
	int T, N;
	vector<char> R;
	vector<int> P;
	
	cin >> T;
	
	for (int i = 0; i < T; ++i) {
		solve(i + 1);
		
	}
	return 0;
}