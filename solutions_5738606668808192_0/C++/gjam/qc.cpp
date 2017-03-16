#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stack>

using namespace std;

__int128 to_base(__int128 n, int base)
{
	__int128 a = 0;
	__int128 r = 1;
	for (int temp = n; temp > 0; temp = temp >> 1) {
		if(temp % 2) a+= r;
		r*=base;
	}
	return a;
}

bool first_divisor(__int128 n, __int128& d)
{
	if (n%2 == 0) {
		d=2;
	        return false;
	}

	auto num_d = static_cast<long double>(n);
	int limit = static_cast<int>(sqrt(num_d) + 1);
	d=3;
	while(d < limit) {
		if (n % d == 0) {
        		return false;
		}
        	d += 2;
	}
	return true;
}

bool is_jamcoin(__int128 n, int proofs[9])
{
	for (int i=0; i < 9; i++) {
		auto rebased = to_base(n, i+2);
		__int128 d;
		bool is_prime = first_divisor(rebased, d);

		if (is_prime) return false;

		proofs[i] = d;
	}
	return true;
}

string int_to_binary_string(int n)
{
	stack<bool> bits;

	for (int temp = n; temp > 0; temp = temp >> 1) {
		bits.push(temp % 2);
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

void print_jamcoin(int i, int proofs[9])
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
	
	__int128 current = 1;
	for(int i=0;i<n-1;i++) {
		current<<=1;
	}
	current++;

	auto n_found = 0;
	int proofs[9];

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
