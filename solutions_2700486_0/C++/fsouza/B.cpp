#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

int maxh;
map <pair <int, int>, double> ret;
map <pair <int, int>, int> now;

void go(int n, int y, int x, double prob)
{
	if (n == 0) {
		for (map<pair <int, int>, int>::iterator it = now.begin(); it != now.end(); it++)
			ret[it -> first] += prob * (it -> second);
		return;
	}

//	printf("Go %d %d %d\n", n, y, x);

	while (1) {
		if (y == 0) {
			break;
		} else {
			if (now[make_pair(y-1, x-1)] == 0 && now[make_pair(y-1, x+1)] == 1) {
				y--;
				x--;
			} else if (now[make_pair(y-1, x-1)] == 1 && now[make_pair(y-1, x+1)] == 0) {
				y--;
				x++;
			} else if (now[make_pair(y-1, x-1)] == 1 && now[make_pair(y-1, x+1)] == 1) {
				break;
			} else if (now[make_pair(y-1, x-1)] == 0 && now[make_pair(y-1, x+1)] == 0) {
				if (y-1 >= 0 && now[make_pair(y-2, x)] == 0 && now[make_pair(y-1, x)] == 0) {
					y -= 1;
				} else {
					y--;
					x--;
					maxh = max(maxh, y);
					
					go(n, y, x, prob/2.0);
					
					x += 2;
					go(n, y, x, prob/2.0);
					
					return;
				}
			}
//			printf("Y = %d, X = %d\n", y, x);

		}
	}

//	printf("Land at %d, %d\n", y, x);

	now[make_pair(y, x)] ++;
	maxh = max(maxh, y);
	go(n-1, maxh+10, 0, prob);
	now[make_pair(y, x)] --;
}

int main()
{
	int ntest;

	scanf("%d", &ntest);

	for (int t = 0; t < ntest; t++) {
		int n, x, y;

		scanf("%d %d %d", &n, &x, &y);
		
		maxh = 0;
		ret.clear();
		now.clear();

		go(n, 10, 0, 1.0);

		printf("Case #%d: %.7f\n", t+1, ret[make_pair(y, x)]);
	}

	return 0;
}
