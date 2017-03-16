#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <complex>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <ctime>

#include<unordered_map>
#include<unordered_set>
using namespace std;



string allS[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};


bool bb(map<char,int> allSCnt[10],map<char, int> cnt,vector<int>& out )
{
	vector<int> out22;
	//for (int i = 0 ; i < 10; ++i)
	for (int i = 10 ; i--;)
	{
		while (1)
		{
			char noGood = 0;
			for (auto iter = allSCnt[i].begin(); iter != allSCnt[i].end(); ++iter)
			{
				if ( cnt[ iter->first] < iter->second)
				{
					noGood = 1; break;
				}
			}
			if (noGood)
				break;
		//	printf("%d" , i);
			out22.push_back(i);

			for (auto iter = allSCnt[i].begin(); iter != allSCnt[i].end(); ++iter)
			{
				cnt[ iter->first] -= iter->second;
			}
		}

	}


	bool ok = 1;
	for ( auto iter = cnt.begin(); iter != cnt.end(); ++iter)
	{
		if (iter->second != 0 )
		{
			printf("%c %d\n" , iter->first, iter->second);
			ok = 0;
		}
	}


	if ( ok)
	{
		for (int i = 0 ; i < out22.size(); ++i)
		{
			out.push_back( out22[i]);
		}
	}

	return ok;
}


bool aa(map<char,int> allSCnt[10],map<char, int> cnt,vector<int>& out )
{
	vector<int> out22;
	for (int i = 0 ; i < 10; ++i)
	//for (int i = 10 ; i--;)
	{
		while (1)
		{
			char noGood = 0;
			for (auto iter = allSCnt[i].begin(); iter != allSCnt[i].end(); ++iter)
			{
				if ( cnt[ iter->first] < iter->second)
				{
					noGood = 1; break;
				}
			}
			if (noGood)
				break;
			out22.push_back(i);
			//printf("%d" , i);

			for (auto iter = allSCnt[i].begin(); iter != allSCnt[i].end(); ++iter)
			{
				cnt[ iter->first] -= iter->second;
			}
		}

	}


	bool ok = 1;
	for ( auto iter = cnt.begin(); iter != cnt.end(); ++iter)
	{
		if (iter->second != 0 )
		{
			printf("%c %d\n" , iter->first, iter->second);
			ok = 0;
		}
	}

	if ( ok)
	{
		for (int i = 0 ; i < out22.size(); ++i)
		{
			out.push_back( out22[i]);
		}
	}

	return ok;
}

int main(int __an, char **__ag)
{	

	map<char,int> allSCnt[10];
	vector<char> mustHave[10];
	for (int i = 0 ; i < 10; ++i)
	{
		for (int j = 0 ; j < allS[i].size(); ++j)
		{
			++allSCnt[i][ allS[i][j] ];

			bool aa = 1;
			for (int k = 0 ; k < 10; ++k)
			{
				if (k == i ) continue;
				
				for (int l = 0 ; l < allS[k].size(); ++l)
				{
					if ( allS[i][j] == allS[k][l])
					{
						aa = 0; break;
					}
				}
			}
			if (aa)
				mustHave[i].push_back( allS[i][j]);
		}


		
	}

	int Case, cases = 0;
	scanf("%d" , &Case);
	while (Case--)	
	{
		string in;
		cin >> in;
		map<char, int> cnt;
		for (int i = 0 ; i < in.size(); ++i)
		{
			cnt[in[i]]++;
		}
		
		printf("Case #%d: " , ++cases);

		vector<int> out;
		for (int i = 0 ; i < 10; ++i)
		{
			while(1)
			{
				bool ok = mustHave[i].size() > 0;
				for (int j = 0; j < mustHave[i].size(); ++j)
				{
					if ( cnt[mustHave[i][j]] < allSCnt[i][  mustHave[i][j] ] )
					{
						ok = 0; break;
					}
				}
				if (ok)
				{
					out.push_back(i);
					for (auto iter = allSCnt[i].begin(); iter != allSCnt[i].end(); ++iter)
					{
						cnt[ iter->first] -= iter->second;
					}
				}
				else
					break;
			}
		}


		if (!aa(allSCnt,cnt,out))
		{
			bb(allSCnt,cnt,out);
		}
		
		sort(out.begin(), out.end());
		for (int i = 0 ; i < out.size(); ++i)
			cout << out[i] ;
		puts("");

	}

	return 0;
}

