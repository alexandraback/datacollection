#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int test, tt, n, Min, Now, i;
char str[1000005];
long long Ans;

int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%d\n", &test);
	while (test > 0)
	{
		test--;
		tt++;
		scanf("%s", str + 1);
		scanf("%d\n", &n);
		Ans = 0;
		Min = 0;
		Now = 0;
		for (i = 1; str[i] != 0; i++)
		{
			if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u')
			{
				Now++;
				if (Now >= n)
					Min = i - n + 1;
			}
			
			else
				Now = 0;
			Ans += Min;
		}
		
		cout << "Case #" << tt << ": " << Ans << endl;
	}
}

