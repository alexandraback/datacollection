#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>

#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cassert>


//#include <boost/multiprecision/cpp_int.hpp> 
typedef long long ll;

using namespace std;

const ll MOD = 1000000007ll;



struct Task
{
	string simplify1(string s)
	{
		string ret;
		ret += s[0];
		char prev = s[0];

		for (size_t i = 1; i < s.size(); ++i)
		{
			if (s[i] != prev) {
				ret.push_back(s[i]);
				prev = s[i];
			}
		}

		return ret;
	}


	void printcarts(vector<string> carts)
	{
		for (int i = 0; i < (int)carts.size(); ++i) {
			std::cerr << carts[i] << " ";
		}
		std::cerr << endl;
	}


	ll solve(int n, vector<string> carts)
	{
		vector<int> begincount(128);
		vector<int> endcount(128);
		vector<int> centercount(128);
		//step 1 - simplify carts 1
		for (string& cart : carts) {
			cart = simplify1(cart);
		}

		printcarts(carts);

		//step 2 - possibility checks
		for (string& cart : carts) {
			if (cart[0] != cart[cart.size() - 1]) {
				++begincount[cart[0]];
				++endcount[cart[cart.size() - 1]];
			}
			for (size_t i = 1; i < cart.size() - 1; ++i) {
				++centercount[cart[i]];
			}
		}

		for (int letter = 0; letter < 128; ++letter)
		{
			if (
				centercount[letter] > 1 ||
				(1 == centercount[letter] && begincount[letter]) ||
				(1 == centercount[letter] && endcount[letter])
				) {
				cerr << "Invalid in center: " << (char)letter << endl;
				return 0;
			}
			if (begincount[letter] > 1) {
				cerr << "Double begin: " << (char)letter << endl;
				return 0;
			}
			if (endcount[letter] > 1) {
				cerr << "Double end: " << (char)letter << endl;
				return 0;
			}
		}



		//step 3 - simplify carts even more
		for (string& cart : carts) {
			cart = string() + cart[0] + cart[cart.size() - 1];
		}

		printcarts(carts);


		//step 4 - group carts
		map<char, char> ab_carts;
		map<char, int> aa_carts;
		map<char, int> uu_carts;

		for (string& cart : carts) {
			if (cart[0] == cart[1]) {
				if (begincount[cart[0]] || endcount[cart[0]]) {
					++aa_carts[cart[0]];
				}
				else {
					++uu_carts[cart[0]];
				}
			}
			else {
				ab_carts[cart[0]] = cart[1];
			}
		}

		cout << "AB carts:" << endl;
		for (auto x : ab_carts) {
			cout << "    " << x.first << "->" << x.second << endl;
		}



		//step 5a - create chains of ab carts
		int chunkcount = 0;
		vector<vector<string>> chunks;
		for (int letter = 0; letter < 128; ++letter)
		{
			if (begincount[letter] && !endcount[letter]) {
				++chunkcount;
				chunks.emplace_back();

				int curr = letter;
				do {
					auto it = ab_carts.find(curr);
					if (it == ab_carts.end()) {
						throw std::logic_error("impossible1");
					}
					pair<char, char> act = *it;
					--begincount[act.first];
					--endcount[act.second];

					string str = string() + act.first + act.second;
					chunks.back().push_back(str);

					curr = act.second;
				} while (begincount[curr]);
			}
		}

		//step 5a - check for remainders
		for (int letter = 0; letter < 128; ++letter)
		{
			if (begincount[letter]) {
				cout << "Cart beginning with " << letter << " remains." << endl;
				return 0;
			}
			if (endcount[letter]) {
				cout << "Cart ending with " << letter << " remains." << endl;
				return 0;
			}
		}

		cout << "Chunks: " << endl;
		for (auto chunk : chunks)
		{
			cout << "    ";
			printcarts(chunk);
		}


		//step 6 - count
		ll ret = 1;
		for (int i = 0; i < chunkcount; ++i) {
			//check if round chunk
			if (chunks[i].front()[0] == chunks[i].back()[1]) {
				return 0;
				//can begin anywhere
				/*ret *= (ll)chunks[i].size();
				ret %= MOD;*/
			}

			ret *= (ll)(i+1);
			ret %= MOD;
		}

		for (const auto &x : aa_carts) {
			for (ll i = 1; i <= (ll)x.second; ++i)
			{
				ret *= i;
				ret %= MOD;
			}
		}

		int foo = chunkcount;
		for (const auto &x : uu_carts) {
			for (ll i = 1; i <= (ll)x.second; ++i)
			{
				ret *= i;
				ret %= MOD;
			}
			++foo;
			ret *= (ll)foo;
			ret %= MOD;
		}

		return ret;
	}
};



int main() {
	//string fnprefix = "B-large";
	string fnprefix = "B-small-attempt2";
	//string fnprefix = "B-test";
	ifstream f(fnprefix + ".in");
	ofstream o(fnprefix + ".out");
	istream &in = f;

	int tn = -1;
	in >> tn;
	if (tn < 0)
	{
		cerr << "Error reading input." << endl;
	}

	for (int ti = 0; ti < tn; ++ti)
	{
		int n;
		in >> n;

		vector<string> input;
		for (int i = 0; i < n; ++i)
		{
			string x;
			in >> x;
			input.push_back(x);
		}

		Task t;
		auto sol = t.solve(n, input);

		string res = to_string(sol);

		o << "Case #" << (ti + 1) << ": " << res << endl;
		cerr << "Case #" << (ti + 1) << ": " << res << endl;
	}

	system("pause");

	return 0;
}


