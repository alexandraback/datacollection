#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>

using namespace std;

int N;

map<int, string> m1;
vector<int> v;

int get_value(const string& s)
{
	int t = 0;
	for(int i=0; i<N; i++) {
		if(s[i]=='1')
			t += v[i];
	}
	return t;
}

void print(const string& s)
{
	vector<int> rv;
	for(int i=0; i<N; i++) {
		if(s[i]=='1')
			rv.push_back(v[i]);
	}
	cout << rv[0];
	for(int i=1; i<rv.size(); i++)
		cout << " " << rv[i];
	cout << endl;
}

bool dfs_pop(string& s, int level)
{
	if(level==N) {
		int value = get_value(s);
		if(m1.find(value)!=m1.end()) {
			print(m1[value]);
			print(s);
			return true;
		}
		else if (value!=0) {
			m1[value] = s;
			return false;
		}
	}
	s[level] = '0'+('1'-s[level]);
	if(dfs_pop(s, level+1)) return true;
	s[level] = '0'+('1'-s[level]);
	if(dfs_pop(s, level+1)) return true;
}

int main()
{
	int T;
	cin >> T;
	for(int caseID=1; caseID<=T; caseID++) {
		cout << "Case #" << caseID << ":" << endl;
		cin >> N;
		v = vector<int>(N);
		m1.clear();
		for(int i=0; i<N; i++)
			cin >> v[i];
		string s(N,'0');
		bool found = dfs_pop(s, 0);
		if(!found)
			cout << "Impossible" << endl;
	}

	return 0;
}
