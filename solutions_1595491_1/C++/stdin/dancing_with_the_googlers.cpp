#include <iostream>
using namespace std;

int main()
{
	int T;
	
	cin >> T;
	
	for (int i=1; i<=T; i++) {
		int N, S, p;
		
		cin >> N >> S >> p;
		int surprising=0, both=0;
		for (int j=0; j<N; j++) {
			int t;
			cin >> t;
			if ((t >= 2*(p-1)+p && t >= 1) || (t >= 3*p && t == 0))
				both++;
			else if (t >= 2*(p-2)+p && t >= 2)
				surprising++;
		}
		
		int res = both + min(S, surprising);
		
		cout << "Case #" << i << ": " << res << endl;
	}
}
