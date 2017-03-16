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

static bool p(int i) {
	std::stringstream ss;
	ss << i;
	string s( ss.str() );
	std::reverse( s.begin(), s.end() );
	return s == ss.str();
}

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

	vector<int> fns;

	for(int i = 1; i < 35; ++ i) {
		if( p(i) && p(i*i) ) fns.push_back(i*i);
	}


	for(int case_num = 1; case_num <= T; ++case_num)
	{
		int mn, ms;
		cin >> mn >> ms;
		vector<int>::iterator it = fns.begin();
		while( (it != fns.end() ) && (*it < mn) ) ++it;
		int ans = 0;
		while( (it != fns.end() ) && (*it <= ms) ) ++it, ++ans;
		cout << "Case #" << case_num << ": " << ans << endl;
	}
 	return 0;
}
