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

int main(void){
	int test_case_number;
	cin>>test_case_number;
		
	for (int test_case=1; test_case<=test_case_number; test_case++) {
		
		int J, P, S, K;
		cin>>J>>P>>S>>K;
		
		K = min(K, S);
		
		int MAX = J * P * K;
		
		cout<<"Case #"<<test_case<<": "<<MAX<<"\n";
		
		for (int a=1; a<=J; a++) for (int b=1; b<=P; b++) for (int k=0; k<K; k++) {
			int c = (a+b+k)%S + 1;
			cout << a << " " << b << " " << c << "\n";
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
