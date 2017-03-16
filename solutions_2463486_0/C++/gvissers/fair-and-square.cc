#include <fstream>
#include <iostream>

void nextPalindrome(std::string& str)
{
	if (str.empty())
	{
		str = "1";
	}
	else
	{
		std::string::size_type len = str.size(), mid = (len-1)/2;
		if (str[mid] < '9')
		{
			++str[mid];
		}
		else
		{
			str[mid] = '0';
			for (std::string::size_type i = mid; i > 0; --i)
			{
				if (str[i-1] != '9')
				{
					++str[i-1];
					break;
				}
				str[i-1] = '0';
			}
			if (str[0] == '0')
			{
				str.assign(++len, '0');
				str[0] = '1';
			}
		}
		for (std::string::size_type i = 0; i <= mid; ++i)
			str[len-i-1] = str[i];
	}
}

std::string sum(const std::string& a, const std::string& b)
{
	if (a.size() < b.size())
		return sum(b, a);

	std::string s = a;
	int carry = 0;
	int i, j;
	for (i = b.size() - 1, j = s.size() - 1; i >= 0; --i, --j)
	{
		int da = s[j] - '0';
		int db = b[i] - '0';
		int ds = da+db+carry;
		s[j] = '0' + ds%10;
		carry = ds/10;
	}
	while (carry && j >= 0)
	{
		if (s[j] != '9')
		{
			++s[j];
			carry = 0;
			break;
		}
		s[j--] = '0';
	}
	return carry ? '1' + s : s;
}

std::string mulDigit(const std::string& a, char d)
{
	int carry = 0;
	int dd = d-'0';
	int i;
	std::string p = a;
	for (i = a.size()-1; i >= 0; --i)
	{
		int da = p[i] - '0';
		int dp = da*dd + carry;
		p[i] = '0' + dp%10;
		carry = dp/10;
	}
	return carry ? char('0'+carry) + p : p;
}

std::string square(const std::string& nr)
{
	std::string res;
	std::string zeros = "";
	for (int i = nr.size()-1; i >= 0; --i)
	{
		res = sum(res, mulDigit(nr, nr[i]) + zeros);
		zeros += '0';
	}
	return res;
}

bool isPalindrome(const std::string& a)
{
	int len = a.size();
	for (int i = 0; i < len/2; ++i)
	{
		if (a[len-i-1] != a[i]) return false;
	}
	return true;
}

bool less(const std::string& a, const std::string& b)
{
	return a.size() < b.size()
		|| (a.size() == b.size() && a < b);
}

int main(int argc, const char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <input-file>\n";
		return 1;
	}

	std::ifstream is(argv[1]);
	if (!is.good())
	{
		std::cerr << "Unable to open input file " << argv[1] << "\n";
		return 1;
	}

	int nr_cases;
	is >> nr_cases;
	if (!is.good())
	{
		std::cerr << "Failed to read number of test cases\n";
		return 1;
	}

	for (int icase = 1; icase <= nr_cases; ++icase)
	{
		std::string low, high;
		is >> low >> high;

		std::string nr, sq;
		unsigned int nrMatches = 0;
		while (less(sq, low))
		{
			nextPalindrome(nr);
			sq = square(nr);
		}
		while (!less(high, sq))
		{
			if (isPalindrome(sq))
				++nrMatches;
			nextPalindrome(nr);
			sq = square(nr);
		}

		std::cout << "Case #" << icase << ": " << nrMatches << '\n';
	}

	return 0;
}
