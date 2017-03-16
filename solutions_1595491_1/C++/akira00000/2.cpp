// 2.cpp
//

#include <iostream>
using namespace std;

const int MAX_N = 100;

int main()
{
	int T;
	int N, S, p;
	int t[MAX_N];
	int ans;

	cin >> T;
	for(int tc=1 ; tc<=T ; ++tc) {
		ans = 0;
		int i, k = 0;

		cin >> N >> S >> p;
		for(i=0 ; i<N ; ++i) {
			cin >> t[i];
			if(t[i] >= 3*p-2)	ans++;
			else if(t[i] >= 3*p-4 && t[i] <= 28 && t[i] >= 2)	k++;
		}
		ans += min(k, S);

		cout << "Case #" << tc << ": " << ans << endl;
	}
	
	return 0;
}