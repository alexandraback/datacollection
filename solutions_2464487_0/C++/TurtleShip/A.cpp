#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

typedef long long ll;

const double PI = 4.0 * atan(1.0);


int main()
{
	double PI = 4.0 * atan(1.0);
	int T;

	cin>>T;
	int idx = 0;
	int res = 0;
	int r,t;
	int needed;
	int cur;

	while((++idx) <= T) {

		cin>>r>>t;
		res = 0;

		while(true) {
			cur = 2*(res+1) - 1;
			needed = 2*r + 2*cur - 1;
			t -= needed;
			if(t < 0) break;
			res++;
		}

		cout<<"Case #"<<idx<<": "<<res<<endl;




	}
	
    return 0;

}