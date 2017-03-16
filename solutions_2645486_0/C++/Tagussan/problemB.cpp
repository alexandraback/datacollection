//============================================================================
// Name        : problemB.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <sstream>
#include <algorithm>
#define rep(i,n) for(int i = 0;i<n;i++)
#define repit(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
typedef unsigned long long ull;
using namespace std;
int E,R,N;
vector<int> vi;
int dfs(int energy,int day){
	if(day == vi.size()){
		return 0;
	}
	int ans = 0;
	for(int cons = 0;cons <= energy;cons++){
		int gain = cons * vi[day];
		int lastE = min(E,E - cons + R);
		ans = max(ans,gain + dfs(lastE,day+1));
	}
	return ans;
}

int main() {
	int T;
	cin >> T;
	for(int Case = 1;Case <= T;Case++){
		cin >> E >> R >> N;
		vi.clear();
		rep(i,N){
			int a;
			cin >> a;
			vi.push_back(a);
		}
		int ans = dfs(E,0);
		cout << "Case #" << Case << ": " << ans << endl;
	}

	return 0;
}
