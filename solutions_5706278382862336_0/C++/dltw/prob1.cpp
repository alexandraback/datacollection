#include <iostream>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <numeric>
#include <iterator>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <math.h>

#define mp make_pair
#define pb push_back
#define sqr(x) ((x)*(x))
#define foreach(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef long long ll;

template<typename T> int size(const T &a) { return a.size(); } 


void process(void) {
    ll p, q, result = 1, result2 = 1, limit = pow(2, 40);
    scanf("%lld/%lld", &p, &q);
	double test = (double)p/q;
	ll p1 = p;
	ll r = (limit%q);
	bool flag = 0;
	double test2 = test;
	for (int i = 0; i < 40; ++i)
	{
		if(test2 !=1) {
		    test2 *= 2;
		    if (test2 > 1)
		    {
		    	test2 -=1;
		    }
		}
		else {
			flag = 1;
		}
	}
    if (!flag) {
    	cout << "impossible" <<endl;
    	return;
    }
    else{

		double lower = 0, upper = 1, mid = 0.5;
		while(mid != test) {
		    if (mid > test)
		    {
		    	upper = mid;
		    	result ++;
		    }
		    else{
		    	lower = mid;
	cout << result << endl;
return;

		    }
			mid = (lower + upper)/2;
		}

    	// ll scale = limit / q;
    	// p *= scale;
    	// ll up = limit;
    	// ll low = 0;
    	// ll middle = (up + low) / 2;
    	// while(middle != p){
    	// 	if (middle > p)
    	// 	{
    	// 		up = middle;
    	// 		result2++;
    	// 	}
    	// 	else{
    	// 		low = middle;
    	// 		// result ++;
    	// 	}
    	// 	middle = (up+low)/2;
    	// }
    	// cout << result << endl;
    }
	cout << result << endl;
	return;
}

int main(void)
{
	
  freopen("A.in","r",stdin);
  freopen("A2.out","w",stdout);
    // precalc();
    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
    }
}