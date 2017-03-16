#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <utility>
#include <vector>
using namespace std;

const long long M = 1000000007;

bool isUni(const string& s) {
	for (int i=0; i<s.size(); i++) {
		if (s[0] != s[i]) {
			return false;
		}
	}
	return true;
}

bool isDual(const string& s) {
	for (int i=1; i<s.size(); i++) {
		if (s[0] != s[i]) {
			return isUni(s.substr(i));
		}
	}
	return false;
}

string triMidSubstring(const string& s) {
	int start = 0;
	while (s[0] == s[start]) {
		start++;
	}
	int end = s.size()-1;
	while (s.back() == s[end]) {
		end--;
	}

	stringstream ss;
	ss << s[start];
	for (int i=start+1; i<=end; i++) {
		if (s[i-1] != s[i]) {
			ss << s[i];
		}
	}

	return ss.str();
}

int countComponents(const vector<string>& s) {
	map<char, set<char>> G;
	for (int i=0; i<s.size(); i++) {
		G[s[i].front()].insert(s[i].back());
	}
	map<char, int> inDeg;
	for (map<char, set<char>>::iterator vi = G.begin(); vi != G.end(); ++vi) {
		for (set<char>::iterator ni = vi->second.begin(); ni != vi->second.end(); ++ni) {
			inDeg[*ni]++;
		}
	}

	map<char, bool> visited;
	int res = 0;
	for (int deg = 0; deg<=1; deg++) {
		for (map<char, set<char>>::iterator vi = G.begin(); vi != G.end(); ++vi) {
			if (!visited[vi->first] && inDeg[vi->first] == deg) {
				res++;
				vector<char> s;
				visited[vi->first] = true;
				s.push_back(vi->first);
				while (!s.empty()) {
					char v = s.back();
					s.pop_back();
					set<char>& n = G[v];
					for (set<char>::iterator it = n.begin(); it != n.end(); ++it) {
						if (!visited[*it]) {
							visited[*it] = true;
							s.push_back(*it);
						}
					}
				}
			}
		}
	}
	return res;
}

long long factorial(int x) {
	long long res = 1;
	for (long long i=1; i<=x; i++) {
		res = (res * i) % M;
	}
	return res;
}

int main() {
	int T;
	cin >> T;
	for (int t=1; t<=T; t++) {
		int n;
		vector<string> uni;
		vector<string> dual;
		vector<string> tri;
		vector<string> all;
		cin >> n;
		for (int i=0; i<n; i++) {
			string s;
			cin >> s;
			if (isUni(s)) {
				uni.push_back(s);
			} else if (isDual(s)) {
				dual.push_back(s);
			} else {
				tri.push_back(s);
			}
			all.push_back(s);
		}

		bool hasSolution = true;
		map<char, int> triMid;
		for (int i=0; i<tri.size(); i++) {
			hasSolution = hasSolution && tri[i].front() != tri[i].back();
			string midSubstring = triMidSubstring(tri[i]);
			for (int j=0; j<midSubstring.size(); j++) {
				triMid[midSubstring[j]]++;
			}
		}
		for (map<char, int>::iterator it = triMid.begin(); it != triMid.end(); ++it) {
			hasSolution = hasSolution && it->second<2;
			for (int i=0; i<all.size(); i++) {
				hasSolution = hasSolution && all[i].front()!=it->first && all[i].back()!=it->first;
			}
		}

		map<char, int> startsWith;
		map<char, int> endsWith;
		for (int i=0; i<dual.size(); i++) {
			string s = dual[i];
			startsWith[s.front()]++;
			endsWith[s.back()]++;
		}
		for (int i=0; i<tri.size(); i++) {
			string s = tri[i];
			startsWith[s.front()]++;
			endsWith[s.back()]++;
		}
		for (map<char, int>::iterator it=startsWith.begin(); it!=startsWith.end(); ++it) {
			hasSolution = hasSolution && it->second < 2;
		}
		for (map<char, int>::iterator it=endsWith.begin(); it!=endsWith.end(); ++it) {
			hasSolution = hasSolution && it->second < 2;
		}
		
		long long res = 0;
		if (hasSolution) {
			int components = countComponents(all);
			res = factorial(components);
			map<char, int> uniCounts;
			for (int i=0; i<uni.size(); i++) {
				uniCounts[uni[i].front()]++;
			}
			for (map<char, int>::iterator it = uniCounts.begin(); it != uniCounts.end(); ++it) {
				res = (res * factorial(it->second)) % M;
			}
		}

		cout << "Case #"<<t <<": " << res << endl;
	}
	return 0;
}