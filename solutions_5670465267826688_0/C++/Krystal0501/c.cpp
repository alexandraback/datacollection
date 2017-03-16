#include <iostream>

using namespace std;

char multiply(char a, char b)
{
	char result;
	if (a == 'g')
	{
		result = b;
	}
	else if (a == 'G')
	{
		result = b + 'A' - 'a';
	}
	else if (a == 'i')
	{
		if (b == 'i')
		{
			result = 'G';
		}
		else if (b == 'j')
		{
			result = 'k';
		}
		else if (b == 'k')
		{
			result = 'J';
		}
	}
	else if (a == 'j')
	{
		if (b == 'i')
		{
			result = 'K';
		}
		else if (b == 'j')
		{
			result = 'G';
		}
		else if (b == 'k')
		{
			result = 'i';
		}
	}
	else if (a == 'k')
	{
		if (b == 'i')
		{
			result = 'j';
		}
		else if (b == 'j')
		{
			result = 'I';
		}
		else if (b == 'k')
		{
			result = 'G';
		}
	}
	else if (a == 'I')
	{
		if (b == 'i')
		{
			result = 'g';
		}
		else if (b == 'j')
		{
			result = 'K';
		}
		else if (b == 'k')
		{
			result = 'j';
		}
	}
	else if (a == 'J')
	{
		if (b == 'i')
		{
			result = 'k';
		}
		else if (b == 'j')
		{
			result = 'g';
		}
		else if (b == 'k')
		{
			result = 'I';
		}
	}
	else if (a == 'K')
	{
		if (b == 'i')
		{
			result = 'J';
		}
		else if (b == 'j')
		{
			result = 'i';
		}
		else if (b == 'k')
		{
			result = 'g';
		}
	}

	return result;

}

int main() {

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int l, x, result;
		int formerl = 1, latterl;
		int formerc = 0, latterc;
		int tmpl, tmpc;
		char tmp = 'g';
		char repeat[10001];
		cin >> l >> x;
		getchar();

		// cout << l << " " << x << endl;

		for (int j = 0; j < l; ++j)
		{
			cin >> repeat[j];
		}
		repeat[l] = '\0';

		// cout << repeat << endl;

		while(formerl <= x)
		{
			tmp = multiply(tmp, repeat[formerc]);
			// cout << tmp;
			if (formerc == l - 1)
			{
				formerc = 0;
				formerl++;
			}
			else
			{
				formerc++;
			}

			if (tmp == 'i')
			{
				break;
			}			

		}

		if (formerl > x)
		{
			cout << "Case #" << i + 1 << ": NO" << endl;
			continue;
		}

		tmp = 'G';
		latterl = x;
		latterc = l - 1;
		// cout << latterl << " " << formerl << endl;
		while(latterl >= formerl)
		{
			tmp = multiply(tmp, repeat[latterc]);
			// cout << "before: " << tmp << endl;
			if (tmp >= 'a' && tmp <= 'z')
			{
				tmp = tmp + 'A' - 'a';
			}
			else
			{
				tmp = tmp - 'A' + 'a';
			}

			// cout << "after: " << tmp << endl;

			if (latterc == 0)
			{
				latterc = l - 1;
				latterl--;
			}
			else
			{
				latterc--;
			}

			if (tmp == 'k')
			{
				break;
			}

		}

		// cout << formerl << " " << formerc << endl;
		// cout << latterl << " " << latterc << endl;

		if (latterl < formerl)
		{
			cout << "Case #" << i + 1 << ": NO" << endl;
			continue;
		}
		else if (latterl == formerl)
		{
			if (latterc < formerc)
			{
				cout << "Case #" << i + 1 << ": NO" << endl;
				continue;
			}
		}

		while((latterl - formerl) >= 5)
		{
			latterl -= 4;
		}

		tmpl = formerl;
		tmpc = formerc;

		tmp = 'g';
		while(tmpl <latterl || (tmpl == latterl && tmpc <= latterc))
		{
			tmp = multiply(tmp, repeat[tmpc]);
			// cout << tmp << endl;

			if (tmpc == l - 1)
			{
				tmpc = 0;
				tmpl++;
			}
			else
			{
				tmpc++;
			}
		}

		// cout << tmp << endl;
		if (tmp == 'j')
		{
			cout << "Case #" << i + 1 << ": YES" << endl;
			continue;
		}
		else
		{
			cout << "Case #" << i + 1 << ": NO" << endl;
			continue;
		}

	}

	return 0;
}

















