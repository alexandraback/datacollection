#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

ll diff(ll a, ll b)
{
	return a < b ? b - a : a - b;
}

int l;
string a, b;

pair<ll, ll> goon(ll ia, ll ib, bool ma, int i)
{
	// go on
	++i;
	for (; i < l; ++i){
		ia *= 10;
		ib *= 10;
		auto ca = a[i];
		auto cb = b[i];
		int da = ca == '?' ? (ma ? 9 : 0) : (ca - '0');
		int db = cb == '?' ? (ma ? 0 : 9) : (cb - '0');
		ia += da;
		ib += db;
	}
	
	return make_pair(ia, ib);
}

int main()
{
	//freopen();
	//freopen();
	
	int t;
	cin >> t;
	for (int tc = 0; tc < t; ++tc){
		cin >> a >> b;
		l = a.size();
		
		ll ia = 0, ib = 0;
		bool ea = false, eb = false;
		bool ena = false, enb = false;
		
		for (int i = 0; i < l; ++i){
			ia *= 10;
			ib *= 10;
			
			auto ca = a[i];
			auto cb = b[i];
			if (ca == '?' && cb == '?')
			{
				ea = eb = true;
				continue; // = assume 0
			}
			if (ca == cb || ca == '?' || cb == '?')
			{
				// no conflict
				int d = ca == '?' ? (cb - '0') : (ca - '0');
				if (d != 9)
				{
					ea = ca == '?';
					eb = cb == '?';
				}
				if (d != 0)
				{
					ena = ca == '?';
					enb = cb == '?';
				}
				
				ia += d;
				ib += d;
				continue;
			}
			
			// CONFLICT
			vector<pair<ll, ll>> sols;
			int da = ca - '0';
			int db = cb - '0';
			ia += da;
			ib += db;
			bool ma = da < db;
			if (ma)
			{
				if (enb)
					sols.push_back(goon(ia, ib - 10, false, i));
			}
			else
			{
				if (ena)
					sols.push_back(goon(ia - 10, ib, true, i));
			}
			sols.push_back(goon(ia, ib, ma, i));
			if (ma)
			{
				if (ea)
					sols.push_back(goon(ia + 10, ib, false, i));
			}
			else
			{
				if (eb)
					sols.push_back(goon(ia, ib + 10, true, i));
			}
			
			pair<ll,ll> sol = sols[0];
			ll delta = diff(sol.first, sol.second);
			for (auto s : sols)
			{
				ll delta2 = diff(s.first, s.second);
				if (delta2 < delta)
				{
					delta = delta2;
					sol = s;
				}
			}
			ia = sol.first;
			ib = sol.second;
			break;
		}
		
		cout << "Case #" << (tc + 1) << ": " << setfill('0') << setw(l) << ia 
									  << " " << setfill('0') << setw(l) << ib << endl;
	}
}