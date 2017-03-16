#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef vector<int>::iterator vit;
typedef map<int,int>::iterator mit;

const LL inf = 1000000000000000000ll;
LL f[111][11];
int v[111];

void work(int no)
{
	int E,R,n;
	scanf("%d%d%d",&E,&R,&n);
	for (int i = 0;i < n;++i)
		scanf("%d",v+i);
	for (int i = 0;i <= n;++i)
		for (int j = 0;j <= E;++j)
			f[i][j] = -inf;
	f[0][E] = 0;
	for (int i = 0;i < n;++i)
		for (int j = 0;j <= E;++j)
			for (int k = 0;k <= j;++k)
				f[i+1][min(E,j - k + R)] = max(f[i+1][min(E,j-k+R)],f[i][j] + k * v[i]);
	printf("Case #%d: %lld\n",no,f[n][min(R,E)]);
}

int main()
{
	int times;
	scanf("%d",&times);
	for (int i = 1;i <= times;++i)
		work(i);
	return 0;
}
