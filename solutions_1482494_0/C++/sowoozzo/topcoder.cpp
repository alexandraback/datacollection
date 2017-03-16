#include <vector>
#include <map>
#include <set>
#include <deque>
#include <algorithm>
#include <functional>
#include <sstream>
#include <cmath>
#include <string>
#include <iostream>

using namespace std;

typedef struct {
	int a, b, c;
} rush;

rush mem[1005];

int main() 
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int TestCase;
	cin >> TestCase;
	for (int T = 1; T <= TestCase; T++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) { 
			cin >> mem[i].a >> mem[i].b; mem[i].c = 0;
		}
		bool isBad = true;
		int res = 0, star = 0;
		while (true) {
			int idx1 = -1, idx2 = -1;
			bool isCompleted = true;
			for (int i = 0; i < n; i++) {
				if (mem[i].c == 2) continue;
				isCompleted = false;
				if (mem[i].b <= star && (idx2 == -1 || mem[i].c < mem[idx2].c)) idx2 = i;
				if (mem[i].c == 0 && mem[i].a <= star && (idx1 == -1 || mem[i].b > mem[idx1].b)) idx1 = i;
			}
			if (idx1 == -1 && idx2 == -1) {
				isBad = !isCompleted; break;
			}
			res++;
			if (idx2 != -1) {
				//cout << idx2 << endl;
				star += 2 - mem[idx2].c;
				mem[idx2].c = 2;
			} else {
				//cout << idx1 << endl;
				star += 1;
				mem[idx1].c = 1;
			}
		}

		if (isBad)
			printf("Case #%d: Too Bad\n", T);
		else
			printf("Case #%d: %d\n", T, res);
	}
}