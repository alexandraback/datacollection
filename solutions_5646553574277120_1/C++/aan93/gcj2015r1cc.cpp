#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;
ifstream in("in.txt");
ofstream out("out.txt");
int t,d;
long long int c,v;
int main()
{
	in >> t;
	for (int i=1;i<=t;i++) {
		in >> c >> d >> v;
		vector <long long int> a(d),b(0);
		for (int j=0;j<d;j++) {
			in >> a[j];
		}
		sort(a.begin(),a.end());
		long long int g = 0;
		int j = 0;
		while (g<v) {
			if ((j<d && g+1 < a[j]) || j>=d) {
				b.push_back(g+1);
				g += (g+1)*c;
			} else {
				g += a[j]*c;
				j++;
			}
		}
	out << "Case #" << i << ": " << (int)b.size() << "\n";
	}
	return 0;
}
