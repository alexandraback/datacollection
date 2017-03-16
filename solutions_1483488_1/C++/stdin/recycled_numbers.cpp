#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <sstream>
using namespace std;

inline int nr_of_digits(int x) {
	int res=0;
	while (x != 0) {
		res++;
		x/=10;
	}
	
	return res;
}

int main()
{
	int T;

	cin >> T;

	for (int i=1; i<=T; i++) {
		int A, B;
		set<pair<int,int> > visited;

		cin >> A >> B;

		for (int j=A; j<=B; j++) {
			stringstream ss;
			ss << j;
			string s = ss.str();
			for (string::size_type ind=1; ind<s.size(); ind++) {
				string sec = s.substr(ind,s.size()-ind)+s.substr(0,ind);
				int nr2=atoi(sec.c_str());
				if (nr_of_digits(nr2) == (int)s.size()
					&& nr2 < j && A <= nr2 && nr2 <= B) {
					visited.insert(make_pair(j, nr2));
				}
			}
		}

		cout << "Case #" << i << ": " << visited.size() << endl;
	}
}
