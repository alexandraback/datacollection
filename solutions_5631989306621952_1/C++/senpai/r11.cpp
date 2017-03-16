#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <fstream>

using namespace std;

typedef long long ll;

int main() { 
	ofstream fout;
	fout.open ("ayylmao.txt");
	ifstream fin;
	fin.open ("A-large.in");

	int t; fin>>t;
	for(int i = 1; i <= t; i++) {
		string s; fin>>s;
		fout<<"Case #"<<i<<": ";
		string ans = "a";
		ans[0] = s[0];
		for(int j = 1; j < s.length(); j++) {
			if(s[j] >= ans[0]) {
				ans = s[j] + ans;
			}
			else {
				ans += s[j];
			}
		}
		fout<<ans<<endl;
	}
	return 0;
}