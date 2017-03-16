#include <cstdio>

struct Quaternion
{
	bool sign;
	char c;
	Quaternion(bool sign, char c): sign(sign), c(c) {}
	Quaternion operator * (const Quaternion &rhs)
	{
		switch (c)
		{
		case '1':
			switch (rhs.c)
			{
			case '1':
				return Quaternion(sign ^ rhs.sign, '1');
				break;
			case 'i':
				return Quaternion(sign ^ rhs.sign, 'i');
				break;
			case 'j':
				return Quaternion(sign ^ rhs.sign, 'j');
				break;
			case 'k':
				return Quaternion(sign ^ rhs.sign, 'k');
				break;
			}
			break;
		case 'i':
			switch (rhs.c)
			{
			case '1':
				return Quaternion(sign ^ rhs.sign, 'i');
				break;
			case 'i':
				return Quaternion(sign ^ rhs.sign ^ 1, '1');
				break;
			case 'j':
				return Quaternion(sign ^ rhs.sign, 'k');
				break;
			case 'k':
				return Quaternion(sign ^ rhs.sign ^ 1, 'j');
				break;
			}
			break;
		case 'j':
			switch (rhs.c)
			{
			case '1':
				return Quaternion(sign ^ rhs.sign, 'j');
				break;
			case 'i':
				return Quaternion(sign ^ rhs.sign ^ 1, 'k');
				break;
			case 'j':
				return Quaternion(sign ^ rhs.sign ^ 1, '1');
				break;
			case 'k':
				return Quaternion(sign ^ rhs.sign, 'i');
				break;
			}
			break;
		case 'k':
			switch (rhs.c)
			{
			case '1':
				return Quaternion(sign ^ rhs.sign, 'k');
				break;
			case 'i':
				return Quaternion(sign ^ rhs.sign, 'j');
				break;
			case 'j':
				return Quaternion(sign ^ rhs.sign ^ 1, 'i');
				break;
			case 'k':
				return Quaternion(sign ^ rhs.sign ^ 1, '1');
				break;
			}
			break;
		}
	}
};

char s[10001];

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int L;
		long long X;
		scanf("%d %lld", &L, &X);
		scanf("%s", s);
		printf("Case #%d: ", kase);
		Quaternion once(0, '1');
		for (int i = 0; i < L; ++i)
		{
			once = once * Quaternion(0, s[i]);
		}
		Quaternion sum(0, '1');
		for (int i = 0; i < X % 4; ++i)
		{
			sum = sum * once;
		}
		if (sum.c == '1' && sum.sign)
		{
			int lm = 0;
			Quaternion t(0, '1');
			for (lm = 0; lm < L * 4; ++lm)
			{
				t = t * Quaternion(0, s[lm % L]);
				if (t.c == 'i' && !t.sign)
				{
					break;
				}
			}
			if (lm < L * 4)
			{
				int rm = 0;
				t = Quaternion(0, '1');
				for (rm = 0; rm < L * 4; ++rm)
				{
					t = Quaternion(0, s[(L * 4 - rm - 1) % L]) * t;
					if (t.c == 'k' && !t.sign)
					{
						break;
					}
				}
				if (rm < L * 4 && lm + 1 + rm + 1 < X * L)
				{
					printf("YES\n");
				}
				else
				{
					printf("NO\n");
				}
			}
			else
			{
				printf("NO\n");
			}
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
