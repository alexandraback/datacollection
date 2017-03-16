#include <cstdio>
#include <set>

using namespace std;

int rewind(int num, int tenPow)
{
	int last = num % 10;
	num /= 10;
	num += last * tenPow;
	return num;
}

void test(int testNum)
{
	int a, b;
	scanf("%d%d", &a, &b);

	int len = 0, tenPow = 1;
	for (int ntp = 10; ntp < b; ntp = tenPow * 10)
	{
		tenPow = ntp;
		len++;
	}
	int rewI, count = 0;
	set<int> st;
	for (int i = a; i <= b; i++)
	{
		st.clear();
		rewI = i;
		for (int j = 0; j < len; j++)
		{
			rewI = rewind(rewI, tenPow);
			if (rewI > i && rewI <= b && st.find(rewI) == st.end())
			{
				st.insert(rewI);
				count++;
			}
		}
	}

	printf("Case #%d: %d\n", testNum, count);
}

int main()
{
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int tc;
	scanf("%d", &tc);

	for (int i = 0; i < tc; i++)
	{
		test(i+1);
	}

	return 0;
}