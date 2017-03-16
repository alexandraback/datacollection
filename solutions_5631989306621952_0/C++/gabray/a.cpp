#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>

using namespace std;

#define For(i, po) for(int (i) = 0; (i) < (po); i++)
#define MAXI 1000000009
typedef long long ll;
typedef pair<int,int> pii;

void solve(int T){
	string s;
	cin >> s;
	vector<pair<char, int> > v;
	for(int i = 0; i < s.length(); i++){
		v.push_back({s[i], i});
	}
	sort(v.begin(), v.end());
	map<int, int> m;
	for(int i = 0; i < s.length(); i++){
		m[v[i].second] = i; 
	}

	int last = - 1;
	deque<char> de;
	for(int i = 0; i < s.length(); i++){
		if(m[i] < last){
			de.push_back(s[i]);
		} else {
			de.push_front(s[i]);
			last = m[i];
		}
	}	

	cout << "Case 	#" << T << ": ";
	for(auto c: de) cout << c; cout << endl;

}

int main(){
	int T;
	cin >> T;
	For(t, T) solve(t+1);
	return 0;
}
