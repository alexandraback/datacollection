#include <cstdio>
#include <cstring>

void Open()
{
	freopen("P1.in", "r", stdin);
	freopen("P1.out", "w", stdout);
}

void Close()
{
	fclose(stdin);
	fclose(stdout);
}

char str[2000000];

inline bool Judge(char &t)
{
	if (t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u') return false;
	return true;
}

void Work()
{
	int N, T, len, ans;
	scanf ("%d", &T);
	for (int k = 0; k < T; k++)
	{
		scanf ("%s %d\n",str, &N);
		int i = 0, j = 0, count = 0, start = 0;
		ans = 0;
		len = strlen(str);
		while (i < len)
		{
			while (count < N && j < len) 
			{
				if (Judge(str[j])) count++;
				else 
				{
					count = 0;
					start = j+1;
				}
				j++;
			}
			if (count >= N)
				ans += (len - j + 1) * (start - i + 1);
			else
				break;

			i = start+1; 
			start = i;
			count--;
		}
		printf ("Case #%d: %d\n", k+1, ans);
	}
}

int main()
{
	Open();
	Work();
	Close();
	return 0;
}