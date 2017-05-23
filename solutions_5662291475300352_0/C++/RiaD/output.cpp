/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author RiaD
 */

#include <iostream>
#include <fstream>

#include <iostream>
#include <bits/stdc++.h>


#include <iterator>

#include <string>
#include <stdexcept>
#ifdef SPCPPL_DEBUG
	#define SPCPPL_ASSERT(condition) \
	if(!(condition)) { \
		throw std::runtime_error(std::string() + #condition + " in line " + std::to_string(__LINE__) + " in " + __PRETTY_FUNCTION__); \
	}
#else
	#define SPCPPL_ASSERT(condition)
#endif



/**
* Support decrementing and multi-passing, but not declared bidirectional(or even forward) because
* it's reference type is not a reference.
*
* It doesn't return reference because
* 1. Anyway it'll not satisfy requirement [forward.iterators]/6
*   If a and b are both dereferenceable, then a == b if and only if *a and
*   b are bound to the same object.
* 2. It'll not work with reverse_iterator that returns operator * of temporary which is temporary for this iterator
*
* Note, reverse_iterator is not guaranteed to work  now too since it works only with bidirectional iterators,
* but it's seems to work at least on my implementation.
*
* It's not really useful anywhere except iterating anyway.
*/
template <typename T>
class IntegerIterator : public std::iterator<std::input_iterator_tag, T, std::ptrdiff_t, T*, T> {
public:
	explicit IntegerIterator(int value): value(value) {

	}

	IntegerIterator& operator++ () {
		++value;
		return *this;
	}

	IntegerIterator operator++ (int) {
		IntegerIterator copy = *this;
		++value;
		return copy;
	}

	IntegerIterator& operator-- () {
		--value;
		return *this;
	}

	IntegerIterator operator-- (int) {
		IntegerIterator copy = *this;
		--value;
		return copy;
	}

	T operator * () const {
		return value;
	}

	bool operator == (IntegerIterator rhs) {
		return value == rhs.value;
	}

	bool operator != (IntegerIterator rhs) {
		return !(*this == rhs);
	}
private:
	T value;
};

template <typename T>
class IntegerRange {
public:
	IntegerRange(T begin, T end): begin_(begin), end_(end) {

	}

	IntegerIterator<T> begin() const {
		return IntegerIterator<T>(begin_);
	}

	IntegerIterator<T> end() const {
		return IntegerIterator<T>(end_);
	}

private:
	T begin_;
	T end_;
};

template <typename T>
class ReversedIntegerRange {
	typedef std::reverse_iterator<IntegerIterator<T>> IteratorType;
public:
	ReversedIntegerRange(T begin, T end): begin_(begin), end_(end) {

	}

	IteratorType begin() const {
		return IteratorType(IntegerIterator<T>(begin_));
	}

	IteratorType end() const {
		return IteratorType(IntegerIterator<T>(end_));
	}

private:
	T begin_;
	T end_;
};

template <typename T>
IntegerRange<T> range(T to) {
	SPCPPL_ASSERT(to >= 0);
	return IntegerRange<T>(0, to);
}

template <typename T>
IntegerRange<T> range(T from, T to) {
	SPCPPL_ASSERT(from <= to);
	return IntegerRange<T>(from, to);
}

template <typename T>
ReversedIntegerRange<T> downrange(T from) {
	SPCPPL_ASSERT(from >= 0);
	return ReversedIntegerRange<T>(from, 0);
}

template <typename T>
ReversedIntegerRange<T> downrange(T from, T to) {
	SPCPPL_ASSERT(from >= to);
	return ReversedIntegerRange<T>(from, to);
}


#include <algorithm>


template<typename R>
void sort(R &range) {
	std::sort(range.begin(), range.end());
}

template<typename R, typename Comp>
void sort(R &range, Comp comp) {
	std::sort(range.begin(), range.end(), comp);
}

template<typename R>
void reverse(R &range) {
	std::reverse(range.begin(), range.end());
}

template<typename R, typename T>
auto lower_bound(const R &range, const T &value) -> decltype(range.begin()) {
	return std::lower_bound(range.begin(), range.end(), value);
}

template<typename R, typename T, typename Comp>
auto lower_bound(const R &range, const T &value, Comp comp) -> decltype(range.begin()) {
	return std::lower_bound(range.begin(), range.end(), value, comp);
}

template<typename R, typename T>
auto upper_bound(const R &range, const T &value) -> decltype(range.begin()) {
	return std::upper_bound(range.begin(), range.end(), value);
}

template<typename R, typename T, typename Comp>
auto upper_bound(const R &range, const T &value, Comp comp) -> decltype(range.begin()) {
	return std::upper_bound(range.begin(), range.end(), value, comp);
}

template <typename R>
auto unique(R& range) -> decltype(range.begin()) {
	return std::unique(range.begin(), range.end());
}

template <typename R>
auto min_element(const R& range) -> decltype(range.begin()) {
	return std::min_element(range.begin(), range.end());
}

template <typename R>
auto max_element(const R& range) -> decltype(range.begin()) {
	return std::max_element(range.begin(), range.end());
}

template <typename R>
bool next_permutation(R& range) {
	return std::next_permutation(range.begin(), range.end());
}

template <typename R>
R sorted(R range) {
	sort(range);
	return range;
}

template <typename R, typename Comp>
R sorted(R range, Comp comp) {
	sort(range, comp);
	return range;
}

template <typename R>
R reversed(R range) {
	reverse(range);
	return range;
}





#include <type_traits>

template <typename T>
T identity();

//FIXME: remove {} when CPP-1825 fixed.
template<typename T, typename Enable = std::true_type>
struct impl__IdentityHelper {
};

template <typename T>
struct impl__SampleIdentityHelper {
	static T identity(const T&) {
		return ::identity<T>();
	}
};

template<typename T>
struct impl__IdentityHelper<T, typename std::is_arithmetic<T>::type> {
	static T identity() {
		return 1;
	}
};

template<typename T>
T identity(const T& sample) {
	return impl__SampleIdentityHelper<T>::identity(sample);
}

template <typename T>
T identity() {
	return impl__IdentityHelper<T>::identity();
}



template <typename T>
T gcd(T a, T b) {
	while (b) {
		T tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}


template <typename T>
class Rational {
public:
	Rational():numerator(0), denominator(1) {
	}
	Rational(T numerator): numerator(numerator), denominator(1) {
	}
	Rational(T numerator, T denominator): numerator(numerator), denominator(denominator) {
		SPCPPL_ASSERT(denominator != 0);
		normalize();
	}

	Rational& operator += (const Rational& rhs) {
		return *this = *this + rhs;
	}

	Rational& operator -= (const Rational& rhs) {
		return *this = *this - rhs;
	}

	Rational& operator *= (const Rational& rhs) {
		numerator *= rhs.numerator;
		denominator *= rhs.denominator;
		normalize();
		return *this;
	}

	Rational operator - () const {
		return Rational(-numerator, denominator);
	}

	Rational& operator /= (const Rational& rhs) {
		SPCPPL_ASSERT(rhs.numerator != 0);
		numerator *= rhs.denominator;
		denominator *= rhs.numerator;
		normalize();
		return *this;
	}

	bool operator == (const Rational& rhs) const {
		return numerator == rhs.numerator && denominator == rhs.denominator;
	}

	const T& getNumerator() const {
		return numerator;
	}

	const T& getDenominator() const {
		return denominator;
	}
private:

	void normalize() {
		T g = gcd(numerator, denominator);
		numerator /= g;
		denominator /= g;

		if(denominator < 0) {
			numerator = -numerator;
			denominator = -denominator;
		}
	}
	T numerator, denominator;

	template <typename U>
	friend Rational<U> operator + (const Rational<U>& lhs, const Rational<U>& rhs);
};


template <typename T>
Rational<T> operator + (const Rational<T>& lhs, const Rational<T>& rhs) {
	T g = gcd(lhs.denominator, rhs.denominator);
	return Rational<T>(
			lhs.numerator * (rhs.denominator / g) + rhs.numerator * (lhs.denominator / g),
			lhs.denominator / g * rhs.denominator
	);
}

template <typename T>
Rational<T> operator - (const Rational<T>& lhs, const Rational<T>& rhs) {
	return lhs + (-rhs);
}

template <typename T>
Rational<T> operator * (const Rational<T>& lhs, const Rational<T>& rhs) {
	Rational<T> copy = lhs;
	return copy *= rhs;
}

template <typename T>
Rational<T> operator / (const Rational<T>& lhs, const Rational<T>& rhs) {
	Rational<T> copy = lhs;
	return copy /= rhs;
}

template <typename T>
std::ostream& operator <<(std::ostream& stream, const Rational<T>& rational) {
	return stream << rational.getNumerator() << '/' << rational.getDenominator();
}
template <typename T>
struct impl__IdentityHelper<Rational<T>> {
	static Rational<T> identity() {
		return Rational<T>(1);
	}
};

template <typename T>
bool operator == (const Rational<T>& lhs, const Rational<T>& rhs) {
	return lhs.getNumerator() * rhs.getDenominator() == lhs.getDenominator() * rhs.getNumerator();
}

template <typename T>
bool operator != (const Rational<T>& lhs, const Rational<T>& rhs) {
	return !(lhs == rhs);
}

template <typename T>
bool operator < (const Rational<T>& lhs, const Rational<T>& rhs) {
	return lhs.getNumerator() * rhs.getDenominator() < lhs.getDenominator() * rhs.getNumerator();
}

template <typename T>
bool operator > (const Rational<T>& lhs, const Rational<T>& rhs) {
	return rhs < lhs;
}

template <typename T>
bool operator <= (const Rational<T>& lhs, const Rational<T>& rhs) {
	return !(lhs > rhs);
}

template <typename T>
bool operator >= (const Rational<T>& lhs, const Rational<T>& rhs) {
	return !(lhs < rhs);
}



using namespace std;

class TaskC {
public:
	void solve(std::istream& in, std::ostream& out) {
		static int testNumber = 0;
		++testNumber;


		int n;
		in >> n;

		int cnt = 0;
		map<long long, int> changes;
		for (int i = 0; i < n; ++i) {
			int d, m, h;
			in >> d >> h >> m;
			cnt += h;
			for (int i: range(h)) {
				int time = m + i;
				changes[time * (360LL - d)] -= 1;
				for (int j: range(1, 20)) {
					changes[time * (360LL - d + j * 360LL)] += 1;
				}
			}
		}


		int cur = cnt;
		int ans = cnt;
		for (auto it = changes.begin(); it != changes.end(); ++it) {
			//cerr << it->first << ' ' << it->second << endl;
			cur += it->second;
			ans = min(ans, cur);
		}

		out << "Case #" << testNumber << ": " << ans << "\n";

	}

};


int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(0);
	std::cout << std::fixed;
	std::cout.precision(20);
	TaskC solver;
	std::ifstream in("/home/riad/Downloads/c.in");
	std::ofstream out("/home/riad/Downloads/c.out");
	int n;
in >> n;
for(int i = 0; i < n; ++i) {
	solver.solve(in, out);
}

	return 0;
}