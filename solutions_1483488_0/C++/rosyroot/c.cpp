#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>

using namespace std;

void tostring(char *str, int num)
{
	int n;
	int cipher = 0;
	int temp;
	int i;

	temp = num;
	while (1)
	{
		cipher++;
		if (temp < 10)
			break;
		temp /= 10;
	}

	for (i = 0; i < cipher; i++)
	{
		str[cipher - 1 - i] = '0' + (num % 10);
		num /= 10;
	}
	str[cipher] = 0;
}

int main()
{
	int T;
	int ncase;
	int low, high;
	int end;
	char strn[10];
	char strm[10];
	char strmax[10];
	char bak[10][10];
	char bakn;

	cin >> ncase;
	for (T = 0; T < ncase; T++)
	{
		cin >> low >> high;
		end = (low + high) / 2 + 1;

		int i, j, k;
		int m;
		int cipher;
		int out = 0;
		tostring(strmax, high);

		for (i = low; i < high; i++)
		{
			tostring(strn, i);
			cipher = strlen(strn);
			strcpy(strm, strn);
			bakn = 0;
			for (j = 0; j < cipher - 1; j++)
			{
				char ch;
				ch = strm[cipher - 1];
				memcpy(strm + 1, strm, cipher - 1);
				strm[0] = ch;
				strm[cipher] = 0;
				if (strm[0] == '0')
					continue;

				if (strcmp(strn, strm) < 0 && strcmp(strm, strmax) <= 0)
				{
					for (k = 0; k < bakn; k++)
					{
						if (strcmp(bak[k], strm) == 0)
							break;
					}

					if (k == bakn)
					{
						strcpy(bak[bakn++], strm);
						//cout << strn << " " << strm << " " << strmax << endl;
						out++;
					}
				}
			}

		}

		cout << "Case #" << T + 1 << ": " << out << endl;
	}
	return 0;
}
