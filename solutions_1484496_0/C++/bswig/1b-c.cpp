#include <algorithm>
#include <cstdio>

using namespace std;

int ntest;
int N;
int number[500];
pair<int, int> res[1 << 20];

int main()
{
	scanf("%d", &ntest);
	for(int test = 1;test <= ntest;++test)
	{
		scanf("%d", &N);
		for(int i = 0;i < N;++i)
			scanf("%d", &number[i]);
		for(int i = 0;i < (1 << N);++i)
		{
			int sum = 0;
			for(int j = 0;j < N;++j)
				if(i & (1 << j))
					sum += number[j];
			res[i] = make_pair(sum, i);
		}
		sort(res, res + (1 << N));
		bool hasAnswer = 0;
		int a, b;
		for(int i = 0;i < (1 << N);++i)
		{
			int j = i;
			while(j > 0 && res[j].first == res[i].first) --j;
			++j;
			while(j < (1 << N) && res[j].first == res[i].first)
			{
				if((res[i].second & res[j].second) == 0)
				{
					hasAnswer = 1;
					a = res[i].second;
					b = res[j].second;
					goto outer;
				}
				++j;
			}
			
		}
		outer:
		printf("Case #%d:\n", test);
		if(!hasAnswer)
			printf("Impossible\n");
		else
		{
			bool first = 1;
			for(int j = 0;j < N;++j)
				if(a & (1 << j))
				{
					if(!first)
						printf(" ");
					first = 0;
					printf("%d", number[j]);
				}
			printf("\n");
			first = 1;
			for(int j = 0;j < N;++j)
				if(b & (1 << j))
				{
					if(!first)
						printf(" ");
					first = 0;
					printf("%d", number[j]);
				}
			printf("\n");
		}
	}
}
