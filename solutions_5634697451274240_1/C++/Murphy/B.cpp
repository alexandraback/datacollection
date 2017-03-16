#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <fstream>
using namespace std;
#define pb push_back 
#define REP(i,n) for(int i=0;i<(n);i++ )
typedef long long LL;
typedef pair<int, int> pii;

int gao(string s) {
	int c = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] == '-') {
			if (i == s.size() - 1 || s[i + 1] != '-') c++;
		}
	}
	c *= 2; if (s[0] == '-') c--;
	return c;
}

int main() {
	int casen; cin>>casen;
	REP(casei, casen) {
		string s; cin>>s;
		cout<<"Case #" << (casei + 1)<<": "<<gao(s)<<endl;
	}
	return 0;
}