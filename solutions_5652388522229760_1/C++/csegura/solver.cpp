#include <iostream>
#include <sstream>
#include <numeric>
#include <set>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <strings.h>
#include <limits.h>
#include <stdlib.h>
#include <float.h>
#include <strings.h>
#include <string.h>
using namespace std;

int main(){
	long long tests;
	cin >> tests;
	for (long long t = 0; t < tests; t++){
		cout << "Case #" << (t+1) << ": "; 
		long long N;
		cin >> N;
		if (N == 0){
			cout << "INSOMNIA" << endl;
		} else {
			long long i = 1;
			vector<bool> seen(10, false);
			long long count = 0;
			bool finished = false;
			while(!finished){
				long long d = i * N;
				stringstream conv;
				conv << d;
				for (long long j = 0; j < conv.str().size(); j++){
					if (seen[conv.str()[j] - '0'] == false){
						count++;
						seen[conv.str()[j] - '0'] = true;
						if (count == 10){
							cout << d << endl;
							finished = true;
							break;
						}
					}
				}
				i++;
			}
		}
	}
}
