#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MYMAX 2005

int a[1000];
int b[1000];
int finish[1000][2];

int foo(int N)
{
	memset(finish, 0, sizeof(finish));
	int star = 0;
	int loop = 1;
	int step = 0;
	while (loop) {
		int flag = 1;
		int maxai = -1;
		int var_maxai = -1;
		int done = 1;
		for (int i=0; i<N; ++i) {
			if (!finish[i][1] && b[i] <= star) {
				if (finish[i][0])
					++star;
				else
					star += 2;
				finish[i][1] = 1;
				flag = 0;
				++step;
			}
			if (b[i] > maxai && a[i] <= star && !finish[i][0] && !finish[i][1]) {
				maxai = b[i];
				var_maxai = i;
			}
			if (!finish[i][1]) {
				done = 0;
			}
		}
		if (flag) {
			if (var_maxai != -1) {
				finish[var_maxai][0] = 1;
				++star;
				++step;
			} else {
				loop = 0;
			}
		}
		if (done)
			break;
	}
	if (!loop)
		return -1;
	return step;
}

int main(void)
{
	int T_;
	scanf("%d ", &T_);
	for (int i_ = 1; i_ <= T_; ++i_) {
		int N;
		scanf("%d", &N);
		for (int i=0; i<N; ++i) {
			scanf("%d %d", a+i, b+i);
		}
		printf("Case #%d: ", i_);
		int ans = foo(N);
		if (ans > 0)
			printf("%d\n", ans);
		else
			printf("Too Bad\n");
	}
	return 0;
}
