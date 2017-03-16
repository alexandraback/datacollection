#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdint.h>
#include <map>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <string.h>

char F[64][64];
uint32_t rows0, cols0, mines0, rows, cols, mines, total;
bool bTransposed, bPossible;
uint32_t cT, T, i, j;

char & elemF(uint32_t i, uint32_t j)
{
	assert(1 <= i && i <= rows && 1 <= j && j <= cols);
	i--;
	j--;
	if(!bTransposed)
	{
		return F[i][j];
	}
	else
	{
		return F[j][i];
	}
}

void initF()
{
	memset(F, 0, sizeof(F));
	bTransposed = rows0 > cols0;
	if(bTransposed)
	{
		rows = cols0;
		cols = rows0;
	}
	else
	{
		rows = rows0;
		cols = cols0;
	}
	total = rows*cols;
}

void fillF(char c)
{
	for(i=1; i<=rows; i++)
		for(j=1; j<=cols; j++)
			elemF(i,j) = c;
}

void solve()
{
	uint32_t left, fill;
	bPossible = false;
	left = total - mines;
	fillF('*');
	if(rows==1)
	{
		bPossible = true;
		for(j=1; j<=left; j++)
			elemF(1, j) = 0;
		elemF(1,1) = 'c';
		return;
	}
	if(rows==2)
	{
		bPossible = (left==1) || (left>=4 && (left%2)==0);
		if(!bPossible)
			return;
		for(j=1; 2*j<=left; j++)
		{
			elemF(1, j) = 0;
			elemF(2, j) = 0;
		}
		elemF(1,1) = 'c';
		return;		
	}
	bPossible = !((left==2) || (left==3) || (left==5) || (left==7));
	if(!bPossible)
		return;
	elemF(1,1) = 'c';
	if(left ==1)
	{
		return;
	}
	if(left >= 4)
	{
		elemF(1,2) = 0;
		elemF(2,1) = 0;
		elemF(2,2) = 0;
		left -= 4;
	}
	if(left >= 2)
	{
		elemF(3,1) = 0;
		elemF(3,2) = 0;
		left-=2;
	}
	if(left >= 2)
	{
		elemF(1,3) = 0;
		elemF(2,3) = 0;
		left-=2;
	}
	if(left==0) 
		return;
	for(i=4; i<=rows && left>=2; i++)
	{
		elemF(i,1) = 0;
		elemF(i,2) = 0;
		left-=2;
	}
	for(j=4; j<=cols && left>=2; j++)
	{
		elemF(1,j) = 0;
		elemF(2,j) = 0;
		left-=2;
	}
	for(i=3; i<=rows && left>=1; i++)
	{
		for(j=3; j<=cols && left>=1; j++)
		{
			elemF(i,j) = 0;
			left--;
		}
	}
	return;
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
		finp >> rows0 >> cols0 >> mines0;
		mines = mines0;
		bPossible = false;
		initF();
		solve();
		fout << "Case #" << T << ": " << std::endl;
		if(bPossible)
		{
			uint32_t cnt = 0;
			for(i=0; i<rows0; i++)
			{
				for(j=0; j<cols0; j++)
				{
					if(F[i][j]=='*')
					{
						cnt++;
					}
				}
			}
			assert(cnt==mines0);
			
			for(i=0; i<rows0; i++)
			{
				for(j=0; j<cols0; j++)
				{
					if(tolower(F[i][j])=='c')
					{
						fout << "c";
					}
					else 
					if(tolower(F[i][j])=='*')
					{
						fout << "*";
					}
					else 
					{
						fout << ".";
					}
				}
				fout << std::endl;
			}
		}
		else
		{
			fout << "Impossible" << std::endl;
		}	
	}
	
	finp.close();
	fout.close();
	std::cout << "done" << std::endl;
	return 0;
}
