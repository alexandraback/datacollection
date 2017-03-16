#define _CRT_SECURE_NO_WARNINGS C4996
#include <stdio.h>
int T;
long long int n;
int route[10000010];
int table[10000010];
int sw[10000010];
int div(int x)
{
	int data[15] = { 0 };
	int cnt = 0;

	while (x)
	{
		data[++cnt] = x % 10;
		x /= 10;
	}

	for (int i = 1; i <= cnt; i++)
	{
		x = x * 10 + data[i];
	}

	return x;
}
int div2(int x)
{
	int data[15] = { 0 };
	return 1;
}
int main()
{
	int i,a;
	int P = 0;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &T);

	long long int ans = 0;
	long long int n2 = 0,copy_n2;
	int data[110] = { 0 },datacnt=0;
	while (T)
	{
		//n = i;
		scanf("%lld", &n);
		n2 = n;
		ans = 0;
		copy_n2 = n2;
		datacnt = 0;
		while (copy_n2)
		{
			data[++datacnt] = copy_n2 % 10;
			copy_n2 /= 10;
		}
		data[1] = 1;
		for (i = 2; i <= datacnt / 2; i++)
		{
			data[i] = 0;
		}
		int sw1 = 0;
		for (i = datacnt; i >= 1; i--)
		{
			copy_n2 = copy_n2 * 10 + data[i];
			if (data[i] != data[datacnt - i + 1]) sw1 = 1;
		}
		if (n2 > copy_n2)
		{
			ans = n2 - copy_n2;
			if (sw1 == 1)
			{
				n2 = 0;
				for (i = 1; i <= datacnt; i++)
				{
					n2 = n2 * 10 + data[i];
				}
				ans++;
			}
			else n2 = copy_n2;
		}
		else
		{
			sw1 = 0;
			copy_n2 = n2 - 1;
			datacnt = 0;
			while (copy_n2)
			{
				data[++datacnt] = copy_n2 % 10;
				copy_n2 /= 10;
			}
			data[1] = 1;
			for (i = 2; i <= datacnt / 2; i++)
			{
				data[i] = 0;
			}
			int sw1 = 0;
			for (i = datacnt; i >= 1; i--)
			{
				copy_n2 = copy_n2 * 10 + data[i];
				if (data[i] != data[datacnt - i + 1]) sw1 = 1;
			}
			ans = n2 - copy_n2;
			if (sw1 == 1)
			{
				n2 = 0;
				for (i = 1; i <= datacnt; i++)
				{
					n2 = n2 * 10 + data[i];
				}
				ans++;
			}
			else n2 = copy_n2;
		}
		while (n2)
		{
			datacnt--;
			copy_n2 = 0;
			for (i = 1; i <= datacnt/2; i++)
			{
				data[i] = 9;
				copy_n2 = copy_n2 * 10 + data[i];
			}
			for (i = datacnt/2+1; i < datacnt; i++)
			{
				data[i] = 0;
				copy_n2 = copy_n2 * 10 + data[i];
			}
			data[datacnt] = 1;
			copy_n2 = copy_n2 * 10 + data[datacnt];

			ans += n2 - copy_n2;
			n2 = 0;
			for (i = datacnt; i >= 1; i--)
			{
				n2 = n2 * 10 + data[i];
			}
			ans++;
			if (n2 == 1) break;
			if (datacnt == 2) {
				ans += (n2); break;
			}
		}

		printf("Case #%d: %lld\n", ++P,ans);
		//printf("%lld\n", ans);
		T--;
		/*table[1] = 1;
		for (i = 1; i <= n; i++)
		{
			if (table[i + 1] == 0 || table[i + 1] > table[i] + 1)
			{
				table[i + 1] = table[i] + 1;
				//route[i + 1] = i;
				//sw[i + 1] = 0;
			}
			int k = div(i);
			if (table[k] == 0 || table[k] > table[i] + 1)
			{
				table[k] = table[i] + 1;
				//route[k] = i;
				//sw[k] = 1;
			}
		}

		//printf("Case #%d: %d\n", ++P,table[n]);
		printf("%d - ", n);
		int b = n;
		while (b)
		{
			if(sw[b]) printf("%d(%d) - ", b,route[b]);
			b = route[b];
		}
		printf("\n");

		++P;
		if (table[n] == ans)
		{
			printf("Test:%d..OK!\n",P);
		}
		else
		{
			printf("Test:%d.. Wrong!\n",P);
			printf("Your Answer : %d\n", ans);
			printf("Correct Answer : %d\n", table[n]);
			break;
		}
		for (i = 1; i <= n; i++)
		{
			table[i] = 0;
		}
		T--;*/
	}

	return 0;
}
