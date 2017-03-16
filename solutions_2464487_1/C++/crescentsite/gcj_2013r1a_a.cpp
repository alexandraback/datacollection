#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <cstdio>
#include <cmath>

using namespace std;
long long int r, t, ans;
long long int sea(long long int x, long long int y){
	long long int test;
	test = (x+y)/2;
	if ((r*2 + test*2 - 1) <= t/test && (r*2 + test*2 + 1) > t/(test+1))
		return test;
	else if ((r*2 + test*2 - 1) > t/test)
		return sea(x, test);
	else return sea(test, y);
}
int main(){
	freopen("a.txt","w",stdout);
	int T, i;
	cin >> T;
	for (i = 1; i <= T; i++)
	{
		cin >> r >> t;
		if (r+r+1 > t)
			ans = 0;
		else ans = sea(1, (long long int)(sqrt(t)+1));
		printf("Case #%d: %lld\n", i, ans);
	}
	return 0;
}

