#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

typedef unsigned long long ll;

int main(){
	int T;
	scanf("%d", &T);
	for(int te = 1; te <= T; te++){
		ll r, t;
		cin >> r >> t;
		ll ac = 0;
		ll b = r;
		ll cnt = 0;
		for(; ac <= t; ac+=2*b+1, b+=2, cnt++);
		printf("Case #%d: ", te);
		cout << cnt-1 << endl;
	}
	return 0;
}
