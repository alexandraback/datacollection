#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef unsigned long long ul;

int main(){
	int N ; 
	cin>> N;

	for(int T = 1 ; T <= N ; T++) {
		
		ul r, t;
		cin>> r>>t;
		ul ir = 2*r+1;
		ul low = (ul)0;
		ul hi = (ul)1<<31;
		ul mid = (low + hi) / (ul)2;
		ul ret = mid;
		while (low <= hi) {
			
			bool c = (2* t / mid>= (2*ir + (mid-1)*4));

			if(!c) {
				hi = mid -1;
				mid = (hi+low)/2;
			}
			else {
				ret = mid;
				low = mid+1;
				mid = (hi+low)/2;
			}
		}

		cout<<"Case #"<<T<<": "<<ret<<endl;
	}
	return 0;
}