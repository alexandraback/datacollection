#include <stdio.h>
#include <queue>
using namespace std;

long long int saveMin[10000000] = { 0, 1, 0, };

int main()
{
	queue<long long int> xq, cntq;
	xq.push(1); cntq.push(1);
	long long int getX = 1;

	while (getX < 1000000){
		long long int x = xq.front(), cnt = cntq.front();
		xq.pop(); cntq.pop();

		long long int reverseX = 0, copy = x;
		while (copy > 0){
			reverseX *= 10;
			reverseX += (copy % 10);
			copy /= 10;
		}

		if (x + 1 <= 1000000)
		if (!saveMin[x + 1]){
			xq.push(x + 1); cntq.push(cnt + 1);
			saveMin[x + 1] = cnt + 1; getX++;
		}

		if (reverseX <= 1000000)
		if (!saveMin[reverseX]){
			xq.push(reverseX); cntq.push(cnt + 1);
			saveMin[reverseX] = cnt + 1; getX++;
		}
	}

	int tc, step = 0; scanf("%d", &tc);
	FILE* fout = fopen("A.txt", "w");
	while (step++ < tc){
		long long int n; scanf("%lld", &n);
		fprintf(fout, "Case #%d: %lld\n", step, saveMin[n]);
	}
	return 0;
}