#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

int x, y;
bool b;
std::vector<char> res;

void skacz(int xa, int ya, int d, std::vector<char> wyn) {
	if(b)
		return;
	if(xa == x && ya == y) {
		res = wyn;
		b = true;
		return;
	}
	if(d > 50 || xa > 150 || xa < -150 || ya > 150 || ya < -150 || b)
		return;
	//printf("%d %d %d\n", xa, ya, d);
	wyn.push_back('N');
	skacz(xa, ya + d, d + 1, wyn);
	wyn.pop_back();
	wyn.push_back('S');
	skacz(xa, ya - d, d + 1, wyn);
	wyn.pop_back();
	wyn.push_back('E');
	skacz(xa + d, ya, d + 1, wyn);
	wyn.pop_back();
	wyn.push_back('W');
	skacz(xa - d, ya, d + 1, wyn);
	wyn.pop_back();
}

int main() {
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++) {
		scanf("%d%d", &x, &y);
		res.clear();
		std::vector<char> pusty;
		b = false;
		skacz(0, 0, 1, pusty);
		printf("Case #%d: ", i + 1);
		for(int j = 0; j < res.size(); j++)
			printf("%c", res[j]);
		printf("\n");
	}
	return 0;
}
