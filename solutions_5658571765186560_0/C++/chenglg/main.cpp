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


int main()
{
//==============in put=================
	ifstream curFile("D-small-attempt0.in");
	vector<string> result;
	int T; // testcases count
	string a = "RICHARD";
	string b = "GABRIEL";
	int X;
	int R;
	int C;
	if(curFile.is_open())
	{
		curFile >> T;
		for(int c = 0 ; c < T ; c++)
		{
//==============solution==================
			cout << "Enter Test case:" << c + 1 << endl;
			curFile >> X;
			curFile >> R;
			curFile >> C;
			if (R < C) {
				R = R^C;
				C = R^C;
				R = R^C;
			}
			if (R < X) {
				result.push_back(a);
				continue;
			}
			if (X >= 7) {
				result.push_back(a);
				continue;
			}
			if (R*C % X != 0) {
				result.push_back(a);
				continue;
			}
			if (X == 3) {
				if (C < 2) {
					result.push_back(a);
					continue;
				}
				else {
					result.push_back(b);
					continue;

				}
			}
			else if (X == 4) {
				if (C < 3) {
					result.push_back(a);
					continue;
				}
				else {
					result.push_back(b);
					continue;

				}

			}
			result.push_back(b);

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
