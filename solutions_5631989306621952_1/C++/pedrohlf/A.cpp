#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <stdlib.h>
#include <set>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stack>
#include <sstream>
#include <list>
#include <bitset>
#define ff first
#define ss second

using namespace std;

typedef long long ll;

bool vis[10];
int cnt;

int main() {
	int t,n,tc=1;
	string s;
	list<char> ans;

	cin >> t;
	while(t--){
		cin >> s;
		ans.clear();
		ans.push_back(s[0]);
		for(int i = 1; i < s.size(); i++){
			if(s[i] >= ans.back())
				ans.push_back(s[i]);
			else
				ans.push_front(s[i]);
		}

		printf("Case #%d: ", tc++);
		stack<char> S;
		for(char x : ans)
			S.push(x);
		while(!S.empty()){
			cout << S.top();
			S.pop();
		}
		cout << "\n";
	}

	return 0;
}
