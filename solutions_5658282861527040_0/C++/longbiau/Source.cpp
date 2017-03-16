/*******************\
|* # By longbiau # *|
\*******************/

#define _CRT_SECURE_NO_WARNINGS

// #include C {
#include<cstring>
#include<cassert>
#include<cstdio>
#include<cctype>
#include<cmath>
// }

// #include C++ {
#include<functional>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<bitset>
#include<queue>
#include<deque>
#include<stack>
#include<list>
#include<map>
#include<set>
// }
using namespace std;
// #typedef {
typedef long long int64;
typedef unsigned long long uint64;
typedef pair <int, int> PII;
typedef pair <int64, int64> PLL;
typedef pair <char, char> PCC;
typedef pair <double, double> PDD;
// }
#ifndef ONLINE_JUDGE
// #parameter{
#define TYPE decltype
/////////////////////////////////////////////////////////////
#else
/////////////////////////////////////////////////////////////
#define TYPE __typeof
// }
#endif
// #define {
#define MP make_pair
#define PB push_back
#define SZ(a) ((int)(a).size())
#define X first
#define Y second
#define L(x) ((x)<<1)
#define R(x) ((x)<<1 | 1)
#define max3(x, y, z) (max(max((x), (y)), (z)))
#define min3(x, y, z) (min(min((x), (y)), (z)))
#define BIT(x, i) (((x) >> (i)) & 1)
#define FOR(it, c) for( TYPE((c).begin()) it = (c).begin(); it != (c).end(); it++)
/////////////////////////////////////////////////////////////
const double PI = 2.0*acos(0.0);
const double EPS = 1e-6;

#define GREATER(x, y) ((x) > (y) + EPS)
#define GREATER_EQUAL(x, y) ((x) > (y) - EPS)
#define LESS(x, y) ((x) < (y) - EPS)
#define LESS_EQUAL(x, y) ((x) < (y) + EPS)
#define EQUAL(x, y) (abs((x) - (y)) < EPS)

#define MAX_N 105
#define MAXX 0x3f
#define UPPER 2147483647LL
#define INT_MAX 2147483647
#define INF (1<<29)
#define NONE -1
#define NIL 0
// }

/////////////////////////////////////////////////////////////
int64 DFS(int depth, int A, int B, int K, int limit){
	int64 res = 0LL;
	if (depth < limit){
		return 1LL * (A+1) * (B+1);
	}
	if (BIT(K, depth) == 1){
		if (BIT(A, depth) == 1 && BIT(B, depth) == 1){
			res += DFS(depth - 1, A - (1 << depth), B - (1 << depth), K, limit);
		}
	}
	else{
		if (BIT(A, depth) == 1 && BIT(B, depth) == 1){
			res += DFS(depth - 1, A - (1 << depth), (1 << depth) - 1, K, limit);//1,0
			res += DFS(depth - 1, (1 << depth) - 1, B - (1 << depth), K, limit);//0,1
			res += DFS(depth - 1, (1 << depth) - 1, (1 << depth) - 1, K, limit);//0,0
		}
		else if (BIT(A, depth) == 1){
			res += DFS(depth - 1, A - (1 << depth), B, K, limit);//1,0
			res += DFS(depth - 1, (1 << depth) - 1, B, K, limit);//0,0
		}
		else if (BIT(B, depth) == 1){
			res += DFS(depth - 1, A, B - (1 << depth), K, limit);//0,1
			res += DFS(depth - 1, A, (1 << depth) - 1, K, limit);//0,0
		}
		else
			res += DFS(depth - 1, A, B, K, limit);//0,0
	}
	//printf("[%d %d %d] => %lld\n", depth, A, B, res);
	return res;
}
/////////////////////////////////////////////////////////////
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++){
		int A, B, K;
		scanf("%d %d %d", &A, &B, &K);
		A--, B--;
		int64 res = 0LL;
		for (int k = 0; k < 31; k++){
			if (BIT(K, k) == 1){
				K -= 1 << k;
				res += DFS(31, A, B, K, k);
			}
		}
		printf("Case #%d: %lld\n", t, res);
	}
	
	return 0;
}
