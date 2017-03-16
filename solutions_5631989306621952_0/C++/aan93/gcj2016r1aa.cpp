#include <fstream>
#include <algorithm>
#include <string>
using namespace std;
ifstream in("in.txt");
ofstream out("out.txt");
int main()
{
	int t;
	in >> t;
	for (int i=1;i<=t;i++) {
		string s;
		in >> s;
		string v(""),u("");
		char z = s[0];
		for (int j=0;j<(int)s.size();j++) {
			if (s[j]<z) {
				u += s[j];
			} else {
				v += s[j];
				z = max(z, s[j]);
			}
		}
		reverse(v.begin(),v.end());
		out << "Case #" << i << ": " << v << u << "\n";
	}
	return 0;
}
