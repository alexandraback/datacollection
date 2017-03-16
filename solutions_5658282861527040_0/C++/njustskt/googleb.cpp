/*************************************************************************
    > File Name: googleb.cpp
    > Author: skt
    > Mail: sktsxy@gmail.com 
    > Created Time: 2014年05月03日 星期六 23时55分35秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define LL long long
int Cas = 1, t, ans;
LL a, b, k;
void work()
{
	printf("Case #%d: ", Cas ++);
	cin >> a >> b >> k;
	ans = 0;
	for (int i = 0; i < a; i ++) {
		for (int j = 0; j < b; j ++) {
			if ((i & j) < k) {
				ans ++;
			}
		}
	}
	printf("%d\n", ans);
}
int main()
{
	scanf("%d", &t);
	while (t --) {
		work();
	}
	return 0;
}
