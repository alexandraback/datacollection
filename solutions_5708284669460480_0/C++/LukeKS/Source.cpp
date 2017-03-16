#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

//#define test
#define small 
//#define large

double round(double x, int prec)
{
	double power = 1.0;
	int i;

	if (prec > 0)
		for (i = 0; i < prec; i++)
			power *= 10.0;
	else if (prec < 0)
		for (i = 0; i < prec; i++)
			power /= 10.0;

	if (x > 0)
		x = floor(x * power + 0.5) / power;
	else if (x < 0)
		x = ceil(x * power - 0.5) / power;

	if (x == -0)
		x = 0;

	return x;
}

short calc(std::vector<char> &probe, short &S, short &L, std::vector<char> &Word)
{
	bool inword = false;
	char ch;
	short count = 0, bananas = 0;
	for (short i = 0; i < S; i++)
	{
		ch = probe[i];
		if (!inword)
		{
			if (ch == Word[0])
			{
				inword = true;
				count = 1;
			}
		}
		else{
			if (ch == Word[count])
				count++;
		}
		if (count == L)
		{
			bananas++;
			inword = false;
			i = i - L + 1;
			count = 0;
		}
	}
	return bananas;
}

void fill(std::vector<char> probe, short count, std::vector<short> &pay, short &K, std::vector<char> &Letters, short &S, std::vector<char> &Word, short &L)
{
	if (count == S)
	{
		pay.push_back(calc(probe, S, L, Word));
		return;
	}
	for (short i = 0; i < K; i++)
	{
		probe[count] = Letters[i];
		fill(probe, count + 1, pay, K, Letters, S, Word, L);
	}
}

double expected(short &K, short &L, short &S, std::vector<char> &Letters, std::vector<char> & Word)
{
	std::vector<short> pay;
	std::vector<char> probe(S);
	short count = 0;
	char ch;
	fill(probe, count, pay, K, Letters, S, Word, L);
	double exp = 0;
	long long sz = pay.size();
	long long var = pow(K, S);
	double py;
	for (int i = 0; i < sz; i++)
	{
		py = pay[i];
		exp += py / var;
	}
	return exp;
}

bool within(char &ch, std::vector<char> &Letters, short &K)
{
	for (short i = 0; i < K; i++)
	{
		if (Letters[i] == ch)
			return true;
	}
	return false;
}

void solve()
{
	short K, L, S;
	char ch;
	std::cin >> K >> L >> S;
	std::vector<char> Letters(K);
	std::cin.get(ch);
	for (short i = 0; i < K; i++)
	{
		std::cin.get(ch);
		//if (ch == '\n')
		Letters[i] = ch;
	}
	std::vector<char> Word(L);
	bool possible = true;
	std::cin.get(ch);
	for (short i = 0; i < L; i++)
	{
		std::cin.get(ch);
		Word[i] = ch;
		if (!within(ch, Letters, K))
			possible = false;
	}
	if (S < L)
		possible = false;
	short max = 0;
	double exp = 0;
	if (possible)
	{
		std::vector<char> perf;
		short count = 0;
		for (short i = 0; i < S; i++)
		{
			perf.push_back(Word[count]);
			count++;
			if (count == L)
				count = 0;
		}
		max = calc(perf, S, L, Word);
		bool alleq = false;
		if (S == L && L == K)
		{
			alleq = true;
			for (short j = 0; j < S; j++)
			{
				if (Word[j] != Letters[j])
					alleq = false;
			}
		}
		if (alleq)
			exp = max;
		else
			exp = expected(K, L, S, Letters, Word);
	}
	double result = max - exp;
	std::cout << std::setprecision(8) << round(result, 8);
	if (floor(result) == round(result, 8))
		std::cout << ".0";
	std::cout << std::endl;
}

int main()
{
#if defined(test)
	std::ifstream in("in.in");
#elif defined(small)
	std::ifstream in("B-small-attempt3.in");
#elif defined(large)
	std::ifstream in("B-large.in");
#endif
	std::cin.rdbuf(in.rdbuf());
	std::ofstream out("out.out");
	std::cout.rdbuf(out.rdbuf());

	short T;
	std::cin >> T;

	for (short i = 1; i <= T; i++)
	{
		std::cout << "Case #" << i << ": ";
		solve();
	}
}