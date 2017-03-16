#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <string>
#include <bitset>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <cmath>

typedef unsigned long long int ulli;
typedef   signed long long int slli;
const ulli MAX_ULLI = 0xFFFFFFFFFFFFFFFF;
const ulli MIN_ULLI = 0x0000000000000000;
const slli MAX_SLLI = 0x7FFFFFFFFFFFFFFF;
const slli MIN_SLLI = 0x8000000000000000;
const ulli MOD = 1e9 + 7;

#ifdef __USE_REAL__
typedef long double real;
const real MATH_PI =  3.141592653589793238462643383279502884197169399375105820974944;
const real MATH_E  =  2.718281828459045235360287471352662497757247093699959574966967;
const real eps = 1e-14;
#endif /* __USE_REAL__ */

#ifdef __DEBUG__
template<typename T>
const std::function<T(T)> IdentityFunction = [](const T& v){ return v; };

template<typename T, typename U=T>
std::string to_string(
	const std::list<T> &l, 
	std::function<U(T)> conv = IdentityFunction<T>,
	const std::string delim = ","
)
{
	std::stringstream ss;
	auto itr = l.begin();
	while(itr != l.end())
	{
		ss << conv(*itr);
		++itr;
		if(itr != l.end()) ss << delim;
	}
	return ss.str();
}

template<typename T>
std::ostream& operator<<(std::ostream &os, const std::list<T> &l)
{
	os << to_string(l);
	return os;
}

template<typename T, typename U=T>
std::string to_string(
	const std::vector<T> &v, 
	std::function<U(T)> conv = IdentityFunction<T>,
	const std::string delim = ","
)
{
	std::stringstream ss;
	for(ulli i=0; i<v.size(); ++i)
	{
		ss << conv(v[i]);
		if((i + 1) < v.size()) ss << delim;
	}
	return ss.str();
}

template<typename T>
std::ostream& operator<<(std::ostream &os, const std::vector<T> &v)
{
	os << to_string(v);
	return os;
}

template<typename T, typename U=T, std::size_t N>
std::string to_string(
	const std::array<T, N> &a, 
	std::function<U(T)> conv = IdentityFunction<T>,
	const std::string delim = ","
)
{
	std::stringstream ss;
	for(std::size_t i=0; i<N; ++i)
	{
		ss << conv(a[i]);
		if((i + 1) < N) ss << delim;
	}
	return ss.str();
}

template<typename T, std::size_t N>
std::ostream& operator<<(std::ostream &os, const std::array<T, N> &a)
{
	os << to_string(a);
	return os;
}

template<typename T, typename U=T>
std::string to_string(
	const std::set<T> &s, 
	std::function<U(T)> conv = IdentityFunction<T>,
	const std::string delim = ","
)
{
	std::stringstream ss;
	auto itr = s.begin();
	while(itr != s.end())
	{
		ss << conv(*itr);
		++itr;
		if(itr != s.end()) ss << delim;
	}
	return ss.str();
}

template<typename T>
std::ostream& operator<<(std::ostream &os, const std::set<T> &s)
{
	os << to_string(s);
	return os;
}
#endif /* __DEBUG__ */

template<typename T, class InputIterator>
inline bool have(
	InputIterator first, 
	InputIterator last, 
	const T &val
)
{
	return std::find(first, last, val) != last;
}

template<class InputIterator, class UnaryPred>
inline bool have_if(
	InputIterator first, 
	InputIterator last, 
	UnaryPred pred
)
{
	return std::find_if(first, last, pred) != last;
}

std::string solve(const std::string &S)
{
	std::array<int, 26> counter;
	for(unsigned i=0; i<26; ++i) counter[i] = 0;
	
	for(unsigned i=0; i<S.size(); ++i)
	{
		++counter[S[i] - 'A'];
	}
	
	int eight = counter['G' - 'A'];
	counter['E' - 'A'] -= eight;
	counter['I' - 'A'] -= eight;
	counter['G' - 'A'] -= eight;
	counter['H' - 'A'] -= eight;
	counter['T' - 'A'] -= eight;
	
	int four = counter['U' - 'A'];
	counter['F' - 'A'] -= four;
	counter['O' - 'A'] -= four;
	counter['U' - 'A'] -= four;
	counter['R' - 'A'] -= four;
	
	int two = counter['W' - 'A'];
	counter['T' - 'A'] -= two;
	counter['W' - 'A'] -= two;
	counter['O' - 'A'] -= two;
	
	int six = counter['X' - 'A'];
	counter['S' - 'A'] -= six;
	counter['I' - 'A'] -= six;
	counter['X' - 'A'] -= six;
	
	int zero = counter['Z' - 'A'];
	counter['Z' - 'A'] -= zero;
	counter['E' - 'A'] -= zero;
	counter['R' - 'A'] -= zero;
	counter['O' - 'A'] -= zero;
	
	int five = counter['F' - 'A'];
	counter['F' - 'A'] -= five;
	counter['I' - 'A'] -= five;
	counter['V' - 'A'] -= five;
	counter['E' - 'A'] -= five;
	
	int three = counter['H' - 'A'];
	counter['T' - 'A'] -= three;
	counter['H' - 'A'] -= three;
	counter['R' - 'A'] -= three;
	counter['E' - 'A'] -= three;
	counter['E' - 'A'] -= three;
	
	int seven = counter['S' - 'A'];
	counter['S' - 'A'] -= seven;
	counter['E' - 'A'] -= seven;
	counter['V' - 'A'] -= seven;
	counter['E' - 'A'] -= seven;
	counter['N' - 'A'] -= seven;
	
	int one = counter['O' - 'A'];
	counter['O' - 'A'] -= one;
	counter['N' - 'A'] -= one;
	counter['E' - 'A'] -= one;
	
	int nine = counter['I' - 'A'];
	counter['N' - 'A'] -= nine;
	counter['I' - 'A'] -= nine;
	counter['N' - 'A'] -= nine;
	counter['E' - 'A'] -= nine;
	
	std::array<int, 10> result = {zero, one, two, three, four, five, six, seven, eight, nine};
	std::string T = "";
	for(unsigned i=0; i<10; ++i)
	{
		for(unsigned j=0; j<result[i]; ++j)
		{
			T += ('0' + i);
		}
	}
	
	return T;
}

int main()
{
	unsigned T;
	std::cin >> T;
	
	for(unsigned t=0; t<T; ++t)
	{
		std::string S;
		std::cin >> S;
		
		std::cout << "Case #" << (t+1) << ": " << solve(S) << std::endl;
	}
	
	return 0;
}
