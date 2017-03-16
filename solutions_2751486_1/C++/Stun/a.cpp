#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>

using namespace std;

struct node{
	int s;
	int e;
	string str;
	node (){}
	node (int s, int e, const string & str) : s(s), e(e) {}
};

int main(){
	int tcase;
	cin >> tcase;
	
	for(size_t casen = 0; casen < tcase; ++casen)
	{
		string str;
		int n;
		long long sol = 0;
		cin >> str >> n;
		vector<node> V;
		
		int prev = 0;
		bool prev_valid = false;
		for(size_t i = n-1; i < str.size(); ++i) {
			bool isvalid = true;
			// if (!prev_valid){
				for(size_t j = 0; j < n; ++j) {
					if (!(str[i-j] != 'a' && str[i-j] != 'e' && str[i-j] != 'i' && str[i-j] != 'o' && str[i-j] != 'u') )
						isvalid = false;
				}				
			// } 
			// else {
				// if (!(str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u') )
				// isvalid = false;
			// }
		
			if (isvalid) {
				int s = i - n + 1;
				int e = i;
				sol += (long long)(s - prev + 1) * (long long)(str.size() - (e+1) + 1);
				// sol += (str.size() - (e + 1)) + 1;
				// sol -= 1;
				prev = s + 1;
				// cout << s << " " << e << " " << n << " " << sol << endl;
			}
			prev_valid = isvalid;
		}
		cout << "Case #" << casen + 1 << ": ";
		cout << sol << endl;
		
	}
	

	return 0;
}
