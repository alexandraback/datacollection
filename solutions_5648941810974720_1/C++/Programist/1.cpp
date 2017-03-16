#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <functional>
#include <math.h>
#include <utility>
#include <sstream>
#pragma comment(linker, "/STACK:133217728")

using namespace std;

int cnt[333];
int numb[44];
string x[10] =  {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

void f(char c, int k) {
	while(cnt[c] > 0) {
		numb[k]++;
		for(int i=0; i<x[k].length(); i++)
			cnt[x[k][i]]--;
	}
}

int main() {  
	freopen("A-large.in", "r", stdin);
	freopen("ans.txt", "w", stdout);
	
	int T;
	cin >> T;
	

	for(int t=1; t<=T; t++) {
		cout << "Case #" << t << ": ";
		string s;
		cin >> s;

		
		for(int i=0; i<333; i++)
			cnt[i] = 0;
		for(int i=0; i<s.length(); i++)
			cnt[s[i]]++;
		
		for(int i=0; i<10; i++) numb[i] = 0;

		f('Z', 0);
		f('W', 2);
		f('U', 4);
		f('F', 5);
		f('X', 6);
		f('S', 7);
		f('G', 8);
		f('O', 1);
		f('R', 3);
		f('N', 9);

		int len = 0;
		for(int i=0; i<10; i++) {
			for(int j=0; j<numb[i]; j++) cout << i;
			len += numb[i];
		}
		if(len != s.length()) runtime_error("");
		cout << endl;
	}
	
	return 0;
}