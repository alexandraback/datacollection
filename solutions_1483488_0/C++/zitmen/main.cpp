#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using std::cin;
using std::map;
using std::vector;
using std::cout;

const int NUMBER_LIMIT = 1000;	// small: 1000, big: 2000000
const int DIGITS_LIMIT = 4;	// small: 4, big: 7

int digits(int n);	// returns count of digits of number `n`
int hash(int n);	// creates hash key - if hash1 != hash2 then number1 IS rotation of number2, else number1 MIGHT BE ratation of number2
int rotate(int n, int k, int digits = DIGITS_LIMIT);	// rotates number `n` by `k` steps
int min_rotation(int n);	// finds a rotation with a minimal value

int main()
{
	int T, A, B, result;
	cin >> T;
	for(int t = 1; t <= T; ++t)
	{
		cin >> A >> B;
		//
		// generate all numbers from the [A,B] interval and save it as linked hash map
		map<int,vector<int> > pairs;
		for(int n = A; n <= B; ++n)
			pairs[hash(n)].push_back(n);
		//
		// check if all th numbers from one bin are a rotation of the same number
		map<int,int> mins;
		for(map<int,vector<int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
		{
			if(it->second.size() == 1) continue;	// no pair detected
			for(vector<int>::iterator itv = it->second.begin(); itv != it->second.end(); ++itv)
				mins[min_rotation(*itv)]++;	// rotation of the same number? min_rotation is rotation invariant transformation
		}
		// count the pairs
		result = 0;
		for(map<int,int>::iterator itm = mins.begin(); itm != mins.end(); ++itm)
			for(int c = itm->second - 1; c > 0; --c)
				result += c;
		//
		cout << "Case #" << t << ": " << result << '\n';
	}
	return 0;
}

int hash(int n)
{
	int sum = 0, mul = 1, digit;
	for(int i = 0; i < DIGITS_LIMIT; ++i)
	{
		if(n > 0)
		{
			digit = n % 10;
			n /= 10;
			//
			sum += digit;
			mul *= ((digit > 0) ? digit : 10);
		}
		else	// digit == 0
			mul *= 10;
	}
	// max(sum) =  9values_of_one_digit * 7digits = 63  --->  8bits
	// max(mul) = 10values_of_one_digit ^ 7digits = 1e7 ---> 24bits
	return (sum << 24 | mul);
}

int rotate(int n, int k, int digits)
{
	int num = 0, tmp = 0, mul = 1;
	for(int i = 0; i < k; ++i)
	{
		num += (n % 10) * mul;
		mul *= 10;
		n /= 10;
	}
	//
	mul = 1;
	for(int i = k; i < digits; ++i)
	{
		num *= 10;
		tmp += (n % 10) * mul;
		mul *= 10;
		n /= 10;
	}
	return (num + tmp);
}

int digits(int n)
{
	int d = 1;
	while((n /= 10) > 0) ++d;
	return d;
}

int min_rotation(int n)
{
	int min = n, tmp;
	for(int k = 1, km = digits(n); k < km; ++k)
		if((tmp = rotate(n, k, km)) < min)
			min = tmp;
	//
	return min;
}
