#include <bitset>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <deque>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <complex>
#include <cstring>
#include <map>
#include <stack>
using namespace std;

long long amountOfPaint(long long r, long long d){
	return d*(2*r+1) + 2ll*d*(d-1);
}
int main(){
	int T;
	cin >> T;
	for(int i=0;i<T;i++){
		long long r, t;
		cin >> r >> t;
		long long low = 1;
		long long high = 1;
		while(amountOfPaint(r, high) <= t){
			high = high * 2;
		}
		while(high - low > 1){
			long long mid = (high + low)/2;
			if(amountOfPaint(r, mid) <= t){
				low = mid;
			} else {
				high = mid;
			}
		}
		cout << "Case #"<< (i+1) << ": " << low << endl;
	}
}
