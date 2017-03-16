#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
	int T, t, L, X, step, sign, x, i;
	char curr;
	string str, ans;

	cin >> T;
	for (t = 0; t < T; t++)
	{
		cin >> L >> X;
		cin >> str;

		step = 0;
		curr = ' ';
		sign = 1;
		for (x = 0; x < X; x++)
		{
			for (i = 0; i < L; i++)
			{
				if (curr == '1')
				{
					curr = str[i];
				}
				else if (curr == 'i')
				{
					if (str[i] == '1')
					{
						curr = 'i';
					}
					else if (str[i] == 'i')
					{
						curr = '1';
						sign *= -1;
					}
					else if (str[i] == 'j')
					{
						curr = 'k';
					}
					else if (str[i] == 'k')
					{
						curr = 'j';
						sign *= -1;
					}
				}
				else if (curr == 'j')
				{
					if (str[i] == '1')
					{
						curr = 'j';
					}
					else if (str[i] == 'i')
					{
						curr = 'k';
						sign *= -1;
					}
					else if (str[i] == 'j')
					{
						curr = '1';
						sign *= -1;
					}
					else if (str[i] == 'k')
					{
						curr = 'i';
					}
				}
				else if (curr == 'k')
				{
					if (str[i] == '1')
					{
						curr = 'k';
					}
					else if (str[i] == 'i')
					{
						curr = 'j';
					}
					else if (str[i] == 'j')
					{
						curr = 'i';
						sign *= -1;
					}
					else if (str[i] == 'k')
					{
						curr = '1';
						sign *= -1;
					}
				} else {
					curr = str[i];
				}

				if (step == 0 && curr == 'i')
				{
					curr = ' ';
					step = 1;
				}
				else if (step == 1 && curr == 'j')
				{
					curr = ' ';
					step = 2;
				}
			}
		}

		ans = "NO";
		if (sign == 1 && step == 2 && curr=='k')
		{
			ans = "YES";
		}
		cout << "Case #"<< t+1 << ": " << ans << endl;
	}

	return 0;
}