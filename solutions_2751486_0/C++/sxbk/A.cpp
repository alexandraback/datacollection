#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <utility>
#include <algorithm>

#define			OK			std::cout << "------------" << std::endl;
#define			DEBUG(x)		std::cout << #x << " = " << x << std::endl;

using namespace std;

typedef long long int LL;

const int MAXN = 2000000;
char s[MAXN];
int N;

inline bool yuan(char c) {
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main()
{
	int TT;

	scanf("%d", &TT);
	getchar();
	for (int _ = 1;_ <= TT;_ ++) {
		char c;
		N = 0;
		while (c = getchar(), c != ' ') {
			s[N++] = c;
		}
		int n;
		scanf("%d", &n);
		getchar();

		LL ans = 0;
		int j = 0, cnt = !yuan(s[j]);
		
		for (int i = 0;i < N;i++) {
			for (;j+1 < N;j ++) {
				if (cnt >= n) break ;
				if (!yuan(s[j+1])) {
					cnt ++;
				} else {
					cnt = 0;
				}
			}
			if (cnt >= n) {
		//		cout << i << " " << j << endl;
				ans += N - j;
			}
			if (j-i+1 == n) {
				cnt --;
			}
		}

		printf("Case #%d: %lld\n", _, ans);
	}

	return 0;
}
