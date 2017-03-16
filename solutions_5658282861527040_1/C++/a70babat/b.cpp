//be name oo
#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <sstream>
#include <set>
#include <complex>
#include <iomanip>
#include <queue>

#define FOR(i, n) for(int i = 0; i < (n); i++)
#define SZ(x) ((int)x.size())
#define PB push_back
#define show(x) cerr << "#" << #x << ": " << x << endl
#define F first
#define S second
#define X real()
#define Y imag()

using namespace std;
typedef pair<int, int> pii;
typedef complex<double> point;

const int MAX_N = 50;

int a, b, k;
int num;
int last;

long long dp[MAX_N][2][2];

long long cal(int first, bool lessa, bool lessb){
	if(first == -1)
		return 1;
	long long &ret = dp[first][lessa][lessb];
	if(ret != -1)
		return ret;
	ret = 0;

	// bit first should be one
	if(first < last || (num & (1 << first))){
		if( (lessa || (a & (1 << first))) &&
			(lessb || (b & (1 << first))) )
				ret += cal(first - 1, lessa, lessb);
	}

	// bit first should be zero
	if(first < last || !(num & (1 << first))){
		if(lessa || (a & (1 << first)))
			ret += cal(first - 1, lessa, lessb || (b & (1 << first)));
		if(lessb || (b & (1 << first)))
			ret += cal(first - 1, lessa || (a & (1 << first)), lessb);
		ret += cal(first - 1, lessa || (a & (1 << first)), lessb || (b & (1 << first)));
	}

	return ret;
}

int main(){
	int num_test_case;
	cin >> num_test_case;
	for(int _test = 1; _test <= num_test_case; _test++){
		cout << "Case #" << _test << ": ";
		cin >> a >> b >> k;
		a--;
		b--;
		k--;
		long long ans = (a + 1);
		ans *= (b + 1);
		for(int i = 0; i < 30; i++)
			if(!(k & (1 << i))){
				last = i;
				num = k;
				num += (1 << i);
				memset(dp, -1, sizeof dp);
				ans -= cal(29, false, false);
			}
		cout << ans << endl;
	}
	return 0;
}

