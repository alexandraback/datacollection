#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <complex>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair<int, int>

#define file "cycle"

void solve(int t){
	string s;
	int n, i;
	cin >> n >> s;
	int ans = 0, cur = 0;
	for(i = 0; i <= n; i++){
		if (cur <= i && s[i] != '0'){
			ans += i - cur;
			cur = i;

		}
		cur += s[i] - '0';
	}
	cout << "Case #" << t << ": " << ans << endl;
}	

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	//freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
	int t = 1;
	cin >> t;
	for(int i = 1; i <= t; i++){
		solve(i);	
	}
}
