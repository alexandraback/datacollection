#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <sstream>

using namespace std;
int main() {
	int T;
	int A;
	int B;
	cin >> T;
	char *ns;
	int cnt;
	int l;
	int n;
	string s;
	string ts;
	char charS[2];
	bool exists[2000010];
	ns = (char*) malloc(sizeof(char) * 10);
	for (int i = 1; i <= T; ++i) {
		cnt = 0;
		cin >> A >> B;
		sprintf(ns, "%d", A);
		l = strlen(ns);
		for (n = A; n < B; n++) {
			sprintf(ns, "%d", n);
			s.assign(ns);
			memset(exists,0,sizeof(exists));
			for (int j = 0; j < l - 1; j++) {
				charS[0] = s.at(0);
				charS[1] = '\0';
				ts = s.substr(1, l - 1);
				ts.append(charS);
				long long int lli = atoll(ts.c_str());
				//cout << "<"<<n<<">"<<ts <<"-"<<(lli > n && lli <= B && n>=A )<< endl;
				if (lli > n && lli <= B && exists[lli]==false) {
					cnt++;
					exists[lli]=true;
				}
				s = ts;
			}
		}
		cout << "Case #" << i << ": " << cnt << endl;
	}
	return 0;
}
