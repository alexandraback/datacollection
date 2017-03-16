// GCJ2013R2C.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

#pragma warning(disable:4996)

using namespace std;

int T;
string s;
int n;
bool is[26];
int clen[1000002];
int near[1000002];

void init()
{
	cin >> T;
	memset(is, 0, sizeof(is));

	for (int i=0; i<26; i++)
	{
		if ('a' + i == 'a' || 'a' + i == 'e' || 'a' + i == 'i' || 'a' + i == 'o' || 'a' + i == 'u')
		{
			is[i] = true;
		}
		else
		{
			is[i] = false;
		}
	}
}


void work()
{
	for (int ca=1; ca<=T; ca++)
	{
		cin >> s >> n;

		cout << "Case #" << ca << ": ";
		int L = s.length();
		memset(clen, 0, sizeof(clen));
		clen[L] = 0;
		near[L] = -1;
		for (int j=L-1; j>=0; j--)
		{
			if (is[s[j]-'a'])
			{
				clen[j] = 0;
			}
			else
			{
				clen[j] = clen[j+1] + 1;
			}
			if (clen[j]>=n)
			{
				near[j] = j;
			}
			else
			{
				near[j] = near[j+1];
			}
		}		
		long long count=0;
		for (int i=0;i<L;i++)
		{
			if (near[i]<0)
				break;
			count+=L-n-near[i]+1;
			//cout << near[i] << " " << L-n-near[i]+1 << endl;
		}
		
		cout << count << endl;
		
	}
}


int main()
{
	freopen("C:\\Users\\yuazh\\Downloads\\A-large.in", "r", stdin);
	freopen("C:\\Users\\yuazh\\Downloads\\A-large.out", "w", stdout);
	init();
	work();

	return 0;
}



