#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdint.h>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <assert.h>
#include <string.h>

struct ARROW
{
	std::string str;
	int32_t dest;
};

struct char_PROP
{
	bool bBeg, bEnd;
	bool bUsed;
};

char_PROP props[256];
ARROW	   arrows[256];
uint32_t   cons[256];
std::list<std::string> strs;

const uint64_t modulo = 1000000007;

int32_t cT, T, i, j, k, gen;
uint64_t P, Q, g, count;

void mul(uint64_t m)
{
	m = m % modulo;
	count = count * m;
	count = count % modulo;
}

void mulf(uint64_t f)
{
	for(; f > 1; f--)
		mul(f);
}

bool reset()
{
	count = 1;
	memset(props, 0, sizeof(props));
	memset(cons, 0, sizeof(cons));
	for(i=0; i<256; i++)
	{
		arrows[i].dest = 0;
		arrows[i].str = "";
	}
	strs.clear();
}

bool classify()
{
	for(std::list<std::string>::iterator it = strs.begin(); it != strs.end(); it++)
	{
		std::string & str = *it;
		int32_t c = str[0];
		int32_t e = str[str.size()-1];
		bool bcons = true;
		for(i=1; i<str.size() && bcons; i++)
			if(str[i] != c)
				bcons = false;
		if(bcons)
		{
			cons[c]++;
		}
		else
		{
			if(arrows[c].str.size() > 0 || c==e)
				return false;
			if(props[c].bBeg || props[e].bEnd)
				return false;
			props[c].bBeg = true;
			props[e].bEnd = true;				
			arrows[c].str = str;
			arrows[c].dest = e;
		}
	}
	return true;
}

bool solve()
{
	std::string S = "";
	uint32_t icl = 0;
	int32_t c;
	if(!classify())
	{
		return false;
	}
	std::cout << "point 1" << std::endl;
	for(;;)
	{
		for(c = 0; c < 256; c++)
		{
			if(!props[c].bUsed && !props[c].bEnd && props[c].bBeg)
			{
				break;
			}
		}
		if(c >= 256)
		{
			break;
		}
		icl++;
		std::cout << ">>> " << c << std::endl;
		for(;;)
		{
			if(props[c].bUsed)
			{
				return false;
			}
			props[c].bUsed = true;
			if(!props[c].bBeg)
			{
				std::cout << "<<< " << std::endl;
				break;
			}
			S = S + arrows[c].str;	
			c = arrows[c].dest;
			std::cout << "--- " << c << std::endl;
		}
	}
	std::cout << "point 2" << std::endl;
	for(c = 0; c < 256; c++)
	{
		if(!props[c].bUsed && (props[c].bEnd || props[c].bBeg))
		{
			return false;
		}
	}
	for(c = 0; c < 256; c++)
	{
		if(cons[c] > 0)
		{
			mulf(cons[c]);
			if(!props[c].bUsed)
			{
				icl++;
				S = S + (char)c;
			}
		}
	}
	mulf(icl);
	
	bool bf[256];
	int32_t cur = 0;
	memset(bf, 0, sizeof(bf));
	for(i=0; i<S.size(); i++)
	{
		if((int32_t)S[i] != cur)
		{
			cur = (int32_t)S[i];
			if(bf[cur])
			{
				return false;
			}
			bf[cur] = true;
		}
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
		reset();
		finp >> i;
		for(; i > 0; i--)
		{
			std::string str;
			finp >> str;
			strs.push_back(str);
		}
		if(!solve())
			count = 0;
		fout << "Case #" << T << ": " << count << std::endl;
	}
	
	finp.close();
	fout.close();
	std::cout << "done" << std::endl;
	return 0;
}
