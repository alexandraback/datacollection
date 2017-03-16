#include <vector>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <map>
#include <ctime>
#include <cassert>

using namespace std;

ofstream fout("../../output.txt");
ifstream fin("../../input.txt");



bool isvowel(char c)
{
	if(c=='a')
		return false;
	if(c=='e')
		return false;
	if(c=='i')
		return false;
	if(c=='o')
		return false;
	if(c=='u')
		return false;
	return true;
}


vector<long long> seclens;
vector<bool> sectypes;

long long choose2(long long x)
{
	return x*(x-1)/2;
}


long long substrings(long long len, long long submax)
{
	long long ret = choose2(submax);
	ret+=(len-submax)*(submax-1);
	return ret;
}

int main(void)
{
	int ttt;
	fin >> ttt;
	int ct = 0;
	string s;
	
	cout.precision(9);
	fout.precision(9);
	
	while(ttt>0)
	{
		ct++;
		ttt--;
		int i,j,k;
		
		
		string s;
		
		fin >> s;
		
		long long len;
		
		fin >> len;
		
		
		int currtot, currc;
		currtot = currc = 0;
		
		int n = s.size();
		
		seclens.clear();
		sectypes.clear();
		
		for(i=0; i<n; i++)
		{
			bool iscon = isvowel(s[i]);
			
			if(!iscon && currc==currtot && currc>=len)
			{
				seclens.push_back(currc);
				sectypes.push_back(true);
				currc=0;
				currtot=1;
			}
			else if(!iscon)
			{
				currtot++;
				currc=0;
			}
			else 
			{
				currc++;
				currtot++;
				if(currc < currtot && currc==len)
				{
					seclens.push_back(currtot-currc);
					sectypes.push_back(false);
					currtot=currc;
				}
			}
		}
		
		if(currtot  >0)
		{
			if(currtot == currc && currc>=len)
			{
				seclens.push_back(currtot);
				sectypes.push_back(true);
			}
			else {
				seclens.push_back(currtot);
				sectypes.push_back(false);

			}
		}
		
		
		long long ret = 0;
		
		
		for(i=0; i<seclens.size(); i++)
		{
			//cout << seclens[i] << " " << sectypes[i] << endl;
			
			if(sectypes[i])
			{
				ret+=substrings(seclens[i], len-1);
			}
			else {
				long long prev = 0;
				long long next = 0;
				
				if(i-1>=0)
					prev=seclens[i-1];
				if(i+1 < seclens.size())
					next= seclens[i+1];
				
				if(prev > len-1)
					prev=len-1;
				if(next > len-1)
					next = len-1;
				
				ret+=prev*next + (prev+next)*seclens[i] + choose2(seclens[i]);
			}
		}
		
		ret = choose2((long long)s.size())-ret;
		
		
		
		cout << "Case #" << ct << ": " << ret;
		fout << "Case #" << ct << ": " << ret;
		
		
		
		
		
		
		
		
		
		fout << endl;
		cout << endl;
		
	}
	
	
	return 0;
}

