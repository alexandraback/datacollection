#include <iomanip>
#include <algorithm>
#include <iterator>     // std::insert_iterator
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <fstream>

using namespace std;
int A,B,K;

int main(){
	ifstream in("A.in");
	ofstream out("result.txt");
	int TESTS; 
	in >> TESTS;
	for(int test = 0; test<TESTS; test++){
		cout << "Case #" << test+1 << ": ";
		out << "Case #" << test+1 << ": ";
		in >> A >> B >> K;
		long long ret = 0;
		/*if(K<=A){
			ret += K*B;
			if(K<=B){
				ret+= K*(A-K);
			}
			else{
				ret += B*(A-K); 
			}
		}
		else{
			ret += A*B;
		}*/
		long long count = 0;
		for(long long i = 0; i<A; i++)
			for(long long j = 0; j<B; j++){
				if((i & j) < K) ret++; 
			}
		
		cout << ret << endl;
		out << ret << endl;
	}
	return 0;
}
