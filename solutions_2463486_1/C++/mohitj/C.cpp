#include <cassert>
#include <string>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
#define SAMPLE_NAME "C"
	if( freopen(SAMPLE_NAME "-large.in", "rt", stdin) ) {
		freopen(SAMPLE_NAME "-large.out", "wt", stdout);
	} else 	if( freopen(SAMPLE_NAME "-small-attempt0.in", "rt", stdin) ) {
		freopen(SAMPLE_NAME "-small.out", "wt", stdout);
	} else ( freopen("test.txt", "rt", stdin) );

	int T;
	cin >> T;

/* Generated offline by code */
//static bool p(long long i) {
//	std::stringstream ss;
//	ss << i;
//	string s( ss.str() );
//	std::reverse( s.begin(), s.end() );
//	return s == ss.str();
//}
//
//int main()
//{ 
//	for(long long i = 1; i < 10000000; ++i) {
//		if( p(i) && p(i*i) ) {cout << (i*i) << ',' << ' '; cerr << i << endl; }
//	}
//        cout << endl;
//	return 0;
//}

	long long fns[] = {1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944,
						1002001, 1234321, 4008004, 100020001, 102030201,
						104060401, 121242121, 123454321, 125686521, 400080004,
						404090404, 10000200001, 10221412201, 12102420121,
						12345654321, 40000800004, 1000002000001, 1002003002001,
						1004006004001, 1020304030201, 1022325232201, 1024348434201,
						1210024200121, 1212225222121, 1214428244121, 1232346432321,
						1234567654321, 4000008000004, 4004009004004 };

	for(int case_num = 1; case_num <= T; ++case_num)
	{
		long long int mn, ms;
		cin >> mn >> ms;
		long long *it = &fns[0];
		long long *last = &fns[0] + sizeof fns / sizeof fns[0];

		while( (it != last ) && (*it < mn) ) ++it;
		int ans = 0;
		while( (it != last ) && (*it <= ms) ) ++it, ++ans;
		cout << "Case #" << case_num << ": " << ans << endl;
	}
 	return 0;
}
