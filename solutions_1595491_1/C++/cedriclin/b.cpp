#include <iostream>

using namespace std;

int tot[256];

int main(){
	int t; cin >> t;
	for (int zz = 1; zz <= t; zz++){
		int n, s, p;
		cin >> n >> s >> p;
		for (int i = 0; i < n; i++)
			cin >> tot[i];
		int good = 0, ok = 0;
		for (int i = 0; i < n; i++){
			if ((tot[i]+2)/3 >= p) good++;
			else if (tot[i] >= p && (tot[i]-p)/2 >= p-2) ok++;
		}
		int ans = good + min(ok,s);
		cout << "Case #" << zz << ": " << ans << endl;
	}
	
	return 0;
}
