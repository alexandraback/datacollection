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



int main()
{
	int T;
	string str;
	int N;
	int L;
	cin>>T;
	int idx = 0;
	ll res = 0ll;

	while(++idx <= T) {
		cin>>str>>N;
		L = str.size();
		res = 0ll;
		bool isFound = false;
		int ct = 0;
		
		int lastSum = 0;

		for(int i=0; i < L; i++) {
			char cur = str[i];
			if(cur != 'a' && cur != 'e' && cur != 'i' && cur !='o' && cur != 'u') {
				ct++;
				if(ct >= N) {
					res += ll(i+1 - N + 1);
					lastSum = ll(i+1 - N + 1);
				} else {
					res += lastSum;
				}
			} else {
				res += lastSum;
				ct = 0;
				
				
			}

		}
		
		cout<<"Case #"<<idx<<": "<<res<<endl;
	}
	
    return 0;

}