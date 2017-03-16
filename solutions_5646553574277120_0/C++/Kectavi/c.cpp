#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>

#define forn(i,n) for(int i=0;i<n;i++)

using namespace std;

typedef long long ll;

typedef pair<int, int> Pll;

int main(void)
{

	ifstream cin("C-small-attempt1.in");//m.txt
	ofstream cout("C_small");

	int T;
	cin >> T;

	forn(i, T)
	{
		int C, D;
		ll V;
		cin >> C >> D >> V;

		vector<ll> coins;
		forn(j, D)
		{
			ll gp;
			cin >> gp;
			coins.push_back(gp);
		}

		ll addnum = 0;
		ll gsum = 0;
		int tc = 0;
		int cm = 0;
		forn(j, D)
		{
			if (j == 0 && cm==0 && coins[j] != 1) {
				addnum++;
				gsum += 1 * C;
				j--;
				cm = 1;
				continue;
			}
			gsum += C*coins[j];
			if (gsum >= V) break;
			if (gsum >= coins[j + 1]-1) continue;
			else{
				ll cc = gsum;
				int cv = -1;
				forn(z, 100){
					addnum++;
					cc = cc + (cc+1)*C;
					if (cc >= V) { tc = 1; break; }
					if ( cc >= coins[j + 1] - 1)  break;
				}
				gsum = cc;
			}
			if (tc == 1) break;
		}

		cout << "Case #" << i + 1 << ": " << addnum << endl;
	}
	return 0;
}