#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <numeric>
#include <list>

using namespace std;

#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define SIZEOF(a) (sizeof(a)/sizeof((a)[0]))

typedef long long ll;

/*
EORZ - Z
ENO
OTW - W
EEHRT - 2R
FORU - U
EFIV - 2F
ISX - X
EENSV - 2S
EGHIT - G
EINN - 2I
*/
string ToText(int i){
	string s[] = {
		"ZERO", "ONE", "TWO", "THREE", "FOUR",
		"FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
	return s[i];
}

typedef map<char, int> TMap;
void Remove(string s, int x, TMap& m){
	FOR(i, s.size()){
		m[s[i]] -= x;
		if(m[s[i]] == 0){
			m.erase(s[i]);
		}
	}
}

void SolveCase()
{
	string s; cin >> s;
	map<char, int> m; FOR(i,s.size()) m[s[i]]++;
	vector<int> res;
	while(!m.empty()){
		if(m.count('Z')){
			int x = m['Z'];
			FOR(i, x) res.push_back(0);
			Remove("ZERO", x, m); continue;
		}
		if(m.count('W')){
			int x = m['W'];
			FOR(i, x) res.push_back(2);
			Remove("TWO", x, m); continue;
		}
		if(m.count('U')){
			int x = m['U'];
			FOR(i, x) res.push_back(4);
			Remove("FOUR", x, m); continue;
		}
		if(m.count('X')){
			int x = m['X'];
			FOR(i, x) res.push_back(6);
			Remove("SIX", x, m); continue;
		}
		if(m.count('G')){
			int x = m['G'];
			FOR(i, x) res.push_back(8);
			Remove("EIGHT", x, m); continue;
		}

		if(m.count('R')){
			int x = m['R'];
			FOR(i, x) res.push_back(3);
			Remove("THREE", x, m); continue;
		}
		if(m.count('F')){
			int x = m['F'];
			FOR(i, x) res.push_back(5);
			Remove("FIVE", x, m); continue;
		}
		if(m.count('S')){
			int x = m['S'];
			FOR(i, x) res.push_back(7);
			Remove("SEVEN", x, m); continue;
		}
		if(m.count('I')){
			int x = m['I'];
			FOR(i, x) res.push_back(9);
			Remove("NINE", x, m); continue;
		}
		if(m.count('O')){
			int x = m['O'];
			FOR(i, x) res.push_back(1);
			Remove("ONE", x, m); continue;
		}
	}
	sort(res.begin(), res.end());
	FOR(i,res.size()) cout << res[i];
}

void test1()
{
	FOR(i, 10){
		string s = ToText(i);
		sort(s.begin(), s.end());
		cout << s << endl;
	}
}

int main()
{
	//test();return 0;
	int t; cin >> t;
	FOR(i,t){
		cout << "Case #" << i+1 << ": ";
		SolveCase();
		cout << endl;
	}
	return 0;
}