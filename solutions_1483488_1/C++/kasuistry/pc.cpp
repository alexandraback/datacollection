
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int s[8] = {1e0, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7};

int digit(int x){
	for(int i=7; i>=0; --i){
		if(x >= s[i]) return i+1;
	}
}

int f(int x, int a, int b){
	
	int n = digit(x);
	int ret = 0;
	int r[10];
	
	for(int i=1; i<n; ++i){
		int y = (x%s[i])*s[n-i]+(x/s[i]);
		if(digit(y) == n && a <= y && y <= b){
			r[ret++] = y;
		}
	}

	if(ret > 0) sort(r, r+ret);

	int ans = (ret>0) ? (1) : (0);

	for(int i=1; i<ret; ++i){
		if(r[i] != r[i-1]){
			++ans;
		}
	}

	return ans;
}

int main(){
	
	int testcase; scanf("%d", &testcase);
	
	for(int t=1; t<=testcase; ++t){
		int a, b; scanf("%d %d", &a, &b);
		int ans=0;
		for(int i=a; i<=b; ++i){
			ans += f(i, i+1, b);
		}
		printf("Case #%d: %d\n", t, ans);
	}

	return 0;
}
