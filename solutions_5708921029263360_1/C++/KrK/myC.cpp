#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct pos {
    int x, y, z;
    pos(int x = 0, int y = 0, int z = 0): x(x), y(y), z(z) {}
};

int t;
int j, p, s, k;
vector <pos> res;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
        scanf("%d %d %d %d", &j, &p, &s, &k);
        if (k > s) k = s;
        res.clear();
        for (int a = 0; a < j; a++)
            for (int b = 0; b < p; b++)
                for (int need = 0; need < k; need++)
                    res.push_back(pos(a, b, (a * k + b * k + need) % s));
        printf("Case #%d: %d\n", tc, res.size());
        for (int i = 0; i < res.size(); i++)
            printf("%d %d %d\n", res[i].x + 1, res[i].y + 1, res[i].z + 1);
	}
	return 0;
}
