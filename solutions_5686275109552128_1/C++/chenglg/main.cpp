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
template<class T>

T prime(T a , T b)
{
	cout << a << "\t"<<b << endl;
	if ( a >= b)
		return (prime(b , a));
	if(a == 0)
		return b;
	return prime(a , b%a);
}

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


int solve( map<int , int> &dict) {
	if(dict.size() < 1)
		return 0;
	map<int, int> ::reverse_iterator rit = dict.rbegin();
	if (rit->second >= rit-> first)
		return rit -> first;
	int k =  rit -> first;
	int n = rit -> second;
	dict.erase(k);
	int ret = k;

	if (k == 9 && n == 1)
	{
		map<int , int> dict2 = dict;
		dict2[3] += 3;
		ret = min(ret,  min(k, 2 * n + solve(dict2)));
	}
	map<int , int> dict2 = dict;
	if (k % 2) {
		dict[k/2] += n; 
		dict[k/2 + 1] += n;
		ret = min(ret,  min(k, n + solve(dict)));
	}
	else {
		dict[k/2] += 2*n;
		ret = min(ret,  min(k, n + solve(dict)));
	}


	return ret;
}

int main()
{
//==============in put=================
	ifstream curFile("B-large.in");
	vector<int> result;
	int m;
	map<int, int> dict;
	int T; // testcases count
	if(curFile.is_open())
	{
		curFile >> T;
		for(int c = 0 ; c < T ; c++)
		{
//==============solution==================
			dict.clear();

			cout << "Enter Test case:" << c + 1 << endl;
			curFile >> m;
			for (int i = 0 ; i < m ; i ++) {
				int t;
				curFile >> t;
				dict[t] += 1;
			}
			result.push_back(solve(dict));
//==============solution end==============
		}	
	}
	curFile.close();
//==============out put==================
	ofstream outfile;
	outfile.open("result.txt");
	if(outfile.is_open())
	{
//		outFile << setprecision(6);
		for(int i = 0; i < result.size() ; i++) {
			outfile << "Case #" << i + 1<< ": " <<result[i] << endl;
			cout << "Case #" << i + 1<< ": " <<result[i] << endl;
		}
	}
	outfile.close();
	return 0;
}
