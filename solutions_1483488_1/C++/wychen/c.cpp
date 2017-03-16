#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FOREACH(i,c) for(typeof(c.begin()) i=(c).begin();i!=(c).end();++i)
#define REP(i,n) FOR(i,0,n)

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

int getbase(int a)
{
	int base=10;
	while(a >= base) {
		base*=10;
	}
	return base/10;
}

int getdigits(int a)
{
	int max=10, ans=1;
	while(a >= max) {
		max*=10;
		ans++;
	}
	return ans;
}

int rotate(int a, int base)
{
	return (a/base) + 10*(a%base);
}

void solve()
{
	int A, B;
	cin >> A >> B;
	int count=0;
	int digits = getdigits(A);
	int base = getbase(A);
	FOR(n, A, B+1) {
		int cur = n;
		//cout << "at " << n;
		set<int> seen;
		REP(j, digits-1) {
			int next = rotate(cur, base);
			if( (n<next) && (next<=B) && seen.count(next)==0) {
				assert(next>=base);
				seen.insert(next);
				count++;
				//cout << " [" << next << "]";
			} else {
				//cout << " " << next;
			}
			cur = next;
		}
		//cout << endl;
	}
	cout << count;
}

int main()
{
	assert(10==getbase(10));
	assert(10==getbase(99));
	assert(100==getbase(100));
	assert(1000==getbase(1000));
	assert(100000000==getbase(123456789));
	
	assert(2==getdigits(10));
	assert(2==getdigits(99));
	assert(3==getdigits(100));
	
	int T;
	cin >> T;
	for(int i=0;i<T;i++) {
		cout << "Case #" << (i+1) << ": ";
		solve();
		cout << endl;
	}
}
