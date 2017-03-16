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
char ch_mapping[3][3] = {
	{0,'k','j'}, 
	{'k', 0, 'i'}, 
	{'j', 'i', 0}
};
int r_mapping[3][3] = {
	{-1,1,-1}, 
	{-1,-1,1}, 
	{1,-1,-1}
};
//solve the small scale first
bool solve (string& s, int L, int X) {
	char target = 'i';
	int r =1;
	char prev=0;
	char cur;
	for (int i=0;i<L*X;++i) {
		cur = s[i%L];
		if (prev) {
			r *= r_mapping[prev-'i'][cur-'i'];
			cur=ch_mapping[prev-'i'][cur-'i'];
		}
		prev = cur;
		if (target==0) continue; 
		if (r==1 && cur == target) {
			prev=0;
			if (target<'k') {
				target++;
			} else {
				target=0;
			}
		}
	}
	return (prev== target && r==1);
}

int main(void) {
	int T;
	cin>>T;
	for (int t=1;t<=T;++t) {
		int L, X;
		cin>>L>>X;
		string s;
		cin>>s;
		bool ans=solve(s,L, X);
		if (!ans) {
			cout<<"Case #"<<t<<": NO"<<endl;
		} else {
			cout<<"Case #"<<t<<": YES"<<endl;
		}
	}
	return 0;
}
