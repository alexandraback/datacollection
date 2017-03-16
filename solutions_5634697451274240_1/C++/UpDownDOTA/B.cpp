#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("B-large.in");
ofstream fout("output.txt");

int main() {
	int n;
	fin>>n;
	for (int i=0; i<n; i++) {
		string s;
		fin>>s;
		int k = 0;
		int ans = 0;
		char current='x';
		while (1) {
			if (s[k] != current) {
				current = s[k];
				ans++;
			}
			k++;
			if (k==s.size()) {
				if (current=='+' && ans) ans--;
				break;
			}
		}
		fout<<"Case #"<<i+1<<": "<<ans<<endl;
	}
}