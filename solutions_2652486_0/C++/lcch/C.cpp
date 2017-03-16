#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

int t[10], x[10];
bool mark[10];
bool bj, ok;

int main()
{
	freopen("C-small-1-attempt0.in", "r", stdin);
	freopen("C.out", "w", stdout);
	
	int TextN = 0, TT = 0, R, A, B, C, ans;
	scanf("%d", &TextN);
	while (TextN--) {
		cin >> R >> A >> B >> C;
		cout << "Case #" << ++TT << ":" << endl;
		for (int i = 1; i <= R; i++) {
			for (int j = 0; j != 7; j++) cin >> t[j];

			for (x[0] = 2; x[0] <= 5; x[0]++)
				for (x[1] = 2; x[1] <= 5; x[1]++)
					for (x[2] = 2; x[2] <= 5; x[2]++) {

						memset(mark, 0, sizeof(mark));
						for (int st = 0; st != 8; st++) {
							int tmp = 1;
							for (int c = 0; c != 3; c++) 
							if (st & (1 << c)) tmp = tmp * x[c];

							for (int k = 0; k != 7; k++)
								if (t[k] == tmp) mark[k] = true;
						}
						if (mark[0] && mark[1] && mark[2] && mark[3] && mark[4] && mark[5] && mark[6]) {
							ans = x[0]*100+x[1]*10+x[2];
						}
					}
			cout << ans << endl;
		}
	}
	return 0;
}