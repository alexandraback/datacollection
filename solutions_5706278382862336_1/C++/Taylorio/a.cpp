#include <iostream>
using namespace std;

void print_args(){}

template <typename T, typename... Args>
void print_args(const T & val, Args... args)
{
	cout << val << " ";
	print_args(args...);
}

template <typename... Args>
void print_case(int test_case, Args... args)
{
	cout << "Case #" << test_case << ": ";
	print_args(args...);
	cout << endl;
}

typedef long long int lli;

lli gcd(lli a, lli b)
{
	if( a > b )
		return gcd(b,a);
	if( a == 0 )
		return b;
	return gcd(b%a, a);
}

lli num_gens(lli top, lli bot)
{
	double frac = top/double(bot);
	double acc = 1;
	for(int n = 0; n <= 40; n++)
	{
		if( frac >= acc )
			return n;
		acc /= 2;
	}
	return -1;
}

bool is_pow_of_two(lli num)
{
	lli acc = 1;
	for(int n = 0; n <= 40; n++)
	{
		if( num == acc )
			return true;
		acc *= (lli)2;
	}
	return false;
}

int main()
{
	int num_cases;
	cin >> num_cases;
	for(int c = 0; c < num_cases; c++)
	{
		lli top, bot;
		char trash;
		cin >> top >> trash >> bot;
		lli g = gcd(top,bot);
		top /= g;
		bot /= g;
		if( !is_pow_of_two(bot) )
			print_case(c+1, "impossible");
		else
			print_case(c+1, num_gens(top,bot));
	}
	return 0;
}
