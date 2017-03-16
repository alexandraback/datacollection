// 3.cpp
//

#include <iostream>
#include <string>
#include <cstring>
#include <set>
using namespace std;


int main()
{
	int T;
	int A, B;
	int n, m;
	long long ans;
	char nn[16], mm[16];
	int len, i;
	set<int> s;

	cin >> T;
	for(int t=1 ; t<=T ; ++t) {
		cin >> A >> B;
		
		ans = 0;
		for(n = A ; n < B ; ++n) {
			itoa(n, nn, 10);
			len = strlen(nn);
			s.clear();
			for(i=0 ; i<len-1 ; ++i) {
				if( nn[len-i-1] == '0' || 
					nn[0] > nn[len-i-1] )	continue;

				strncpy(mm, nn+len-i-1, i+1);
				strncpy(mm+i+1, nn, len-i-1);
				mm[len] = 0;
				m = atoi(mm);

				if(n < m && m <= B)
					s.insert(m);
			}
			ans += s.size();
		}

		cout << "Case #" << t << ": " << ans << endl;
	}

	return 0;
}