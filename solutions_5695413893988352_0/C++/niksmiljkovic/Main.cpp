#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

#define Q '?'

unsigned long long diff = 9223372036854775808;
char sol1[100], sol2[100];
long long ll1, ll2;

void generate(char * s1, char *s2, int i, int n)
{
	if (i == n)
	{
		long long l1 = 0;
		long long l2 = 0;
		for (int i = 0; i < n; i++)
		{
			l1 = l1 * 10 + s1[i] - '0';
			l2 = l2 * 10 + s2[i] - '0';
		}

		// cout << l1 << ' ' << l2 << endl;

		unsigned long long dd;
		if (l1 > l2) dd = l1 - l2; else dd = l2 - l1;
		if (dd < diff || (dd == diff && l1 < ll1) || (dd == diff && l1 == ll1 && l2 < ll2))
		{
			diff = dd;
			for (int i = 0; i < n; i++) { sol1[i] = s1[i]; sol2[i] = s2[i]; }
			ll1 = l1; ll2 = l2;
		}
		return;
	}

	// both are question marks
	if (s1[i] == Q && s2[i] == Q)
	{
		for (int prvi = -1; prvi < 2; prvi++)
			for (int drugi = -1; drugi < 2; drugi++) {
				s1[i] = '0' + (prvi + 10) % 10;
				s2[i] = '0' + (drugi + 10) % 10;
				generate(s1, s2, i + 1, n);
				s1[i] = s2[i] = Q;
			}
		return;
	}

	// both are not question marks
	if (s1[i] != Q && s2[i] != Q)
	{
		generate(s1, s2, i + 1, n);
		return;
	}

	// one of them is a question mark
	if (s1[i] == Q) {
		int d = s2[i] - '0';
		for (int cc = d - 1; cc <= d + 1; cc++)
		{
			int x = (cc + 10) % 10;
			s1[i] = x + '0';
			generate(s1, s2,i + 1, n);
			s1[i] = Q;
		}

		s1[i] = '0';
		generate(s1, s2, i + 1, n);
		s1[i] = '9';
		generate(s1, s2, i + 1, n);

		s1[i] = Q;
	}
	else {
		int d = s1[i] - '0';
		for (int cc = d - 1; cc <= d + 1; cc++)
		{
			int x = (cc + 10) % 10;
			s2[i] = x + '0';

			generate(s1, s2, i + 1, n);
			s2[i] = Q;
		}

		s2[i] = '0';
		generate(s1, s2, i + 1, n);
		s2[i] = '9';
		generate(s1, s2, i + 1, n);
		s2[i] = Q;
	}
}

int solve(char *s1, char *s2) {
	int n = strlen(s1);

	diff = 9223372036854775808;
	for (int i = 0; i < 20; i++) sol1[i] = sol2[i] = 0;

	generate(s1, s2, 0, n);

	cout << sol1 << ' ' << sol2;

	return 0;
}

  int main() {
	  freopen("C:\\Users\\user\\Desktop\\inputs\\A.in", "r", stdin);
	freopen("C:\\Users\\user\\Desktop\\inputs\\A.out", "w", stdout);

	  int n;
	  scanf("%d", &n);

	  for (int i = 0; i < n; i++)
	  {
		  char s1[50], s2[50];
		  scanf("%s%s", s1, s2);

		  cout << "Case #" << (i + 1) << ": ";
		  solve(s1, s2);
		  cout << endl;
	  }

	  return 0;
  }
