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

int best[110][110];

int main()
{
	int T;
	string str;
	int N;
	int L;
	cin>>T;
	int idx = 0;
	int res = -1;

	while(++idx <= T) {
		cin>>str>>N;
		L = str.size();
		// try every possible ones
		res = 0;

		for(int i=0; i < L; i++)
			for(int j=i; j < L; j++) {
				int ct = 0;

				for(int k=i; k <= j; k++) {
					char cur = str[k];
					if(cur != 'a' && cur != 'e' && cur != 'i' && cur !='o' && cur != 'u') {
						ct++;
						if(ct == N) {
							res++;
							break;
						}
					} else {
						ct = 0;
					}
				}
			}



		cout<<"Case #"<<idx<<": "<<res<<endl;
	}
	
    return 0;

}