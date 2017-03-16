#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <climits>
#include <cctype>
#include <cmath>
#include <cassert>
#include <ctime>

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <complex>
#include <limits>
#include <functional>
#include <numeric>

using namespace std;

int main(){
	int t, count = 1;
	int a, b, k, r;
	
	cin >> t;
	while(t--){
		cin >> a >> b >> k;
		r = 0;
		
		for(int i = 0; i < a; i++){
			for(int j = 0; j < b; j++){
				if((i&j) < k) r++;
			}
		}
		
		cout << "Case #" << count++ << ": " << r << endl;
	}
	
	return 0;
}

