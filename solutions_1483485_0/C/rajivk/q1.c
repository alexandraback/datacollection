#include<stdio.h>
int main()
{
	int t, T, i;
	char ch, en, ge[128]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ' ', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 0, 0, 0, 0, 0, 0, 0, 'Y', 'H', 'E', 'S', 'O', 'C', 'V', 'X', 'D', 'U', 'I', 'G', 'L', 'B', 'K', 'R', 'Z', 'T', 'N', 'W', 'J', 'P', 'F', 'M', 'A', 'Q', 0, 0, 0, 0, 0, 0, 'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
	scanf("%d", &T);
	getchar();
	for(t=0;t<T;t++)
	{
		printf("Case #%d: ", t+1);
		while((ch=getchar())!=10)
			putchar(ge[ch]);
		printf("\n");
	}
	return 0;
}

