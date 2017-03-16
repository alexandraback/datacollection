#include <iostream>

using namespace std;

void flip(string & s, int n)
{
	//cout << "Flip(" << n << ") " << s;

	string ns = s;
	for (int i = 0; i < n; ++ i)
		ns[i] = (s[n-i-1] == '+')? '-' : '+';

	s = ns;
	//cout << " >> " << s << endl;
}

int solve(string & s)
{
	int end = s.size();
	if (end == 0) return 0;

	int nFlipped = 0;

	while (1)
	{
		while (end > 0 && s[end-1] == '+')
		{
			--end;
		}

		if (end == 0)
			break;
			
		if (s[0] == '+')
		{
			int i = 1;
			for (; i < end; ++i)
			{
				if (s[i] == '-')
				{
					break;
				}
			}

			flip(s, i);
			++nFlipped;
		}
		else
		{
			int i = 1;
			for (; i < end; ++i)
			{
				if (s[i] == '+')
				{
					break;
				}
			}
			flip(s, end);
			end -= i;

			++nFlipped;
		}
	}

	return nFlipped;
}

int main()
{
	unsigned numInputs = 0;
	
	cin >> numInputs;

	for (size_t i=0; i< numInputs; ++i)
	{
		string s;

		cin >> s;
		//cout << "Input: " << s << endl;

		cout << "Case #" << i + 1 << ": " << solve(s) << endl;
	}	

	return 0;
}
