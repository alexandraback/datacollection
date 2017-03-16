#include <bits/stdc++.h>

using namespace std;

//z = zero
//w = two
//G = eight
//X = six

int t;
string str;
int cnt[256];
int numbers[10];
char in[20010];
int main(void)
{
	scanf("%d",&t);
	for (int cases = 1; cases <= t; ++cases)
	{
		memset(cnt, 0, sizeof cnt);
		memset(numbers, 0, sizeof numbers);
		scanf("%s",in);
		str = in;
		for (int i = 0; i < str.size(); ++i)
		{
			cnt[str[i]]++;
		}

		//zero
		while (cnt['Z'])
		{
			cnt['Z']--;
			cnt['E']--;
			cnt['R']--;
			cnt['O']--;
			numbers[0]++;
		}

		//two
		while (cnt['W'])
		{
			cnt['T']--;
			cnt['W']--;
			cnt['O']--;
			numbers[2]++;
		}

		//eight
		while (cnt['G'])
		{
			cnt['E']--;
			cnt['I']--;
			cnt['G']--;
			cnt['H']--;
			cnt['T']--;
			numbers[8]++;
		}


		//six
		while (cnt['X'])
		{
			cnt['S']--;
			cnt['I']--;
			cnt['X']--;
			numbers[6]++;
		}

		//THREE
		while (cnt['T'])
		{
			cnt['T']--;
			cnt['H']--;
			cnt['R']--;
			cnt['E']--;
			cnt['E']--;
			numbers[3]++;
		}

		//seven
		while (cnt['S'])
		{
			cnt['S']--;
			cnt['E']--;
			cnt['V']--;
			cnt['E']--;
			cnt['N']--;
			numbers[7]++;
		}

		//FOUR
		while (cnt['R'])
		{
			cnt['F']--;
			cnt['O']--;
			cnt['U']--;
			cnt['R']--;
			numbers[4]++;
		}

		//FIVE
		while (cnt['F'])
		{
			cnt['F']--;
			cnt['I']--;
			cnt['V']--;
			cnt['E']--;
			numbers[5]++;
		}

		//ONE
		while (cnt['O'])
		{
			cnt['O']--;
			cnt['N']--;
			cnt['E']--;
			numbers[1]++;
		}

		//NINE
		while (cnt['N'])
		{
			cnt['N']--;
			cnt['I']--;
			cnt['N']--;
			cnt['E']--;
			numbers[9]++;
		}

		printf("Case #%d: ",cases);
		for (int i = 0; i <= 9; ++i)
		{
			while (numbers[i]--)
			{
				printf("%d",i);
			}
		}
		printf("\n");
	}
	return 0;
}