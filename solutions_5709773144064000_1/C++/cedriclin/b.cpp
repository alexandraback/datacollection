#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>

using namespace std;

typedef double ld;

const ld eps = 1e-9;

// c/(2.0) + c/(2.0+f) + c/(2.0+2f) + ...

int main(){
	int t; cin >> t;
	for (int zz = 1; zz <= t; zz++){
		ld c, f, x;
		cin >> c >> f >> x;
		/*
		int cnt = 0;
		ld ct = 0;
		ld nt = ct;
		ld cf = 2.0;
		ld best = (x/cf);
		while (nt < x){
			ct = nt;
			ld nb = ct + (x-ct)/cf;
			if (best > nb) best = nb;
			nt = ct + (c/cf);
			cf += f;
			cnt++;
			cout << cnt << " " << cf << " " << nt << endl;
		}
		*/
		// ceiling x/c - 2/f -1
		int n = (int) (x/c - 2/f - eps);
		if (n < 0) n = 0;
		ld ans = 0;
		for (int i = 0; i < n; i++)
			ans += c/(2+i*f);
		ans += x/(2+n*f);
		printf("Case #%d: %.7f\n", zz, ans);
		//cout << "Case #" << zz << ": " << setprecision(7) << ans << endl;
	}
	
	return 0;
}
