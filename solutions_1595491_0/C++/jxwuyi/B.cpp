#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<string>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<deque>
#include<complex>
#include<numeric>
using namespace std;
const int inf = 10000000;
int N, S, Q, T[200];

int dp[102][102];

int get(int i, int j)
{
	if(j > S) return -inf;
	if(i == N)
	{
		return (j == S ? 0 : -inf);
	}
	int & ret = dp[i][j];
	if(ret != -1) return ret;
	
	ret = -inf;
	// not surprise
	int k = T[i] / 3;
	if(T[i] % 3 != 0) ++ k;
	ret = max(ret, (k >= Q) + get(i+1, j));
	
	// surprise
	k = T[i] / 3;
	if(T[i] % 3 != 2 && k == 0);
	else
	{
		++ k;
		if(T[i] % 3 == 2) ++ k;
		ret = max(ret, (k >= Q) + get(i+1, j+1));
	}
	return ret;
}

int run()
{
	scanf("%d %d %d", &N, &S, &Q);
	for(int i=0;i<N;++i) scanf("%d", T+i);
	memset(dp, -1, sizeof(dp));
	return get(0, 0);
}

int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w",stdout);
	int test;scanf("%d", &test);
	for(int no=1;no<=test;++no)
	{
		printf("Case #%d: %d\n", no, run());
	}
}
