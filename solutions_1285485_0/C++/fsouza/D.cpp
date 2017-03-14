#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/3)

typedef long long lint;

using namespace std;

int gcd(int a, int b)
{
	if (a == 0) return b;
	return gcd(b%a, a);
}

int main(int argc, char ** argv)
{
	int ntest;

	scanf("%d", &ntest);
	
	for (int test = 0; test < ntest; test++) {
		int height, width, maxdist;
		vector <string> field;
		
		scanf("%d %d %d", &height, &width, &maxdist);
		
		for (int y = 0; y < height; y++) {
			string line;
			for (int x = 0; x < width; x++) {
				char c;
				scanf(" %c", &c);
				if (x != 0 && x != width-1)
					line += c;
			}
			if (y != 0 && y != height-1)
				field.push_back(line);
		}

		int rep = 0;
		while (field[0].size() < 8*maxdist || rep < 5) {
			for (int y = 0; y < field.size(); y++) {
				string bla = field[y];
				reverse(bla.begin(), bla.end());
				field[y] += bla;
			}
			rep ++;
		}
		rep = 0;
		while (field.size() < 8*maxdist || rep < 5) {
			for (int y = field.size()-1; y >= 0; y--)
				field.push_back(field[y]);
			rep ++;
		}
		rep = 0;

		vector <pair <int, int> > pos;
		pair <int, int> start;
		for (int y = 0; y < field.size(); y++)
			for (int x = 0; x < field[y].size(); x++) {
				if (field[y][x] == 'X') {
					pos.push_back(make_pair(y, x));
					if (y-maxdist >= 0 && y+maxdist < field.size() && x-maxdist >= 0 && x+maxdist < field[0].size())
					    start = make_pair(y, x);
				}
			}

		set <pair <int, int> > angles;

		for (int i = 0; i < pos.size(); i++) {
			int y = start.first, x = start.second;
			int y2 = pos[i].first, x2 = pos[i].second;
			if (y == y2 && x == x2) continue;
			if ((y-y2)*(y-y2) + (x-x2)*(x-x2) <= maxdist*maxdist) {
				int g = gcd(abs(y-y2), abs(x-x2));
				angles.insert(make_pair((y-y2)/g, (x-x2)/g));
			}
		}

		printf("Case #%d: %d\n", test+1, (int)angles.size());
	}

	return 0;
}
