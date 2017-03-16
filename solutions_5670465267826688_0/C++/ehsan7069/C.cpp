/*
 * By: Ehsan
 *
 * Contact info: ehsan7069[at]gmail[dot]com
 */

#include <iostream>
#include <string>

using namespace std;

struct Unit {
	
	char v; bool is_neg;

	Unit (char _v = '1', bool _is_neg = false) :
		v(_v), is_neg(_is_neg) { }

	Unit (const Unit & _Unit) :
		v(_Unit.v), is_neg(_Unit.is_neg) { }

	bool operator == (const Unit & _Unit) const {
		return ((v == _Unit.v) && (is_neg == _Unit.is_neg));
	}

	Unit neg () const {
		return Unit(v, !is_neg);
	}

	/*
	Unit inverse () const {
		if (v == '1')
			return (*this);
		return neg();
	}*/

	Unit operator * (const Unit & _Unit) const {
		if (is_neg)
			return (neg() * _Unit).neg();
		if (_Unit.is_neg)
			return ((*this) * _Unit.neg()).neg();
		if (v == '1')
			return _Unit;
		if (_Unit.v == '1')
			return (*this);
		if (v == _Unit.v)
			return Unit('1', true);
		if ((v == 'i') && (_Unit.v == 'j'))
			return Unit('k');
		if ((v == 'j') && (_Unit.v == 'k'))
			return Unit('i');
		if ((v == 'k') && (_Unit.v == 'i'))
			return Unit('j');
		return (_Unit * (*this)).neg();
	}

	void output () const {
		cout << (is_neg?'-':'+') << v << endl;
	}

};

const int MAX_LEN = 20 * 10 * 1000;

int L, X;

string data;

Unit mul_forward[MAX_LEN], mul_backward[MAX_LEN];

bool final_result;

void preprocess (const string & my_string) {
	int len = my_string.length();
	mul_forward[0] = Unit(my_string[0]);
	for (int i = 1 ; i < len ; i++)
		mul_forward[i] = (mul_forward[i - 1] * Unit(my_string[i]));
	mul_backward[len - 1] = Unit(my_string[len - 1]);
	for (int i = len - 2 ; i >= 0 ; i--)
		mul_backward[i] = (Unit(my_string[i]) * mul_backward[i + 1]);
	return;
}

void input () {
	cin >> L >> X;
	cin >> data;
	if (((int)data.length()) != L)
		cerr << "OOOOPS" << endl;
	return;
}

bool solve_on_string (const string & my_string) {
	preprocess(my_string);
	int len = my_string.length();
	int first_ind = 0, second_ind = len - 1;
	for (; first_ind < len ; first_ind++)
		if (mul_forward[first_ind] == Unit('i'))
			break;
	if (first_ind == len)
		return false;
	for (; second_ind > first_ind ; second_ind--)
		if (mul_backward[second_ind] == Unit('k'))
			break;
	if (second_ind <= first_ind + 1)
		return false;
	return (mul_backward[first_ind + 1] == Unit('i'));
}

void solve () {
	string my_string ("");
	for (int i = 0 ; i < X ; i++)
		my_string += data;
	final_result = solve_on_string(my_string);
	return;
}

void output (int t) {
	cout << "Case #" << t + 1 << ": ";
	if (final_result)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return;
}

int main () {
	int T;
	cin >> T;
	for (int t = 0 ; t < T ; t++) {
		input();
		solve();
		output(t);
	}
	return 0;

}


