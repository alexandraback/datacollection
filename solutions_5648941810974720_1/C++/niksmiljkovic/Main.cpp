

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int cnt[500];

int digcnt[20];

void decrease(char*c, int times)
{
	int n = strlen(c);
	for (int i = 0; i < n; i++)
	{
		cnt[c[i]-'A'] -= times;
	}
}

void decrease(int digit, int times)
{
	if (digit == 0) decrease("ZERO", times);
	if (digit == 1) decrease("ONE", times);
	if (digit == 2) decrease("TWO", times);
	if (digit == 3) decrease("THREE", times);
	if (digit == 4) decrease("FOUR", times);
	if (digit == 5) decrease("FIVE", times);
	if (digit == 6) decrease("SIX", times);
	if (digit == 7) decrease("SEVEN", times);
	if (digit == 8) decrease("EIGHT", times);
	if (digit == 9) decrease("NINE", times);
}

int solve(char *s) {
	for (int i = 0; i < 500; i++)  cnt[i] = 0;
	for(int i = 0; i < 20; i++) digcnt[i] = 0;

	int n = strlen(s);

	for (int i = 0; i < n; i++) {
		cnt[s[i] - 'A']++;
	}


	digcnt[0] = cnt['Z' - 'A'];
	decrease(0, digcnt[0]);

	digcnt[2] = cnt['W' - 'A'];
	decrease(2, digcnt[2]);

	digcnt[8] = cnt['G' - 'A'];
	decrease(8, digcnt[8]);

	digcnt[6] = cnt['X' - 'A'];
	decrease(6, digcnt[6]);
	
	digcnt[4] = cnt['U' - 'A'];
	decrease(4, digcnt[4]);;

	digcnt[5] = cnt['F' - 'A'];
	decrease(5, digcnt[5]);

	digcnt[7] = cnt['V' - 'A'];
	decrease(7, digcnt[7]);

	digcnt[9] = cnt['I' - 'A'];
	decrease(9, digcnt[9]);

	digcnt[3] = cnt['R' - 'A'];
	decrease(3, digcnt[3]);

	digcnt[1] = cnt['O' - 'A'];
	decrease(1, digcnt[1]);


	for (int i = 0; i < 20; i++)
	{
		while (digcnt[i] > 0) {
			cout << i;
			digcnt[i]--;
		}
	}

	return 0;
}

  int main() {
	  freopen("C:\\Users\\user\\Desktop\\inputs\\A.in", "r", stdin);
	  freopen("C:\\Users\\user\\Desktop\\inputs\\A.out", "w", stdout);

	  int n;
	  scanf("%d", &n);

	  for (int i = 0; i < n; i++)
	  {
		  char s[3000];
		  scanf("%s", s);

		  cout << "Case #" << (i + 1) << ": ";
		  solve(s);
		  cout << endl;
	  }

	  return 0;
  }
