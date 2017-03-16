#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin >> T;

	for(int t = 0; t < T; t++){
		cout << "Case #" << t+1 << ": ";
		long long b, m;
		cin >> b >> m;
		if(m > (1ll<<(b-2)))
			cout << "IMPOSSIBLE" << endl;
		else{
			cout << "POSSIBLE" << endl;
			for(int i = 0; i < b; i++){
				for(int j = 0; j < b-1; j++){
					if(i < j)
						cout << 1;
					else
						cout << 0;
				}
				if(i != b-1 && (m == (1ll<<(b-2)) || (i != 0 && (m&(1ll<<(i-1))))))
					cout << 1;
				else
					cout << 0;
				cout << endl;
			}
		}
	}

	return 0;
}
