#include <iostream>
#include <algorithm>

using namespace std;

typedef double ld;

int main(){
	int t; cin >> t;
	for (int zz = 1; zz <= t; zz++){
		int n; cin >> n;
		ld a[n];
		ld b[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		
		sort(a,a+n);
		sort(b,b+n);
		int y = 0, z = 0;
		for (int pos = 0; pos < n; pos++)
			if (a[pos] > b[y]) y++;
		for (int pos = 0; pos < n; pos++)
			if (b[pos] > a[z]) z++;
		z = n-z;
		cout << "Case #" << zz << ": " << y << " " << z << endl;
	}

	return 0;
}
