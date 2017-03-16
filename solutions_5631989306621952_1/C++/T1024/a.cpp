#include <cmath>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	int t;
	
	cin >> t;
	for(int tt=1; tt<=t; ++tt)
	{
		string s;
		cin >> s;
		
		string ans = "";
		ans += s[0];
		for(int i=1; i<s.size(); ++i)
			if(s[i] < ans[0])
				ans += s[i];
			else
				ans.insert(ans.begin(), s[i]);
				
		cout << "Case #" << tt << ": " << ans << "\n";
		cout.flush();
	}

	return 0;
}
