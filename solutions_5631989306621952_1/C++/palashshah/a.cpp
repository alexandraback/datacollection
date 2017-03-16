#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		string s, t;
		cin >> s;
		t.insert(0, 1, s[0]);
		for(int j = 1; j < s.size(); j++){
			if(s[j] >= t[0])
				t.insert(0, 1, s[j]);
			else
				t.insert(t.size(), 1, s[j]);
		}
		cout << "Case #" << i << ": " << t << endl;
	}
	return 0;
}
