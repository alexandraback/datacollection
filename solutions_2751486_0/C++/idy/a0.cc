#include <iostream>
#include <string>
using namespace std;

bool is_con(char x) {
	return !(x=='a' || x=='e' || x=='i' || x=='o' || x=='u');
}
bool good(const string& s, int n) {
	int con = 0;
	for(size_t i=0; i<s.size(); ++i) {
		if (is_con(s[i]))
			con ++;
		else
			con = 0;
		if(con >= n)
			return true;
	}
}
int main() {
	int casn;
	cin >> casn;
	for(int casi=1; casi <= casn; ++casi) {
		string name;
		int n, cnt = 0;
		cin >> name >> n;
		int sz = name.size();
		for(size_t i=0; i<sz; ++i) {
			for(size_t j=i+1; j<=sz; ++j) {
				string subs = name.substr(i, j-i);
				if(good(subs, n))
					cnt ++;
			}
		}
		cout << "Case #" << casi << ": " << cnt << endl;
	}
	return 0;
}