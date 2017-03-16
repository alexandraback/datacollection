#include <stdio.h>
#include <algorithm>
using namespace std;

int data[10000];

int main()
{
	int TT;
	scanf("%d",&TT);
	for (int tt=1; tt<=TT; tt++)
	{
		printf("Case #%d: ", tt);


		int N,S,P;
		scanf("%d%d%d",&N,&S,&P);

		for (int i = 0; i < N; i++)
		{
			scanf("%d",&data[i]);
		}

		sort(&data[0],&data[N],[](const int &a, const int &b)->bool{return a>b;});

		int nonsurprise = (P == 0) ? 0 : 3 * P - 2;
		int surprise = (P <= 1) ? P : 3 * P - 4;

		// 안 surpring의 한계: p-1, p-1, p
		// surpring의 한계: p-2, p-2, p

		// 참 쉽죠잉?

		int count = 0;
		for (count = 0; count < N; count++)
		{
			if (data[count] < surprise) break;
			else if (data[count] < nonsurprise)
			{
				if (S-- == 0) break;
			}
		}

		printf("%d\n", count);
	}
	return 0;
}
