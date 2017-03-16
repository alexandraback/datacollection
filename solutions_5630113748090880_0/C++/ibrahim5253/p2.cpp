#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n; cin >> n;
		int count[2501];
		cout << "Case #" << i << ": ";
		memset(count,0,2501*sizeof(int));
		for (int j = 1; j <= 2*n-1; j++) {
			for (int k = 1; k<= n; k++) {
				int a;
				cin >> a;
				count[a] = (count[a]+1)%2;
			}
		}
		for (int j =1; j < 2501; j++) {
			if (count[j]==1)	cout << j << " ";
		}
		cout << "\n";
	}
}
