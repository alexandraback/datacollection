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
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

bool vowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;	
	return false;
}

int main () {
        int T;  
        cin >> T;
        string line;
        getline(cin,line);
        for (int i = 0; i < T; ++i) {
		string A;
		long long N;
		cin >> A >> N;
		getline(cin,line);
		long long count = 0;
		vector<long long> b, e;
		bool cur = false;
		for (long long j = 0; j < A.length(); ++j) {
			if (!vowel(A[j])) {
				if (j == 0 || (j > 0 && vowel(A[j-1]))) b.push_back(j);
				if (j+1 == A.length() || (j+1 < A.length() && vowel(A[j+1]))) e.push_back(j);
			}
			
		}
		long long last = -1;
		for (long long j = 0; j < b.size(); ++j) {
			if (e[j]-b[j] + 1 >= N) {
				long long n = e[j]-b[j] + 1 - N;
				for (long long k = 0; k < n+1; ++k) {
					count += (b[j]+k-last)*(A.length()-e[j]+n-k);
					last = b[j]+k;
				}
			}
		}
                cout << "Case #" << i+1 << ": " << count <<endl;
        }   
}
