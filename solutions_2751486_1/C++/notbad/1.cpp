// =====================================================================================
//
//       Filename:  1.cpp
//
//    Description:  
//
//        Version:  1.0
//        Created:  05/12/2013 04:59:19 PM
//       Revision:  none
//       Compiler:  gcc
//
//         Author:  fang zhiwen (zhiwenf@gmail.com), 
//   Organization:  
//
// =====================================================================================

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

typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> PII;

#define PB push_back
#define MP make_pair

inline bool is_cons(char ch) {
	return ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u';
}
LL go(string str, int n) {
	int j = 0, cnt = 0;
	LL ans = 0;
	LL len = str.length() ;
	for (LL i = 0; i < len; ++i) {
		if (is_cons(str[i])) {
			cnt++;
			if (cnt >= n) {
				while (i - j >= n - 1) {
					++j;
					ans += len - i;
				}
			}	
		} else {
			cnt = 0;
		}
	}
	return ans;
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
// ----------  end of function main  ---------- 
