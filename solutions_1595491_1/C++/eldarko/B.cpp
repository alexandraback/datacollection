#include <stdio.h>

int t[128];

int main()
{
	int T;
	scanf("%d", &T);
	
	for(int case_ = 1; case_ <= T; case_++)
	{
		int N, S, p;
		scanf("%d %d %d", &N, &S, &p);
		
		for(int i = 0; i < N; i++)
			scanf("%d", &t[i]);
		
		int res = 0;
		for(int i = 0; i < N; i++)
		{
			if(0 == t[i]) {
				if(0 == p)
					res++;
			}
// 			printf("Consider %d %d %d\n", t[i], S, p);
			else if(0 == t[i] % 3 && (t[i] / 3 >= p)) {
// 				printf("YES1\n");
				res++;
			}
			else if((0 == (t[i] + 1) % 3) && ((t[i] + 1) / 3 >= p)) {
// 				printf("YES2\n");
				res++;
			}
			else if((0 == (t[i] + 2) % 3) && ((t[i] + 2) / 3 >= p)) {
// 				printf("YES3\n");
				res++;
			}
			else if((S > 0) && (0 == t[i] % 3) && ((t[i] / 3) + 1 >= p)) {
				res++;
				S--;
			}
			else if((S > 0) && (0 == (t[i] + 4) % 3) && ((t[i] + 4) / 3 >= p)) {
				res++;
				S--;
			}
// 			else
// 				printf("NOPE\n");
		}
		printf("Case #%d: %d\n", case_, res);
	}
}
