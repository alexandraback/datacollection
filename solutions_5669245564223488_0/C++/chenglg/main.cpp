#ifdef __GNUC__
#include <ext/hash_map>
#include <ext/hash_set>
#else
#include <hash_map>
#include <hash_set>
#endif

namespace std
{
 using namespace __gnu_cxx;
}

#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <algorithm>
#include <math.h>
#include <cstdlib>
#include <climits>
#include <iomanip> 
using namespace std;

typedef long long LL;
typedef long double LD;

string its(int n)
{
	string ret;
	if(n == 0)
	{
		ret = "0";
		return ret;
	}
	while(n > 0)
	{
		ret += (n % 10 + '0');
		n /= 10;
	}
	reverse(ret.begin() , ret.end());
	return ret;
}

string shrink(string src)
{
	string ret;
	char a = src[0];
	for(int i = 1 ; i< src.size() ; i++)
	{
		if(a == src[i])
			continue;
		else
		{
			ret += a;
			a = src[i];
		}
	}
	ret += a;
	return ret;
}

bool checkValid(string& src)
{
	hash_set<char> dict;
	for(int i = 0 ; i < src.size() ; i++)
	{
		if(dict.count(src[i]))
			return false;
		dict.insert(src[i]);
	}
	return true;
}

void permute(vector<string>& pool , int &r , int pos)
{
	if(pos == pool.size())
	{
		string pat;
		for( int i = 0 ; i< pool.size() ; i++)
		{
			pat += pool[i];
		}
		pat = shrink(pat);
		if(checkValid(pat))
			r++;
		return;
	}
	for(int i = pos ; i < pool.size() ; i ++)
	{
		swap(pool[i],pool[pos]);
		permute(pool , r , pos + 1);
		swap(pool[i] ,pool[pos]);
	}
}

int main()
{
//==============in put=================
	ifstream curFile("B-small-attempt0.in");
	vector<int> result;
	int T; // testcases count
	int N;
	if(curFile.is_open())
	{
		curFile >> T;
		for(int c = 0 ; c < T ; c++)
		{
//==============solution==================
			curFile >> N;
			vector<string> pool;
			for(int i = 0 ; i< N ; i++)
			{
				string cur;
				curFile >> cur;
				cur = shrink(cur);
				pool.push_back(cur);
			}
			int r = 0;
			permute(pool , r , 0);
//==============solution end==============
			result.push_back(r);
		}	
	}
	curFile.close();
//==============out put==================
	ofstream outfile;
	outfile.open("result.txt");
	if(outfile.is_open())
	{
//		outFile << setprecision(6);
		for(int i = 0; i < result.size() ; i++)
			outfile << "Case #" << i + 1<< ": " <<result[i] << endl;
	}
	outfile.close();
	return 0;
}
