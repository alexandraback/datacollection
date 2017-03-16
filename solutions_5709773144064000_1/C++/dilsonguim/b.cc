#include <bits/extc++.h>
#include <iostream>
#include <iomanip>

using namespace std;

//#define NDEBUG
#ifdef NDEBUG
#define DEBUG if (false)
#else
#define DEBUG if (true)
#endif
#define WRITE(x) DEBUG { cout << (x) << endl; }
#define WATCH(x) DEBUG { cout << #x << " = " << (x) << endl; }
//#define ALL(x) (x).begin(), (x).end()
//#define FORN(i, a, b) for(typeof(b) i = (a); i < (b); ++i)
//#define FOREACH(i, c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int ntc;
	cin >> ntc;
	for(int tc = 0 ; tc < ntc; tc++){
		double c, f, x;
		cin >> c >> f >> x;
		
		double minimum_time = x / 2.0;
		double time_spent_building_farms = 0.0;
		double cookies_per_second = 2.0;
		const int max_farms = ceil(x / c);
		for(int num_farms = 1; num_farms <= max_farms; num_farms++){
			time_spent_building_farms += c / cookies_per_second;
			cookies_per_second += f;
			const double time_to_finish = time_spent_building_farms
				+ x / cookies_per_second;
			minimum_time = min(minimum_time, time_to_finish);
		}
		
		cout << "Case #" << (tc + 1) << ": ";
		cout << fixed << setprecision(7) << minimum_time << "\n";
	}
}
