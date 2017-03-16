#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdint.h>
#include <map>
#include <vector>
#include <algorithm>
#include <assert.h>

std::vector<double> A, B;
int32_t cT, T, i, j, k, cnt, score_deceive, score_opt;

void solve()
{
	score_deceive = 0;
	score_opt = 0;
	
	i = k-1; j = k-1;
	cnt = 0;
	for(; i>=0 && j>=0; )
	{
		if(A[i] > B[j])
		{
			if(cnt > 0)
			{
				cnt--;
				score_opt++;
			}
			i--;			
		}
		else
		{
			cnt++;
			j--;
		}
	}
	for(; i>=0; i--)
	{
		if(cnt > 0)
		{
			cnt--;
			score_opt++;
		}
	}
	score_opt = k - score_opt;


	i = k-1; j = k-1;
	cnt = 0;
	for(; i>=0 && j>=0; )
	{
		if(A[i] < B[j])
		{
			if(cnt > 0)
			{
				cnt--;
				score_deceive++;
			}
			j--;			
		}
		else
		{
			cnt++;
			i--;
		}
	}
	for(; j>=0; j--)
	{
		if(cnt > 0)
		{
			cnt--;
			score_deceive++;
		}
	}
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
		finp >> k;
		A.resize(k);
		B.resize(k);
		for(i=0; i<k; i++)
			finp >> A[i];
		for(i=0; i<k; i++)
			finp >> B[i];
		std::sort(A.begin(), A.end());
		std::sort(B.begin(), B.end());
		solve();		
		fout << "Case #" << T << ": " << score_deceive << " " << score_opt << std::endl;
	}
	
	finp.close();
	fout.close();
	std::cout << "done" << std::endl;
	return 0;
}
