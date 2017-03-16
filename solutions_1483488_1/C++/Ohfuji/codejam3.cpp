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


vector< set<int> >recycled;


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

void makeup(int n, set<int>&done)
{
	vector<int> nums;
	splitn(n, nums);
	done.clear();
	for ( int i = 0; i < nums.size(); i++ ) {
		int m = rebuild( nums, i);
		if ( n < m && m <= B ) { 
			done.insert( m);
		}
	}
}

void makeup()
{
	A = 0;
	B = 2000000;
	recycled.clear();
	for ( int i = A; i <= B; i++ ) {
		set<int> done;
		makeup( i, done);
		recycled.push_back(done);
	}
}

int solve()
{
	int cnt = 0;
	for ( int i = A; i <= B; i++ ) {
		set<int>::iterator e = recycled[i].end();
		for ( set<int>::iterator j = recycled[i].begin(); j != e; j++ ) {
			if ( *j <= B )
				cnt++;
		}
	}
	return cnt;
}

int main(int argc, char* argv[])
{
	makeup();

	int	casenum;
	cin >> casenum;
	for ( int i = 1; i <= casenum; i++ ) {
		cin >> A >> B;
		cout << "Case #" << i << ": " << solve() << endl;
	}

	return 0;
}
