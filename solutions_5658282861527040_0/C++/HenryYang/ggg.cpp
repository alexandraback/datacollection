#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(){
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	int t, a, b, k, ctt = 0;
	cin >> t;
	while(t--){
		cin >> a >> b >> k;
		int ans = 0;
		for(int i = 0; i < a; i++)
			for(int j = 0; j < b; j++)
				ans += (i&j) < k;
		printf("Case #%d: %d\n", ++ctt, ans);
	}
	return 0;
}