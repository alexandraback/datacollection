#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()

void solve(int tc){
	printf("Case #%d: ", tc);
	string s;
	cin >> s;
	string x; x += s[0];
	int L = s.length();
	for(int i=1;i<L;i++){
		string t;
		for(int j=0;j<i;j++)t += s[i];
		if(x > t)x = x + s[i];
		else x = s[i] + x;
	}
	cout << x << endl;
}

int main(){
	int Tc; scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve(tc);
	}
	return 0;
}