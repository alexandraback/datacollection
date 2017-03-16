#include <cstdlib>
#include <cstdio>
#include <cstdlib>  
#include <cctype>  
#include <cstring>  
#include <cstdio>  
#include <cmath>  
#include <algorithm>  
#include <vector>  
#include <string>  
#include <iostream>  
#include <sstream>  
#include <map>  
#include <set>  
#include <queue>  
#include <stack>  
#include <fstream>  
#include <numeric>  
#include <iomanip>  
#include <bitset>  
#include <list>  
#include <stdexcept>  
#include <functional>  
#include <utility>  
#include <ctime>

using namespace std;  

typedef long long LL;

bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

LL go(string str, int n) {
	int j = 0, cc = 0;
	LL res = 0, len = str.length() ;
	for (LL i = 0; i < len; ++i) {
		if (isVowel(str[i])) {
			cc = 0;
		} else {
			cc++;
			if (cc >= n) {
				while (i - j >= n - 1) {
					++j;
					res += len - i;
				}
			}	
		}
	}
	return res;
}
int main ( int argc, char *argv[] ) {
	int T;
	cin >> T;
	string str;
	int n;
	for (int t = 1; t <= T; ++t) {
		cin >> str >> n;
		cout << "Case #" << t << ": " << go(str, n) << endl;
	}
}
