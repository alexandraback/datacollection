#include <iostream>
#include <cstring>
#define MAXLEN 1002
using namespace std;

int main()
{
	int t, l1, l2, i, j;
	char c, s[MAXLEN], stack1[MAXLEN], stack2[MAXLEN];
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	cin >> t;
	for (int times = 1; times <= t; times++) {
		cin >> s;
		l1 = l2 = 0;
		memset(stack1, 0, sizeof(stack1));
		memset(stack2, 0, sizeof(stack2));
		stack2[l2++] = s[0];
		for (i = 1; i < strlen(s); i++)
			if (s[i] >= stack2[l2 - 1])
				stack2[l2++] = s[i];
			else
				stack1[l1++] = s[i];
		for (i = 0, j = l2 - 1; i < j; i++, j--) {
			c = stack2[i]; stack2[i] = stack2[j]; stack2[j] = c;
		}
		cout << "Case #" << times << ": " << stack2 << stack1 << endl;
	}
	return 0;
} 
