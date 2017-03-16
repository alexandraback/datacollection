//this code uses boost 1.53
//http://www.boost.org/doc/libs/1_53_0/libs/multiprecision/doc/html/boost_multiprecision/tut/ints/cpp_int.html

#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;
using boost::multiprecision::cpp_int;

cpp_int sqrt(cpp_int sq){
	cpp_int low = 0;
	cpp_int high = sq;
	cpp_int ans = 0;
	while(low<=high){
		cpp_int mid = (low+high)/2;
		if(mid*mid > sq){
			high = mid-1;
		}else{
			ans = mid;
			low = mid+1;
		}
	}
	return ans;
}

static void doComp(){
	cpp_int r,t;
	cin >> r >> t;
	cpp_int sq = (2*r-1)*(2*r-1) + 8*t;
	cpp_int left = -2*r+1;
	cpp_int res = (left + sqrt(sq))/4;
	cout << res << endl;
}

int main(){
	int C;
	cin >> C;
	for(int c=1; c<=C; ++c){
		cout << "Case #" << c << ": ";
		doComp();
	}

}

