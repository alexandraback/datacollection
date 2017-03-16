#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <sstream>
#include <utility>
#include <map>
#include <set>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int) (n); ++i)
#define fore(i, a, b) for(int i = (int) (a); i < (int) (b); ++i)

#define ll long long
#define ld long double
#define PLL pair <ld, ld>
#define PII pair <int, int>
#define pb push_back
#define sz size

const ld EPS = 1e-9;
const int MAXN = 2010000;
const int INF = (int)(2e9 + 1e-9);

bool us[MAXN];
vector <int> v[MAXN];

int main()
{
    freopen("input.txt","rt", stdin);
    freopen("output.txt", "wt", stdout);    

	memset(us, 0, sizeof us);

	fore(i, 1, MAXN) {
		int x = i, k = 0, mul = 1;

		while (x) {
			++k;
			mul *= 10;
			x /= 10;
		}
		
		mul /= 10;
		
		us[i] = 1;

		int div = 10;

		int num = i;

		forn(j, k){
			int s = i / div, f = i % div;
			num = f * mul + s;


			if (f > div / 10 - 1 && !us[num]) {
				us[num] = 1;
				v[i].pb(num);
			}

			mul /= 10;
			div *= 10;
		}

		us[i] = 0;

		//cout << i << ": ";
		forn(j, v[i].size()){
			us[v[i][j]] = 0;
			//cout << v[i][j] << " ";
		}

		//cout << endl;
	}
	
	int tk;
	scanf("%d\n", &tk);

	fore(tn, 1, tk + 1){
		int a, b;
		cin >> a >> b;

		int ans = 0;
		fore(i, a, b + 1){
			forn(j, v[i].size()){
				if (v[i][j] >= a && v[i][j] <= b) ++ans;
			}
		}

		ans /= 2;

		printf("Case #%d: %d\n", tn, ans);
	}

	
	
	return 0;
}

