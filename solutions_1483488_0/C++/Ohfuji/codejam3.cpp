#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <string.h>
#include <boost/regex.hpp>

using namespace std;

int A;
int B;

inline void splitn( int n, vector<int>& nums )
{
	while ( n > 0 ) {
		nums.push_back(n%10);
		n /= 10;
	}
}
inline int rebuild( vector<int>& nums, int s)
{
	int num = 0;
	for ( int i = 0; i < nums.size(); i++ ) {
		num *= 10;
		num += nums[s--];
		if ( s < 0 ) s = nums.size() - 1;
	}
	return num;
}

int check_m(int n)
{
	vector<int> nums;
	splitn(n, nums);
	set<int> done;
	for ( int i = 0; i < nums.size(); i++ ) {
		int m = rebuild( nums, i);
		if ( n < m && m <= B ) { 
			done.insert( m);
		}
	}
	return done.size();
}


int solve()
{
	int cnt = 0;
	for ( int i = A; i <= B; i++ ) {
		if ( i < 10 ) continue;
		cnt += check_m(i);
	}
	return cnt;
}

int main(int argc, char* argv[])
{
	int	casenum;
	cin >> casenum;
	for ( int i = 1; i <= casenum; i++ ) {
		cin >> A >> B;
		cout << "Case #" << i << ": " << solve() << endl;
	}

	return 0;
}
