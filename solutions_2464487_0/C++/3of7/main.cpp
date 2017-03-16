#include <cmath>
#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

const long long MYMAX = 707106780 + 10000;
long long r, t;

bool cando(long long num)
{
    long long used = 2*r*num + num * (2*num - 1);
    if(used <= t) {
        return true;
    }
    return false;
}

long long upper_bound(long long lo, long long hi)
{
	while(lo < hi)
	{
		int mid = lo + (hi-lo+1LL)/2LL;
		if(cando(mid) == false)
		{
			hi = mid-1;
		}
		else
		{
			lo = mid;
		}
    }

	return lo;
}

int main() {
    int T;
    cin>>T;
    for(int casenum=1; casenum<=T; casenum++) {
        cin >> r >> t;
        long long mymax = std::min(t / r, 707106780LL + 100LL);
        long long ans = upper_bound(1, mymax);
        cout << "Case #" << casenum << ": " << ans << endl;
    }
    return 0;
}