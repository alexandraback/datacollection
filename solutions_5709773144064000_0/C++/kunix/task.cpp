#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdint.h>
#include <map>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <math.h>
#include <iomanip>

double C, F, X;

double func(uint32_t n)
{
	uint32_t i, j;
	double sum1, sum2;
	sum2 = sum1 = 0;
	for(i=n; i>0; i--)
	{
		j = i-1;
		sum1 += 1/(2 + j*F);
	}
	sum1 *= C;
	sum2 = X / (2 + n*F);
	return sum1 + sum2;
}

double calc_n0()
{
	return X/C - 2/F;
}

int main(int argc, char** argv)
{
	uint32_t cT, T, i, j;
	
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
		double n0, n1, n2, mintime;
		finp >> C >> F >> X;
		mintime = func(0);
		n0 = calc_n0();
		std::cout << std::setprecision(18) << C << "  |  " << F << "  |  " << X << "  |  " << mintime << "  |  " << n0 << std::endl;
		n1 = floor(n0);
		n2 = std::max((double)0, n1 + 10);
		n1 = std::max((double)0, n1 - 10);
		i = (uint32_t)n1;
		j = (uint32_t)n2;
		for(; i<=j; i++)
		{
			mintime = std::min(mintime, func(i));
		}
		fout << "Case #" << T << ": " << std::setprecision(18) << mintime << std::endl;
	}
	
	finp.close();
	fout.close();
	std::cout << "done" << std::endl;
	return 0;
}
