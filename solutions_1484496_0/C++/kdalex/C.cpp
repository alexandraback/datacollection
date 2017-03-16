#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

#define EPS 1e-6



void once() {
	int n;
	vector<int> s;
	multimap<int, unsigned int> m;
	cin >> n;
	s.resize(n);
	for(int i = 0; i < n; i++) 
		cin >> s[i];	
	unsigned int m1 = 0, m2 = 0;
	for(unsigned int mask = 1; mask < (1 << n); mask++) {
		int sc = 0;
		for(int i = 0; i < n; i++)
			if(mask & (1 << i))
				sc += s[i];
		if(m.count(sc) == 0) {
			m.insert(pair<int, unsigned int>(sc, mask));
			continue;
		}
		
		pair<multimap<int, unsigned int> :: iterator, multimap<int, unsigned int> :: iterator> rg = m.equal_range(sc);
		for(multimap<int, unsigned int> :: iterator it = rg.first; it != rg.second; it++)
			if(((*it).second & mask) == 0) {
				m1 = mask;
				m2 = (*it).second;
				break;
			}
		if(m1 != 0)
			break;
		m.insert(pair<int, unsigned int>(sc, mask));
		
	}
	if(m1 == 0) {
		cout << endl << "Impossible" << endl;
		return;
	}
	cout << endl;
	for(int i = 0; i < n; i++)
		if(m1 & (1 << i))
			cout << s[i] << " ";
	cout << endl;
	for(int i = 0; i < n; i++)
		if(m2 & (1 << i))
			cout << s[i] << " ";

}

int main() {
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		once();
		cout << endl;
	}
	return 0;
}