//Carlo Piovesan - carlop

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <istream>
#include <string>
#include <math.h>
#include <map>
#include <set>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <bitset>
#include <ctime>
#include <algorithm>
#include <sys/time.h>
#include <assert.h>

using namespace std;

long long pow2(int a) {
	long long res = 1;
	
	while (a>0) {
		a--;
		res *= 2;
	}

	return res;
}

int main(void){
	int test_case_number;
	cin>>test_case_number;
		
	for (int test_case=1; test_case<=test_case_number; test_case++) {
		
		int B;
		long long M;
		cin>>B >> M;
		cerr << B << " "<<B-2 << " "<<pow2(B-2)<<"\n";
		
		if (M <= pow2(B-2)) {
			cout<<"Case #"<<test_case<<": "<<"POSSIBLE"<<"\n";
			vector <string> slide(B, string(B, '0'));
			for (int i=0; i<B-1; i++) for (int j=0; j<i; j++) slide[j][i]='1';
			
			vector <long long> val(B-1, 1);
			for (int i=2; i<B-1; i++) val[i] = 2*val[i-1];
			
			for (int j=B-2; j>=0; j--) if (val[j] <= M) {
				M-= val[j];
				slide[j][B-1] = '1';
			}
			
			for (int i=0; i<B; i++) cout << slide[i]<<"\n";
		}
		else {
			cout<<"Case #"<<test_case<<": "<<"IMPOSSIBLE"<<"\n";
		}
	}
	
	return 0;
}



/*
10
10

1 -> 19 -> 91 -> 100
19	1		9
29
*/
