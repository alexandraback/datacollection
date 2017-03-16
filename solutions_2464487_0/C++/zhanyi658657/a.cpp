#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include<iostream>
#include<fstream>
using namespace std;
#include <iostream>   
#include<algorithm>
#define INF 100000000    
using namespace std;  
const double PI = acos(-1.0);
bool ok( unsigned __int64 r, unsigned __int64 t, unsigned __int64 mid)
{
	double r_ = (double)r;
	double t_ = (double)t;
	double mid_ = (double)mid;
	double sum = r_ * 2 * mid_ + (2 * mid_ * mid_ - mid_);
	return (sum <= t);
}
void solve()
{
	unsigned __int64 r, t;
	scanf("%I64d%I64d%", &r, &t);
	unsigned __int64 left = 0;
	unsigned __int64 right = t;
	while(left <= right) {
		unsigned __int64 mid = (left + right) / 2;
		if(ok(r, t, mid)) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	if(ok(r, t, left - 1)) {
		cout<<left - 1<<endl;
	} else {
		cout<<left<<endl;
	}

}
int main()
{
	//freopen("data.txt", "r", stdin);
	freopen("A-small-attempt2.in", "r", stdin);
	freopen("A-small-attempt2.out", "w", stdout);
	int t = 0;
	scanf("%d", &t);

	for(int i = 0;i < t;++i) {
		cout<<"Case #"<<i + 1<<": ";
		solve();
	}
	return 0;
}