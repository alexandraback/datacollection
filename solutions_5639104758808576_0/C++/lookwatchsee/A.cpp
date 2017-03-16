#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <list>
#include <queue>
#include <stack>
#include <deque>

using namespace std;


int solve(string& s, int n) {
	int sum = 0;
	int invited = 0;
	for (int i=0;i<n;++i) {
		int x=s[i]-'0';
		if (x==0) continue;
		if (i > sum) {
			invited+=(i-sum);
			sum=i;
		}
		sum+=x;
	} 
	return invited;
}
int main(void) {
	int T;
	cin>>T;
	for (int t=1;t<=T;++t) {
		int n;
		string s;
		cin>>n;
		cin>>s;
		int ans = solve(s, n+1);
		cout<<"Case #"<<t<<": "<<ans<<endl;
	}
	return 0;
}
