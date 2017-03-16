// fbhc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// fbhc.cpp : Defines the entry point for the console application.
//



#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<limits>
#include<climits>
#include<cmath>
#include<functional>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<typeinfo>
using namespace std;

typedef long long int ll;
typedef short int i16;
typedef unsigned long long int u64;
typedef unsigned int u32;
typedef unsigned short int u16;
typedef unsigned char u8;

string u[10] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };


int foo(string s) {

	int num = 0;
	for (int i = 0; i < s.length(); i++) {

		num += pow(10, s.length() - i - 1) * (s[i] - '0');
	}
	return num;
}
int l;
int min_diff = INT_MAX;
int min_a = INT_MAX;
string ac, bc;
int min_b = INT_MAX;
void solve(string a, string b, int idx) {

	//cout << a << " " << b << endl;
	if (idx == l) {
		//cout << a << " " << b << endl;
		int z = abs(foo(a) - foo(b));
		if (z < min_diff) {

			min_diff = z;
			min_a = foo(a);
			ac = a;
			bc = b;
			min_b = foo(b);
		}
		else if (z == min_diff) {

			if (min_a > foo(a)) {
				min_a = foo(a);
				ac = a, bc = b;
				min_b = foo(b);
			}
			else if (min_a == foo(a) && min_b > foo(b)) {
				bc = b;
				min_b = foo(b);
			}
		}
		return;
	}


	if (a[idx] != '?' && b[idx] != '?') {

		solve(a, b, idx + 1);
	}

	else if (a[idx] == '?' && b[idx] == '?') {

		for (char i = '0'; i <= '9'; i++) {
			for (char j = '0'; j <= '9'; j++) {
				string aa = a, bb = b;
				aa[idx] = i, bb[idx] = j;
				solve(aa, bb, idx + 1);
			}
		}
	}
	else if (a[idx] != '?' && b[idx] == '?') {

		
			for (char j = '0'; j <= '9'; j++) {
				string bb = b;
				bb[idx] = j;
				solve(a , bb , idx + 1);
			}
		
	}
	else {

		
			for (char j = '0'; j <= '9'; j++) {
				string aa = a;
				aa[idx] = j;
				solve(aa , b, idx + 1);
			}
		
	}

}

int N;
map<string, int> fn, sn;
vector<pair<int, int> > L;
string fs[16], ss[16];

bool isSet(int m, int j) {

	
	int ans =  (((m) >> (j)) & 1);

//	cout << m<<" " <<(1<<j)<<" : "<< ans << endl;

	return ans;
}
int dp[1 << 17];
int solve(int mask) {

	//cout << mask << endl;
	if (mask == (1 << N) - 1){

		return 0;
	}
	if (dp[mask] != -1) return dp[mask];
	int msk1 = 0, msk2 = 0;
	for (int i = 0; i < N; i++) {

		if (!isSet(mask, i)) continue;
		msk1 |= 1<<L[i].first;
		msk2 |= 1<<L[i].second;
	}

	int ans = 0;
	
	for (int i = 0; i < N; i++) {

		if (isSet(mask, i)) {

			continue;
		}
		int nm = mask| (1 << i);
	//	cout << msk1 << "  " << L[i].first << " : " << msk2 << " : " << L[i].second<<endl;
		if (isSet(msk1, L[i].first) && isSet(msk2, L[i].second)) {

			//cout << "here\n";
			ans = max(ans, 1 + solve(nm));
		}
		else {
			
			ans = max(ans, solve(nm));
		}
	}
	dp[mask] = ans;
	return ans;

}
int maint()
{
	ofstream cout("out.txt");
	ifstream cin("f.in");

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {

		
		cin >> N;
		fn.clear();
		sn.clear();
		for (int i = 0; i < N; i++) {
			string f, s;
			cin >> f >> s;
			fn[f] = 1;
			sn[s] = 1;
			fs[i] = f;
			ss[i] = s;

		}

		int c;
		c = 0;
		for (auto x : fn) {

			fn[x.first] = c++;
		}

		c = 0;
		for (auto x : sn) {

			sn[x.first] = c++;
		}

		L.resize(N);

		for (int i = 0; i < N; i++) {

			L[i].first = fn[fs[i]];
			L[i].second = sn[ss[i]];
			//cout << L[i].first << " " << L[i].second << endl;
		}

	//	sort(L.begin(), L.end());

		/*int chain = 0;
		map<int, int> fo, so;
		for (int i = 0; i < N; i++) {

			if (fo.count(L[i].first) && so.count(L[i].second)) {

				chain++;
			}
			fo[L[i].first] = so[L[i].second] = 1;
		}*/
		memset(dp, -1, sizeof(dp));
		int chain = solve(0);
		cout << "Case #" << tc << ": ";
		cout << chain ;

		cout << '\n';
	}

	return 0;
}




int _tmain(int argc, _TCHAR* argv[])
{
	return maint();
	return 0;
}

