//#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <fstream>
using namespace std;
int ktyp[40];
int kl[40];
int parent[20];
int used[20];
int which[20];
map<pair<vector<int>,int> ,int> zmap;
map<int,vector<int> > keysin;
ifstream cin("D-small-attempt2.in");
ofstream cout("D-small2.out");

int K,N;
bool fd;

int rec(vector<int> zvec, int nused, int par) {
	if (zmap.find(make_pair(zvec,nused)) != zmap.end()) return zmap[make_pair(zvec,nused)];
	if (nused == N) {fd = true; return 0; }
	if (fd) return 0;
	bool found = false; int res = 0;
	for (int i=0; i<N; i++) 
	if (!used[i] && kl[which[i]] > 0) {
		found = true;
		used[i] = 1; kl[which[i]]--; 
		vector<int> zvec2; vector<int>::iterator it = zvec.begin();
		vector<int>::iterator it2;
		it2 = keysin[i].begin();
		while (it2!=keysin[i].end() && it!=zvec.end()) {
			if (*it < *it2) { zvec2.push_back(*it); it++; continue; }
			if (*it2 < *it) { kl[*it2]++; zvec2.push_back(*it2); it2++; continue; }
			if (*it2 == *it) { kl[*it2]++; it++; it2++; continue; }
		}
		while (it2<keysin[i].end()) {kl[*it2]++; zvec2.push_back(*it2); it2++; }
		while (it<zvec.end()) { zvec2.push_back(*it); it++; }
		
		int temp = rec(zvec2, nused+1, i);
		for (it2 = keysin[i].begin(); it2!=keysin[i].end(); it2++) kl[*it2]--;
		if (temp > res) { res = temp; parent[i] = par; }
		used[i] = 0; kl[which[i]]++; if (fd==true) break;
	}
	if (!found) { zmap[make_pair(zvec,nused)] = 0; return 0; } else { zmap[make_pair(zvec,nused)] = res+1; return res+1; }
}

int main() {
int T;

cin >> T;
for (int tt=1; tt<=T; tt++) { zmap.clear(); keysin.clear(); fd = false;
cout << "Case #"<<tt<<": ";
cin >> K >> N;
for (int i=0; i<20; i++) { used[i] = 0; parent[i] = -1; }
for (int i=0; i<40; i++) { ktyp[i] = 0; kl[i] = 0; }
vector<int> start;
for (int i=0; i<K; i++) { int l; cin >> l; ktyp[l-1]++; kl[l-1]++; }
for (int i=0; i<N; i++) { 
int Ti,Ki; cin >> Ti >> Ki; start.push_back(Ti-1);
which[i] = Ti-1;
for (int j=0; j<Ki; j++) { int l; cin >> l; keysin[i].push_back(l-1); }
sort(keysin[i].begin(), keysin[i].end());
}
sort(start.begin(), start.end());
vector<int>::iterator it = start.begin();
for (int i=0; i<40; i++) if (ktyp[i] != 0) { while ((*it == i) && ktyp[i]>0 && start.size()>0) { start.erase(it); ktyp[i]--; } while(*it < i) it++; if (it==start.end()) break; }

int reso = rec(start,0,-2);

if (reso < N) { cout << "IMPOSSIBLE" << endl; } else {
	bool found=true; int indp = -2;
	while (found) {
	found = false;
	for (int i=0; i<N; i++) if (parent[i] == indp) { cout << i+1 << " "; indp = i; found = true; break; }
	}
	for (int i=0; i<N; i++) if (parent[i] == -1) { cout << i+1 << " "; }
	cout << endl;
}
}
return 0;
}
