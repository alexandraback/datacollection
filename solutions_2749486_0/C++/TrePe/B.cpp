#include <stdio.h>
#include <queue>
#include <map>
#include <stack>
using namespace std;

const int N = 0;
const int S = 1;
const int W = 2;
const int E = 3;

int cases, kejs;
int i, j, n;
int x, y, cx, cy;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int rdx[4] = {0, 0, 1, -1};
int rdy[4] = {-1, 1, 0, 0};
char dc[5] = "NSWE", z;
int rdc[127];
map<pair<int, int>, char > was;
map<pair<int, int>, char > wasb;
queue<pair<pair<int,int>, int>  > q;
pair<int, int> pii;
pair<pair<int, int>, int> ppiii;
stack<char> st;

int main() {
    rdc['N'] = 0;
    rdc['S'] = 1;
    rdc['W'] = 2;
    rdc['E'] = 3;
    scanf("%d", &cases);
    for (kejs = 1; kejs <= cases; kejs++) {
        printf("Case #%d: ", kejs);
        scanf("%d%d", &x, &y);
        was.clear();
		wasb.clear();
        pii.first = pii.second = 0;
        was[pii] = '\0';
        ppiii.first = pii;
        ppiii.second = 0;
        q.push(ppiii);
        for (;;) {
            ppiii = q.front();
            ppiii.second++;
            q.pop();
            if (ppiii.first.first == x && ppiii.first.second == y) break;
            for (j = 0; j < 4; j++) {
                ppiii.first.first += ppiii.second * dx[j];
                ppiii.first.second += ppiii.second * dy[j];
				cx = ppiii.first.first;
				cy = ppiii.first.second;
                if (was.find(ppiii.first) == was.end()) {
					wasb[ppiii.first] = ppiii.second;
                    was[ppiii.first] = dc[j];
                    q.push(ppiii);
                }
                ppiii.first.first -= ppiii.second * dx[j];
                ppiii.first.second -= ppiii.second * dy[j];
            }
        }
        while (!q.empty()) q.pop();
		ppiii.second = wasb[ppiii.first];
        while ((z = was[ppiii.first]) != '\0') {
			st.push(z);
            ppiii.first.first -= ppiii.second * dx[rdc[(int)z]];
            ppiii.first.second -= ppiii.second * dy[rdc[(int)z]];
            ppiii.second--;
        }
		while (!st.empty()) {
			putchar(st.top());
			st.pop();
		}
        putchar('\n');
    }
    return 0;
}

