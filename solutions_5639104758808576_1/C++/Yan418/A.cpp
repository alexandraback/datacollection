#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	int n;
	ifstream inf("A-large.in");
	ofstream outf("A-large.out");
	inf >> n;
	//iostream::sync_with_stdio(false);
	for (int i = 1; i <= n; i++){
		int maxS;
		string s;
		inf >> maxS;
		inf >> s;
		int tot = 0,add = 0;
		for (int j = 0; j < s.size(); j++){
			if (j > tot + add && s[j]!='0') {
				add += j - tot - add;
			}
			tot += s[j] - '0';
		}
		outf << "Case #" << i << ": " << add << "\n";
	}


	return 0;
}