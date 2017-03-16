#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdint.h>
#include <map>
#include <vector>
#include <algorithm>
#include <assert.h>

int32_t cT, T, i, j, k, gen;
uint64_t P, Q, g, pow2;
bool bpossible;

uint64_t gcd(uint64_t a, uint64_t b)
{
	uint64_t r;
	for(;;)
	{
		r = a % b;
		if(r==0)
			return b;
		a = b;
		b = r;
	}
	assert(false);
	return 0;
}

bool ispower2(uint64_t x)
{
	return (x&(x-1))==0;
}

int32_t getpower2(uint64_t a)
{
	assert(a > 0);
	assert(ispower2(a));
	int32_t i = 0;
	for(; a > 1; i++)
	{
		a = a / 2;
	}
	return i;
}

bool solve()
{
	g = gcd(P, Q);
	P /= g;
	Q /= g;
	if(!ispower2(Q))
	{
		return false;
	}
	pow2 = getpower2(Q);
	if(pow2 > 40)
	{
		return false;
	}
	for(gen = 0; ; gen++, Q = Q / 2)
	{
		if(P >= Q)
			break;
	}
	return true;	
}

int main(int argc, char** argv)
{
	std::ifstream finp;
	std::ofstream fout;
	finp.open("0.in");
	fout.open("1.out", std::ios::trunc);
	if(!finp.is_open() || !fout.is_open())
	{
		std::cout << "can't open files" << std::endl;
		return -1;
	}
	
	finp >> cT;
	finp.ignore();
	for(T=1; T<=cT; T++)
	{
		std::string str1, str2;
		std::getline(finp, str1, '/');
		std::getline(finp, str2);
		P = strtoull(str1.c_str(), 0, 0);
		Q = strtoull(str2.c_str(), 0, 0);
		//std::cout << P << ", " << Q << std::endl;
		bpossible = solve();
		if(bpossible)
		{	
			fout << "Case #" << T << ": " << gen << std::endl;
		}
		else
		{
			fout << "Case #" << T << ": " << "impossible" << std::endl;
		}
	}
	
	finp.close();
	fout.close();
	std::cout << "done" << std::endl;
	return 0;
}
