#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <sstream>
#include <functional>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int nt;
char s[100];

int main()
{
	int nt;
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
		fprintf(stderr, "test = %d\n", tt);
		printf("Case #%d:\n", tt);
		
		int N, J;
		scanf("%d %d", &N, &J);
		
		for(int i = 0; i < J; i++)
		{
			for(int j = 0; j < N; j++) s[j] = '0';
			s[0] = s[N - 1] = '1';
			int k = i;
			int pos = N - 2;
			while(k)
			{
				int bit = k % 2;
				k /= 2;
				s[pos--] = '0' + bit;
				s[pos--] = '0' + bit;
			}
			printf("%s", s);
			for(int b = 2; b <= 10; b++)
			{
				long long int x = 0;
				for(int j = 0; j < N; j++) x = x * b + s[N - j - 1] - '0';
				assert(x % (b + 1) == 0);
				printf(" %d", b + 1);
			}
			puts("");
		}

	}
	return 0;
}