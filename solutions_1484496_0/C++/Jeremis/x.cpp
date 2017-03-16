#include <iostream>
#include <vector>
#include <set>
#include <memory.h>
#include <map>
#include <algorithm>
#include <string>
using namespace std;



int main() {
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int t;
	scanf("%d",&t);
	for (int z = 1 ; z <= t; z++) {
		cout << "Case #" << z << ":" << endl;
	int n;
	scanf("%d",&n);
	int s;
	map <int, int> m;
	vector <int> v;
	v.resize(n);
	for (int i=0;i<n;i++)
		scanf("%d",&v[i]);
	
	m[v[0]]=0;
	
	bool ok = false;
	for (int i=1;i<n;i++) {
		map <int, int>::iterator it = m.end(); --it;
		while (true) {
			pair < map <int, int>::iterator , bool > ins = m.insert(make_pair(it->first + v[i],it->first));
			if (!ins.second) {
				//backway
				while (ins.first->second) {
					cout << ins.first->first - ins.first->second << " ";
					ins.first = m.find(ins.first->second);
					if (ins.first == m.end()) cout << endl <<  "ERR1" << endl;
				}
				cout << ins.first->first - ins.first->second << endl;

				while (it->second) {
					cout << it->first - it->second << " ";
					it = m.find(it->second);
					if (it == m.end()) cout << endl <<  "ERR2" << endl;
				}
				cout << it->first-it->second << " " << v[i] << endl;
				ok = true;
				break;
			}
			if (it==m.begin()) break;
			it--;
		}
		if (ok) break;
		pair < map <int, int>::iterator , bool > ins = m.insert(make_pair(v[i],0));
		if (!ins.second) {
			while (ins.first->second) {
				cout << ins.first->first - ins.first->second << " ";
				ins.first = m.find(ins.first->second);
				if (ins.first == m.end()) cout << endl <<  "ERR1" << endl;
			}
			cout << ins.first->first - ins.first->second << endl;	
			cout << v[i] << endl;
			ok = true;
			break;
		}
	}
	if (!ok) cout << "Impossible" << endl;
	}
}