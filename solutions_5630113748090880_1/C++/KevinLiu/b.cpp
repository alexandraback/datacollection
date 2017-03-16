#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef vector<int> Vint;
typedef vector<LL> VLL;

void printV(Vint v)
{
	for (int i=0;i<v.size();i++) {
		printf("%d\n", v[i]);
	}
}

void solve()
{
	int N;
	scanf("%d", &N);
	//vector<Vint> lst;
	int cnt[2501];
	for (int i=0;i<2501;i++) cnt[i]=0;

	for (int i=0;i<2*N-1;i++) {
		Vint l;
		for (int j=0;j<N;j++) {
			int x;
			scanf("%d", &x);
			l.push_back(x);
			cnt[x]++;
		}
		//lst.push_back(Vint(l));
	}

	for (int i=0;i<2501;i++) {
		if (cnt[i]%2!=0) {
			printf(" %d", i);
		}
	}
	printf("\n");
}

int main() 
{
	int T=0;
	scanf("%d", &T);
	for (int i=1;i<=T;i++) {
		printf("Case #%d:", i);
		solve();
	}
	
	return 0;
}
