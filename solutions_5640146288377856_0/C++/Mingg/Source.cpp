#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
	FILE *stream;
	//freopen_s(&stream, "C:\\input.txt", "r", stdin);
	freopen_s(&stream, "C:\\Users\\Mingzhi\\Downloads\\A-small-attempt1.in", "r", stdin);
	freopen_s(&stream, "C:\\output.txt", "w", stdout);
	int T;
	scanf_s("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		int R, C, W;
		scanf_s("%d%d%d", &R, &C, &W);
		int s = C / W + W;
		if (C%W == 0) s--;
		s *= R;
		printf("Case #%d: %d\n", i, s);
	}
	return 0;
}