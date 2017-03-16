#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i=0; i<t; ++i) {
		int n;
		set<int> s;
		cin >> n;
		for (int j=0; j<2*n-1; ++j) {
			int h;
			for (int k=0; k<n; ++k) {
				cin >> h;
				if (s.find(h)!=s.end()) {
					s.erase(h);
				}
				else
				{
					s.insert(h);
				}
			}
		}
		vector<int> v(s.begin(), s.end());
		cout << "Case #" << i+1 << ":";
		for (int j=0; j<v.size(); ++j)
			cout << " " << v[j];
		cout << endl; 
	}
}