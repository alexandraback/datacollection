#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<algorithm>
#include<bitset>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<complex>
#include<functional>
#include<climits>
#include<cassert>
#include<iterator>
#include<valarray>
//#include<bits/stdc++.h>
using namespace std;
int t;
#define MAX 10000001
long long int dp[MAX];
bool use[MAX];
int rev(int a){
	int r = 0;
	while (a){
		r *= 10;
		r += a % 10;
		a /= 10;
		//r *= 10;
	}
	return r;
}
queue<int> q;
int main(){
	scanf("%d", &t);
	dp[1] = 1;
	string k;
	for (int i = 1; i < MAX; i++){
		dp[i] = INT_MAX;
	}
	dp[0] = 0;
	dp[1] = 1;
	q.push(1);
	while (!q.empty()){
		int a = q.front();
		q.pop();
		if (use[a]){
			continue;
		}
		use[a] = true;
		if (a + 1 < MAX&&dp[a + 1] > dp[a] + 1){
			q.push(a + 1);
			use[a + 1] = false;
			dp[a + 1] = dp[a] + 1;
		}
		int b = rev(a);
		if (b<MAX&&dp[b]>dp[a] + 1){
			q.push(b);
			use[b] = false;
			dp[b] = dp[a] + 1;
		}
	}
	int ca = 0;
	while (t--){
		ca++;
		cout << "Case #" << ca << ": ";
		long long int n;
		scanf("%lld", &n);
		printf("%lld\n", dp[n]);
	}
	return 0;
}