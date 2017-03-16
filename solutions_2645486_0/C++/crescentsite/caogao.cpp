#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <cstdio>
#include <cmath>

using namespace std;
int T, i, k;
int e, r, n, ans;
int v[10005];
int ch[11]={};
void test(){
	int tmp = e, sum, p;
	for (p = 0; p < n; p++)
	{
		if (tmp < ch[p])
			break;
		tmp -= ch[p];
		tmp += r;
		if (tmp > e)
			tmp = e;
	}
	if (p == n)
	{
		sum = 0;
		for (int h = 0; h < n; h++)
			sum += v[h] * ch[h];
		if (sum > ans)
		{
			ans = sum;
		}
	}
}
void tb(int no){
	int s;

	for (s = 0; s <= e; s++)
	{
		ch[no] = s;
		if (no == n-1)
		{
			test();
		}
		else tb(no+1);
	}
}
int main(){
	cin >> T;
	for (k = 1; k <= T; k++)
	{
		cin >> e >> r >> n;
		for (i = 0; i < n; i++)
			scanf("%d", v+i);
		ans = 0;
		tb(0);
		printf("Case #%d: %d\n", k, ans);
	}
	return 0;
}

