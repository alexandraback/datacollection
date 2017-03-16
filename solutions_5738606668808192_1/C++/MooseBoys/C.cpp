#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "BigInteger.hh" // https://mattmccutchen.net/bigint/

using namespace std;

static const vector<unsigned int> primes{
	/* 2, */ 3, 5, 7, 11, 13, 17, 19, 23, 29, 31,
	37, 41, 43, 47, 53, 59, 61, 67, 71, 73,
	79, 83, 89, 97, 101, 103, 107, 109, 113,
	127, 131, 137, 139, 149, 151, 157, 163,
	167, 173, 179, 181, 191, 193, 197, 199,
	211, 223, 227, 229, 233, 239, 241, 251 };

vector<unsigned int> GetDivisors(unsigned int coin, int check, int N)
{
	vector<unsigned int> divisors;
	for (int base = 2; base <= 10; base++)
	{
		BigInteger sum = 0;
		BigInteger digit = 1;
		for (int i = 0; i < N; i++)
		{
			if ((coin >> i) & 1)
			{
				sum += digit;
			}
			digit *= base;
		}
		bool match = false;
		for (int i = 0; i < check && !match; i++)
		{
			if (sum % primes[i] == 0)
			{
				divisors.push_back(primes[i]);
				match = true;
			}
		}
		if (!match) return divisors;
	}
	return divisors;
}

vector<pair<unsigned int, vector<unsigned int>>> GenerateJamCoins(int N, int J)
{
	cout << "Finding " << J << " " << N << "-digit JamCoins..." << endl;
    vector<pair<unsigned int, vector<unsigned int>>> jamCoins;
    unsigned int numCoins = 1 << (N - 2);
    unsigned int outer = (1 << (N - 1)) | 1;
	for (int check = 3; check <= static_cast<int>(primes.size()) && static_cast<int>(jamCoins.size()) < J; check++)
	{
		cout << "Checking primes {";
		for (int i = 0; i < check; i++)
		{
			cout << primes[i];
			if (i < check - 1) cout << ",";
		}
		cout << "}" << endl;
		for (unsigned int inner = 0; inner < numCoins && static_cast<int>(jamCoins.size()) < J; inner++)
		{
			unsigned int coin = (inner << 1) | outer;
			auto divisors = GetDivisors(coin, check, N);
			if(divisors.size() == 9)
			{
				jamCoins.push_back(make_pair(coin, divisors));
			}
		}
	}
	return jamCoins;
}

void SaveCoins(const vector<pair<unsigned int, vector<unsigned int>>>& coins, int N, string filename)
{
	ofstream out(filename);
	out << "Case #1:" << endl;
	for (const auto& coin : coins)
	{
		for (int i = N - 1; i >= 0; i--)
		{
			out << ((((coin.first >> i) & 1) == 1) ? '1' : '0');
		}
		for (const auto& divisor : coin.second)
		{
			out << " " << divisor;
		}
		out << endl;
	}
}

int main(int argc, char* argv[])
{
    auto coins16 = GenerateJamCoins(16, 50);
	SaveCoins(coins16, 16, "C-small-out.txt");
    auto coins32 = GenerateJamCoins(32, 500);
	SaveCoins(coins32, 32, "C-large-out.txt");
    return 0;
}
