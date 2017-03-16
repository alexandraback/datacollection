#include <cstdio>
int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	scanf("%d", &T);

	for(int Case = 1; Case <= T; ++Case)
	{
		char S[1001];
		scanf("%s", S);

		char str[2003];
		int prevPtr = 1000, nextPtr = 1001;
		str[nextPtr++] = S[0];
		for(int i = 1; 0 != S[i]; ++i)
		{
			bool flag = false;
			int index = prevPtr+1;
			while(index < nextPtr)
			{
				if(str[index++] > S[i])
				{
					flag = true;
					break;
				}
			}

			if(flag)
				str[nextPtr++] = S[i];
			else
				str[prevPtr--] = S[i];
				
		}

		printf("Case #%d: ", Case);
		for(int i = prevPtr+1; i < nextPtr; ++i)
			printf("%c", str[i]);

		printf("\n");
	}
	
	return 0;
}
