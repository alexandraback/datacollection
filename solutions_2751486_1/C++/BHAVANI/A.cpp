#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
#define all(c) c.begin(), c.end() 
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define sz size()
//#define tr(container, it) \
#define gcd __gcd
#define oo  (int)13e7
bool isVowel(char c)
{
	char Vowel[] = {'a','e','i','o','u'};
	REP(i,5)
	{
		if ( c == Vowel[i] )
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int T;
	cin >> T;
	for ( int tt = 0 ; tt < T; tt++ )
	{
		string str;
		int nVal;
		cin >> str >>nVal;
		vector <int> cache;
		int nChars[1000010];
		REP(i,str.sz)
		{
			if ( isVowel(str[i] ) )
			{
				nChars[i] = 0;
			}
			else
			{
				nChars[i] = 1;
				if ( i != 0 )
				{
					nChars[i] = nChars[i-1]+1;
				}
				if ( nChars[i] >= nVal)
				{
					cache.pb(i);
				}
			}
		}
		long long int ret = 0;
		REP(start,str.sz-nVal+1)
		{
			std::vector<int>::iterator low;
			low=std::lower_bound (all(cache),start+nVal-1);
			
			if ( low != cache.end())
			{
				long long int nEnds = str.sz-(*low);
				//cout <<start<<" "<< nEnds<<endl;
				ret += nEnds;
			}
		}
		
		cout << "Case #"<<(tt+1)<<": "<<ret<<endl;
	}
}
