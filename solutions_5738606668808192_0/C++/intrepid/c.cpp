/* Round 1B
 * Problem A
 * intrepid
 */
#include <cassert>
#include <cmath>

#include <algorithm>
#include <chrono>
#include <functional>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using namespace chrono;


random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<int> distribution(1,100);
auto myRand = bind(distribution, generator);

typedef long double LD;
typedef int64_t LI;
typedef uint64_t LU;

const LD kPi = acos(static_cast<LD>(-1));

const LU MAX_C = 14;

LU base_mul[11][MAX_C+2];
vector<LU> primes;

void InitBaseMul()
{
	for (int b = 2; b <= 10; ++b)
	{
		LU v = 1;
		for (LU t = 0; t < MAX_C+2; ++t) {
			base_mul[b][t] = v;
			v *= b;
		}
	}
}

bool IsPrime(LU v)
{
	LU l = sqrt((LD)v);
	l+=1;
	for (LU i = 2; i <= l; ++i)
	{
		if (v % i == 0)
			return false;
	}
	return true;
}

void InitPrimes()
{
	ifstream in("primes.dat");
	if (!in.fail())
	{
		LU prime;
		in >> prime;
		while (!in.fail())
		{
			primes.push_back(prime);
			in >> prime;
		}
		cerr << "Loaded " << primes.size() << " primes.\n";
		return;
	}
	
	ofstream out("primes.dat");
	primes.push_back(2);
	primes.push_back(3);
	primes.push_back(5);
	for (LU i = 6; i < 100000000ull; ++i)
	{
		if (IsPrime(i))
			primes.push_back(i);
	}
	for (LU prime : primes) {
		out << prime << "\n";
	}
}

void ToBits(vector<int>& v, int c)
{
	for (size_t i = 0; i < v.size(); ++i) {
		v[i] = c & 1;
		c = c >> 1;
	}
}

LU BitsToBase(const vector<int>& v, int b)
{
	LU r = 0;
	for (size_t i = 0; i < v.size(); ++i)
		r += v[i] * base_mul[b][i];
	return r;
}

LU GetFirstFactor(LU v)
{
	for (size_t i = 0; i < primes.size() && primes[i] < v; ++i) {
		if (v % primes[i] == 0)
			return primes[i];
	}
	return 0;
}

void PrintBits(const vector<int>& bits)
{
	for (size_t i = bits.size(); i > 0; --i)
		cout << bits[i-1];
}

bool doTest()
{
	int N, J;
	cin >> N >> J;
	
	int C = N - 2;
	int T = 1 << (C - 1);
	vector<int> bits(C);
	int acount = 0;
	for (int i = 0; i < T && acount < J; ++i) {
		ToBits(bits, i);
		vector<LU> sol(11);
		int b;
		for (b = 2; b <= 10; ++b) {
			LU v = BitsToBase(bits, b);
			v *= b;
			v += 1 + base_mul[b][C+1];
			sol[b] = GetFirstFactor(v);
			if (!sol[b]) break;
		}
		if (b>10) {
			// OUTPUT answer
			++acount;
			cout << "1";
			PrintBits(bits);
			cout << "1 ";
			for (int b = 2; b <= 10; ++b)
				cout << sol[b] << " ";
			cout << endl;
		}
	}
	
	return true;
}

int main(int /*argc*/, char **/*argv[]*/)
{
	cout << scientific << setprecision(7);
	int runs;
	cin >> runs;
	if ( ! cin.good() )
	{
		cerr << "Error reading runs!\n" << endl;
		return 0;
	}
	InitBaseMul();
	InitPrimes();
	for (int run=1; run <= runs; ++run) {
		cout << "Case #" << run << ":\n";
		
		if ( !doTest() )
		{
			cerr << "Test case failed!" << endl;
			break;
		}
	}
	if ( !cin.good() ) cerr << "Error reading!\n" << endl;
	
	return 0;
}
