#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <cstring>
#include <iostream>
using namespace std;

#define MAXN 110
int N, M;
typedef long long LL;

int A[MAXN], B[MAXN];
LL a[MAXN], b[MAXN];
#define mp make_pair
typedef pair<int, pair<LL, pair<int, LL> > > State;
map<State, LL> Map;
 
LL solve(int i, LL aa, int j, LL bb)
{
	State state = mp(i, mp(aa, mp(j, bb)));
	if(Map.find(state) != Map.end()) return Map[state];
	LL &ret = Map[state];
	/*
	cout << "At State " << endl;
	cout << "i: " << i << " aa: " << aa << " j: " << j << " bb: " << bb << endl;
	*/
	if(i == N) return ret = 0;
	if(j == M) return ret = 0;
	
	ret = 0;
	if(A[i] == B[j] && aa > 0 && bb > 0)
	{
		LL mn = min(aa, bb);
		ret = max(ret, mn + solve(i, aa - mn, j, bb - mn));
	}
	else
	{
		ret = max(ret, solve(i+1, a[i+1], j, bb));
		
		ret = max(ret, solve(i, aa, j+1, b[j+1]));
	}
	return ret;
}
int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	
	for(int cases=1;cases<=T;cases++) {
		scanf("%d %d", &N, &M);
		for(int i=0;i<N;i++)
		scanf("%lld %d", &a[i], &A[i]);
		
		for(int i=0;i<M;i++)
		scanf("%lld %d", &b[i], &B[i]);
		
		Map.clear();
		LL ret = solve(0, a[0], 0, b[0]);
		
		printf("Case #%d: %lld\n", cases, ret);
	}
	return 0;
}
