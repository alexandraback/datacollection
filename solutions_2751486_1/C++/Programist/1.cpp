#include <iostream>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <math.h>
#include <stack>
#include <queue>
#include <list>
#include <limits.h>
#include <time.h>
#include <iterator>

#pragma comment(linker, "/STACK:167772160")

using namespace std;

int main(){
	ifstream cin("in.txt");
	
	ofstream cout ("out.txt");
	int T;
	cin >> T;
	long long _ans[111];
	for(int t=1; t <= T; t++){
		string s;
		cin >> s;
		int k;
		cin >> k;
		long long dp[1000100] = {};
		long long ans = 0;
		long long c = 0, last = -1;
		for(int i=0; i<s.length(); i++){
			//if(i) ans += dp[i-1];
			if(i) dp[i] = dp[i-1];
			if(s[i] == 'a' || s[i] == 'i' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u') 
				{
					if(c >= k)dp[i] += last + 1; 
					else{if(dp[i])dp[i] += last + 1;}
					c = 0;
					continue;
			}			
			c++;
			if(c >= k) dp[i] += (i + 1) - k + 1; else dp[i] += last + 1;
			if(c >= k) last = i - k+1;
			
		}
		cout << "Case #" << t << ": " << dp[s.length()-1] << endl;
	}
	return 0;
}
