#include <iostream>
#include <string>
using namespace std;
string s;

int main() {
	freopen("A.in", "r", stdin);
	freopen("B.txt", "w", stdout);
	int t;
	cin >> t;
	for(int ii=0;ii<t;ii++) {
		cin >> s;
		s = s + "+";
		int k = s.size();
		int cnt = 0;
		for(int i=0;i<k-1;i++) {
			if(s[i] == s[i+1]) continue;
			cnt ++;
		}
		cout << "Case #" << ii+1 << ": " << cnt << endl;
	}
}