#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <deque>


using namespace std;

#define FOR0(i,N) for(int i=0; i<(N); i++)
#define FOR1(i,N) for(int i=1; i<=(N); i++)


struct _compare {
	bool operator()(int i, int j) {
		return i>j; // 참이 되는 경우가 옳은 순서.
	}
} COMP;

int main()
{
//	freopen("1c/sample.in", "r", stdin);
	freopen("1c/A-small-attempt0.in", "r", stdin);
//	freopen("1c/A-large.in", "r", stdin);
	freopen("1c/outputA", "w", stdout);

	int test_case;
	scanf("%d", &test_case);

	int R, C, W;

	FOR1(T,test_case) {
		scanf("%d %d %d", &R, &C, &W);
		int Ans = (C-1)/W + W;


		printf("Case #%d: %d\n", T, Ans);
	}
	return 0;
}












