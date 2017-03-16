#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <sstream>

using namespace std;

unsigned long long fromStr(string a)
{
	stringstream ss(a);
	unsigned long long ans;
	ss>>ans;
	return ans;
}

string min(string a, string b)
{
	unsigned long long aN = fromStr(a),
					   bN = fromStr(b);
	if (aN < bN) return a;
	else if (bN < aN) return b;
	else return a;
}

string minA = "";
string minB = "";
unsigned long long minDiff = 654321065L;
unsigned long long temp;
int len;
string valA, valB;
int tempCalc;
char tempStore;

void dfs(int currInd, int indicator)
{
	//cout<<"DFS: "<<valA<<" "<<valB<<" "<<currInd<<" "<<indicator<<endl;
	//end of dfs branch
	if (currInd == len)
	{
		if (indicator == -1)
		{
			temp = fromStr(valB)-fromStr(valA);
		}
		else
		{
			temp = fromStr(valA)-fromStr(valB);
		}
		//cout<<valA<<" "<<valB<<" "<<temp<<endl;

		if (temp < minDiff || minDiff==654321065L)
		{
			minDiff = temp;
			minA = string(valA);
			minB = string(valB);
		}
		else if (temp==minDiff)
		{
			if (min(minA, valA) == minA && min(minA, valA)==valA)
			{
				minB = min(minB, valB);
			}
			else if (min(minA, valA)==valA)
			{
				minA = valA;
				minB = valB;
			}
		}

		return ;
	}
	//if both are known - can't really change anything
	if (valA[currInd]!='?' && valB[currInd]!='?')
	{
		if (indicator == 0)
		{
			if (valA[currInd]==valB[currInd])
				dfs(currInd+1, 0);
			else if (valA[currInd]>valB[currInd])
				dfs(currInd+1, 1);
			else
				dfs(currInd+1, -1);
		}
		else
			dfs(currInd+1, indicator);
		return ;
	}

	//if both are equal so far
	if (indicator==0)
	{
		if (valA[currInd]=='?' && valB[currInd]=='?')
		{
			valA[currInd] = '0';
			valB[currInd] = '0';
			dfs(currInd+1, 0);

			valA[currInd] = '0';
			valB[currInd] = '1';
			dfs(currInd+1, -1);

			valA[currInd] = '1';
			valB[currInd] = '0';
			dfs(currInd+1, 1);

			valA[currInd] = '?';
			valB[currInd] = '?';
		}
		else if (valA[currInd]=='?')
		{
			//other-1 same
			if (valB[currInd]>'0')
			{
				valA[currInd] = valB[currInd]-1;
				dfs(currInd+1, -1);
			}
			else
			{
				valA[currInd] = '9';
				dfs(currInd+1, 1);
			}

			//same same
			valA[currInd] = valB[currInd];
			dfs(currInd+1, 0);

			//other+1 same
			if (valB[currInd]<'9')
			{
				valA[currInd] = valB[currInd]+1;
				dfs(currInd+1, 1);
			}
			else
			{
				valA[currInd] = '0';
				dfs(currInd+1, -1);
			}

			valA[currInd] = '?';
		}
		else if (valB[currInd]=='?')
		{
			//same other-1
			if (valA[currInd]>'0')
			{
				valB[currInd] = valA[currInd]-1;
				dfs(currInd+1, 1);
			}
			else
			{
				valB[currInd] = '9';
				dfs(currInd+1, -1);
			}
			
			//same same
			valB[currInd] = valA[currInd];
			dfs(currInd+1, 0);

			//same other+1
			if (valA[currInd]<'9')
			{
				valB[currInd] = valA[currInd]+1;
				dfs(currInd+1, -1);
			}
			else
			{
				valB[currInd] = '0';
				dfs(currInd+1, 1);
			}
		}
	}
	//if a is bigger
	else if (indicator == 1)
	{
		//both unknown
		if (valA[currInd]=='?' && valB[currInd]=='?')
		{
			valA[currInd] = '0';
			valB[currInd] = '9';
			dfs(currInd+1, indicator);

			valA[currInd] = '?';
			valB[currInd] = '?';
		}

		//a known
		else if (valB[currInd]=='?')
		{
			valB[currInd] = '9';
			dfs(currInd+1, indicator);

			valB[currInd] = '?';
		}

		//b known
		else if (valA[currInd]=='?')
		{
			valA[currInd] = '0';
			dfs(currInd+1, indicator);

			valA[currInd] = '?';
		}

	}
	//if b is bigger
	else if (indicator == -1)
	{
		//both unknown
		if (valA[currInd] == '?' && valB[currInd] == '?')
		{
			valA[currInd] = '9';
			valB[currInd] = '0';
			dfs(currInd+1, indicator);

			valA[currInd] = '?';
			valB[currInd] = '?';
		}

		//a known
		else if (valB[currInd] == '?')
		{
			valB[currInd] = '0';
			dfs(currInd+1, indicator);

			valB[currInd] = '?';
		}

		//b known
		else if (valA[currInd] == '?')
		{
			valA[currInd] = '9';
			dfs(currInd+1, indicator);

			valA[currInd] = '?';
		}

	}
}

int main()
{
	ifstream fin("README.txt");
	ofstream fout("Close.out");

	int numTests;
	fin>>numTests;
	string temp1, temp2;
	for (int run = 1; run<=numTests; run++)
	{
		//input
		fin>>temp1>>temp2;
		len = temp1.length();
		cout<<run<<" "<<temp1<<" "<<temp2<<" "<<len<<endl;

		//calculate via dfs and reset vars before
		minDiff = 654321065L;
		valA = temp1;
		valB = temp2;
		dfs(0, 0);

		//output
		fout<<"Case #"<<run<<": "<<minA<<" "<<minB<<endl;
	}

	fin.close();
	fout.close();

	return 0;
}