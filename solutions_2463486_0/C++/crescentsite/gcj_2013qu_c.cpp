#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <cstdio>
#include <cmath>
using namespace std;
int check(int in){
	int t, tmp, rev = 0;
	t = in;
	while (t > 0)
	{
		tmp = t%10;
		t /= 10;
		rev = rev*10 + tmp;
	}
	if (in == rev)
		return 1;
	else return 0;
}
int main(){
	int T, k, a, b, as, bs, i, ans;
	cin >> T;
	for (k = 1; k <= T; k++)
	{
		cin >> a >> b;
		ans = 0;
		as = (int)sqrt(a);
		if (as*as != a)
			as++;
		bs = (int)sqrt(b);
		for (i = as; i <= bs; i++)
			if (check(i) == 1 && check(i*i) == 1)
				ans++;
		printf("Case #%d: %d\n", k, ans);
	}
	return 0;
}
