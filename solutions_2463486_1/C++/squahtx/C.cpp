#include <iostream>
#include <fstream>
#include <stddef.h>
#include <stdlib.h>
#include <string>
#include <vector>

class bignum
{
public:
#define MAX_DIGITS 102
	bool overflow;
	unsigned int digitcount;
	char digits [MAX_DIGITS];

	bignum ()
	{
		overflow = false;
		digitcount = 0;
		for (unsigned int i = 0; i < MAX_DIGITS; i++)
		{
			digits [i] = '0';
		}
	}

	bignum (const char *s)
	{
		overflow = false;
		digitcount = strlen (s);
		for (unsigned int i = 0; i < MAX_DIGITS; i++)
		{
			digits [i] = '0';
		}

		for (unsigned int i = 0; i < digitcount; i++)
		{
			digits [i] = s [digitcount - 1 - i];
		}
	}

	void fixoverflow ()
	{
		for (unsigned int i = 0; i < digitcount; i++)
		{
			if (digits [i] > '9')
			{
				digits [i + 1] += (digits [i] -'0') / 10;
				digits [i] = (digits [i] - '0') % 10 + '0';
				overflow = true;
				if (i + 2 > digitcount)
				{
					digitcount = i + 2;
				}
			}
		}
	}

	bignum square ()
	{
		bignum result;
		result.digitcount = digitcount * 2 - 1;

		// yay convolution!!
		for (unsigned int i = 0; i < digitcount; i++)
		{
			for (unsigned int j = 0; j < digitcount; j++)
			{
				result.digits [i + j] += (digits [i] - '0') * (digits [j] - '0');
			}
		}

		result.fixoverflow ();
		return result;
	}

	bool operator<= (const bignum &n)
	{
		if (digitcount < n.digitcount) { return true;  }
		if (digitcount > n.digitcount) { return false; }

		for (int i = digitcount - 1; i >= 0; i--)
		{
			if (digits [i] < n.digits [i]) { return true; }
			if (digits [i] > n.digits [i]) { return false; }
		}

		// all digits equal
		return true;
	}
};

std::ostream &operator<< (std::ostream &out, const bignum &n)
{
	for (int i = n.digitcount - 1; i >= 0; i--)
	{
		out << n.digits [i];
	}
	return out;
}

// returns index of the least significant digit that was touched
int next_pal (bignum &n, int i)
{
	n.digits [i]++;
	n.digits [n.digitcount - 1 - i] = n.digits [i];

	while (n.digits [i] > '3')
	{
		n.digits [i] = '0';
		n.digits [n.digitcount - 1 - i] = '0';
		if (i == 0)
		{
			n.digitcount++;
			n.digits [0] = '1';
			n.digits [n.digitcount - 1] = '1';
			return 0;
		}
		i--;
		n.digits [i]++;
		n.digits [n.digitcount - 1 - i] = n.digits [i];
	}
	return i;
}

int main ()
{
	std::ifstream in ("c.in");
	std::ofstream out ("c.out");
	std::vector<bignum *> fairandsquares;

	bignum n ("1");
	
	std::cout << "Generating list..." << std::endl;

	unsigned int count = 0;

	int digittouched = 0;
	while (true)
	{
		bignum square = n.square ();
		if (!square.overflow)
		{
			fairandsquares.push_back (new bignum (square));
		}
		if (square.digitcount > 100) { break; }
		digittouched = next_pal (n, square.overflow ? digittouched : (n.digitcount - 1) / 2);
	}

	std::cout << "Processing test cases..." << std::endl;

	unsigned int testcount;
	in >> testcount;

	for (unsigned int i = 0; i < testcount; i++)
	{
		std::string str;
		in >> str;

		bignum min (str.c_str ());

		in >> str;
		bignum max (str.c_str ());

		unsigned int count = 0;

		for (unsigned int j = 0; j < fairandsquares.size (); j++)
		{
			bool undermax = *fairandsquares [j] <= max;
			if (!undermax) { break; }
			if (min <= *fairandsquares [j] && undermax)
			{
				count++;
			}
		}
		
		out << "Case #" << (i + 1) << ": " << count << std::endl;
	}

	std::cout << "Done, cleaning up..." << std::endl;

	for (unsigned int i = 0; i < fairandsquares.size (); i++)
	{
		delete fairandsquares [i];
	}

	return 0;
}

