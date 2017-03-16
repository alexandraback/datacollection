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
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

ifstream cin("A-Large.in");
ofstream cout("A-Large.out");
//don't forget overflow and the bounds;
double ml(long long k,long long r){ //ml necessary for k stripes
	return double(2*r+1)*k + 2.0*k*(k-1);
	
}
int main(){
	long long T;
	cin >> T;
	long long t,r ;
	for(long long i=0;i<T;i++){
		cin >> r >> t;
		long long lb = 0,ub = 2LL *1000LL *1000LL *1000LL ;
		for(long long z=0;z<200;z++) {
			long long mid = (lb+ub)/2;
			if(ml(mid,r) <=t) lb = mid;
			else ub = mid;
		}
		cout << "Case #" <<i+1 <<": "<< lb << endl;

	}
	
	return 0;
}