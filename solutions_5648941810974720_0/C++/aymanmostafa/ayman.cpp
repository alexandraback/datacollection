//============================================================================
// Name        : ayman.cpp
// Author      : Ayman Mostafa
// Email       : ayman93live@hotmail.com
// Version     : v5.0
//============================================================================

#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
#include <functional>
#include <numeric>

using namespace std;

#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define clr(v,d) memset(v,d,sizeof(v));

const double PI = 2 * acos(0.0);
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
void fastInOut();

long long pwr(long long base, long long power) {
	long long res = 1;
	while (power) {
		if (power & 1)
			res *= base;
		base *= base;
		power >>= 1;
	}
	return res;
}
int comp_double(double a, double b) {
	if (fabs(a - b) <= 1e-10)
		return 0;
	return a < b ? -1 : 1;
}
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

//##########################################################################################
//###################################MAIN FUNCTION##########################################
//##########################################################################################
int main() {
#ifndef ONLINE_JUDGE
	freopen("A-small-attempt1.in", "rt", stdin);
	freopen("output.out", "wt", stdout);
#endif
	fastInOut();
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
	int t, iii = 1;
	string s;
	cin >> t;
	vector<int> v;
	while (t--) {
		cin >> s;
		cout << "Case #" << iii++ << ": ";
		int arr[26] = { 0 };
		int res[10] = { 0 };
		for (auto i : s)
			arr[i - 'A']++;
		//0**
		if (arr['Z' - 'A'] <= arr['E' - 'A'] && arr['Z' - 'A'] <= arr['R' - 'A']
				&& arr['Z' - 'A'] <= arr['O' - 'A']) {
			res[0] += arr['Z' - 'A'];
			arr['E' - 'A'] -= arr['Z' - 'A'];
			arr['R' - 'A'] -= arr['Z' - 'A'];
			arr['O' - 'A'] -= arr['Z' - 'A'];
			arr['Z' - 'A'] = 0;
		}
		//2**
		if (arr['W' - 'A'] <= arr['T' - 'A']
				&& arr['W' - 'A'] <= arr['O' - 'A']) {
			res[2] += arr['W' - 'A'];
			arr['T' - 'A'] -= arr['W' - 'A'];
			arr['O' - 'A'] -= arr['W' - 'A'];
			arr['W' - 'A'] = 0;
		}
		//4**
		if (arr['U' - 'A'] <= arr['F' - 'A'] && arr['U' - 'A'] <= arr['O' - 'A']
				&& arr['U' - 'A'] <= arr['R' - 'A']) {
			res[4] += arr['U' - 'A'];
			arr['F' - 'A'] -= arr['U' - 'A'];
			arr['O' - 'A'] -= arr['U' - 'A'];
			arr['R' - 'A'] -= arr['U' - 'A'];
			arr['U' - 'A'] = 0;
		}
		//5**
		if (arr['F' - 'A'] <= arr['I' - 'A'] && arr['F' - 'A'] <= arr['V' - 'A']
				&& arr['F' - 'A'] <= arr['E' - 'A']) {
			res[5] += arr['F' - 'A'];
			arr['I' - 'A'] -= arr['F' - 'A'];
			arr['V' - 'A'] -= arr['F' - 'A'];
			arr['E' - 'A'] -= arr['F' - 'A'];
			arr['F' - 'A'] = 0;
		}
		//6**
		if (arr['X' - 'A'] <= arr['S' - 'A']
				&& arr['X' - 'A'] <= arr['I' - 'A']) {
			res[6] += arr['X' - 'A'];
			arr['S' - 'A'] -= arr['X' - 'A'];
			arr['I' - 'A'] -= arr['X' - 'A'];
			arr['X' - 'A'] = 0;
		}
		//7**
		if (arr['S' - 'A'] <= arr['E' - 'A'] / 2
				&& arr['S' - 'A'] <= arr['V' - 'A']
				&& arr['S' - 'A'] <= arr['N' - 'A']) {
			res[7] += arr['S' - 'A'];
			arr['E' - 'A'] -= arr['S' - 'A'];
			arr['E' - 'A'] -= arr['S' - 'A'];
			arr['V' - 'A'] -= arr['S' - 'A'];
			arr['N' - 'A'] -= arr['S' - 'A'];
			arr['S' - 'A'] = 0;
		}
		//8**
		if (arr['G' - 'A'] <= arr['E' - 'A'] && arr['G' - 'A'] <= arr['I' - 'A']
				&& arr['G' - 'A'] <= arr['H' - 'A']
				&& arr['G' - 'A'] <= arr['T' - 'A']) {
			res[8] += arr['G' - 'A'];
			arr['E' - 'A'] -= arr['G' - 'A'];
			arr['I' - 'A'] -= arr['G' - 'A'];
			arr['H' - 'A'] -= arr['G' - 'A'];
			arr['T' - 'A'] -= arr['G' - 'A'];
			arr['G' - 'A'] = 0;
		}
		v.clear();
		v.push_back(arr['T' - 'A']);
		v.push_back(arr['H' - 'A']);
		v.push_back(arr['R' - 'A']);
		sort(all(v));
		//3**THREE
		if (v[0] <= arr['T' - 'A'] && v[0] <= arr['H' - 'A']
				&& v[0] <= arr['R' - 'A'] && v[0] <= arr['E' - 'A']) {
			if (v[0] * 2 <= arr['E' - 'A']) {
				res[3] += v[0];
				arr['T' - 'A'] -= v[0];
				arr['H' - 'A'] -= v[0];
				arr['R' - 'A'] -= v[0];
				arr['E' - 'A'] -= (v[0] * 2);
			}
		}
		//--------------------
		//9***
		if (arr['N' - 'A'] >= arr['I' - 'A'] * 2
				&& arr['I' - 'A'] <= arr['E' - 'A']) {
			res[9] += (arr['I' - 'A']);
			arr['N' - 'A'] -= arr['I' - 'A'];
			arr['N' - 'A'] -= arr['I' - 'A'];
			arr['E' - 'A'] -= arr['I' - 'A'];
		}
		//---------------
		v.clear();
		//1**ONE
		v.push_back(arr['O' - 'A']);
		v.push_back(arr['N' - 'A']);
		v.push_back(arr['E' - 'A']);
		sort(all(v));
		if (v[0] <= arr['N' - 'A'] && v[0] <= arr['E' - 'A']
				&& v[0] <= arr['O' - 'A']) {
			res[1] += v[0];
			arr['O' - 'A'] -= v[0];
			arr['N' - 'A'] -= v[0];
			arr['E' - 'A'] -= v[0];
		}
		string ress = "";
		for (int i = 0; i < 10; i++) {
			for (int k = 0; k < res[i]; k++)
				ress += (i + '0');
		}
		cout << ress << endl;
	}
}
void fastInOut() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
}
