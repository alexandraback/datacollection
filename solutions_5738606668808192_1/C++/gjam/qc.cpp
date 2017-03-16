#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stack>
#include <boost/multiprecision/gmp.hpp>

using namespace std;
namespace mp = boost::multiprecision;

mp::mpz_int to_base(mp::mpz_int n, int base)
{
	mp::mpz_int a = 0;
	mp::mpz_int r = 1;
	for (auto temp = n; temp > 0; temp = temp >> 1) {
		if(temp % 2) a+= r;
		r*=base;
	}
	return a;
}

bool first_divisor(mp::mpz_int n, mp::mpz_int& d)
{
	if (n%2 == 0) {
		d=2;
	        return false;
	}

	mp::number<mp::gmp_float<128>> num_d = n;
	mp::mpz_int limit = static_cast<mp::mpz_int>(2^16);
	d=3;
	while(d < limit) {
		if (n % d == 0) {
        		return false;
		}
        	d += 2;
	}
	return true;
}

bool is_jamcoin(mp::mpz_int n, mp::mpz_int proofs[9])
{
	for (int i=0; i < 9; i++) {
		auto rebased = to_base(n, i+2);
		mp::mpz_int d;
		bool is_prime = first_divisor(rebased, d);

		if (is_prime) return false;

		proofs[i] = d;
	}
	return true;
}

string int_to_binary_string(mp::mpz_int n)
{
	stack<bool> bits;

	for (mp::mpz_int temp = n; temp > 0; temp = temp >> 1) {
		bits.push((temp % 2)!=0);
	}

	string s;
	ostringstream o(s);
	while (!bits.empty())
	{
		if (bits.top()) o<<'1';
		else o<<'0';
		bits.pop();
	}
	return o.str();
}

void print_jamcoin(mp::mpz_int i, mp::mpz_int proofs[9])
{
	cout<<int_to_binary_string(i)<<" "<<proofs[0];

	for(int i = 1; i < 9; i++)
	{
		cout<<" "<<proofs[i];
	}
	cout<<"\n";
}

string run_test(string line)
{
	cout<<"\n";

	istringstream iss(line);
	string temp;
	iss >> temp;
	auto n = stoi(temp);
	iss >> temp;
	auto j = stoi(temp);

	string retval;
	ostringstream oss(retval);
	
	mp::mpz_int current(1);
	for(int i=0;i<n-1;i++) {
		current<<=1;
	}
	current++;

	auto n_found = 0;
	mp::mpz_int proofs[9];

	while(n_found < j)
	{
		fill_n(proofs, 9, 0);
		if (is_jamcoin(current, proofs)) {
			print_jamcoin(current, proofs);
			n_found++;
		}
		current += 2;
	}

	return oss.str();
}

int main()
{
	string line;
	getline(cin,line);

	auto n_tests = stoi(line);	

	for(int i = 0; i < n_tests; i++) {		
		getline(cin,line);

		cout<<"Case #"<<i+1<<": ";

		auto result = run_test(line);

		cout<<result<<"\n";	
	}
}
