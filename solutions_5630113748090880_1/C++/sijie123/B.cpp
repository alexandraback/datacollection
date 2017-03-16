#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("B-large.in", "r", stdin);
	freopen ("B-large-out.txt","w",stdout);
	bool multi[2505];
	int tc;
	cin >> tc;
	for (int z = 1; z <= tc; z++) {
		for (int i =0 ; i < 2505; i++) {
			multi[i] = false;
		}
		int size;
		cin >> size;
		for (int i = 0; i < 2*size-1;i++) {
			for (int j = 0; j < size; j++) {
				int temp;
				cin >> temp;
				if (multi[temp]) multi[temp] = 0;
				else multi[temp] = 1;
			}
		}
		printf("Case #%d:", z);
		for (int i = 0; i < 2505; i++) {
			if (multi[i]) cout << " " << i;
		}
		cout << "\n";


		
	}

	
	return 0;
}
