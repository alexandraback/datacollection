#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#pragma comment(linker, "/STACK:16777216")

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <stack>
#include <set>
#include <queue>
#include <numeric>
#include <algorithm>
#include <utility>
#include <bitset>
#include <cmath>
#include <sstream>
#include <functional>

#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a).size()

using namespace std; 

typedef long long int64;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector<double> vd;
typedef vector< vd > vvd;
typedef vector< string > vs;
typedef pair< int, int > pii;
typedef vector< pii > vpii;

bool isPalindrome(int64 a)
{
	vi digits;
	int cnt = 0;
	while (a)
	{
		digits.push_back(a % 10);
		a /= 10;
	}
	for (int i = 0; i < sz(digits) / 2; i++)
		if (digits[i] != digits[sz(digits) - i - 1])
			return false;
	return true;

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
	int64 ans[] = {1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004};
	
	//vector<int64> ans;
	//for (int64 i = 1; i <= 10000000; i++)
	//{
	//	if (isPalindrome(i) && isPalindrome(i * i))
	//		ans.push_back(i * i);
	//}
	//for (int i = 0; i < sz(ans); i++)
	//	cout << ans[i] <<  " ";
	int T = 0;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int ans_len = sizeof(ans) / sizeof(ans[0]);
		int64 a, b;
		cin >> a >> b;
		int cnt = 0;
		for (int i = 0; i < ans_len; i++)
			if (ans[i] >= a && ans[i] <= b)
				cnt++;
		cout << "Case #" << t + 1 << ": ";
		cout << cnt << endl;
	}

    return 0;
}