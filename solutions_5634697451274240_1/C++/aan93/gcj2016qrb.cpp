#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
ifstream in("in.txt");
ofstream out("out.txt");
int main()
{
	int t;
	in >> t;
	string s;
	for(int i=1;i<=t;i++) {
		in >> s;
		string z = "";
		z += s[0];
		for (int j=1;j<(int)s.size();j++) {
			if (s[j] != s[j-1]) {
				z += s[j];
			}
		}
		int ans = (int)z.size();
		if (z[(int)z.size()-1] == '+')
			ans--;
		out << "Case #" << i << ": " << ans << "\n";
	}
	return 0;
}
