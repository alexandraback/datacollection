#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	ifstream inf("A-small-attempt0.in");
	ofstream outf("output.txt");
	int t, n;
	string s;
	inf >> t;
	for (int k = 0; k < t; ++k){
		inf >> n >> s;
		int f = 0, c = 0;
		for (int i = 0; i <= n; ++i){
			if (i <= c) c += (int)s[i] - 48;
			else{
				f += i - c;
				c = i + (int)s[i] - 48;
			}
		}
		outf << "Case #" << k + 1 << ": " << f << '\n';
	}
}