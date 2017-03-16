#include <iostream>
#include <vector>
#include <sstream>
#include <set>
#include <stdexcept>
#include <fstream>
#include <map>
#include <limits>
#include <math.h>
#include <iomanip>
#include <iomanip>
#include <algorithm>

using namespace std;

template<typename T>
string ToString(T v)
{
	ostringstream ostr;

	ostr << v;

	return ostr.str();
}

typedef __int64 int64_t;

int abs(int n)
{
	if ( n < 0)
		return -n;
	return n;
}



string  Solve2(int x, int y)
{
	string res = "";
	int px = 0;
	int py = 0;

	int i = 1;
	for (; i <= 500; ++i)
	{
		if (x == px && y == py)
			return res;
		if (px < x)
		{
			px += i;
			res += 'E';			
		}
		else
		{
			if (py < y)
			{
				py += i;
				res += 'N';
			}
			else
				break;			
		}
	}

	while (px < x)
	{
		px -=i++;
		px += i++;
		res += "WE";
	}

	while (px > x)
	{
		px +=i++;
		px -= i++;
		res += "EW";
	}

	while (py < y)
	{
		py -=i++;
		py += i++;
		res += "SN";
	}
	
	while (py > y)
	{
		py +=i++;
		py -= i++;
		res += "NS";
	}
	return res;
}

void Swap(string& str, char c, char c2)
{
	for (int i =0; i < str.size(); ++i)
	{
		if (str[i] == c)
			str[i] = c2;
		else if (str[i] == c2)
			str[i] = c;
	}
}

string Solve(int x, int y)
{
	auto res = Solve2(abs(x), abs(y));
	
	if ( x < 0)
		Swap(res, 'E', 'W');
	if (y < 0)
		Swap(res, 'N', 'S'); 
	return res;
}

bool Check(const string& s, int x, int y )
{
	int px = 0;
	int py = 0;

	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == 'N')
			py += i + 1;
		else if (s[i] == 'S')
			py -= i + 1;
		else if (s[i] == 'E')
			px += i + 1;
		else if (s[i] == 'W')
			px -= i + 1;
	}

	if ( px != x || py != y)
		throw runtime_error("");
	if (s.size() > 500)
		throw runtime_error("");
	return true;

}

int main(int argc, char** argv)
{
/*	int t= 0;
	for (int i = 0; i <= 100; ++i)
	{
		cout << i << " " << t << endl;
		for (int j  = 0; j <= 100; ++j)
		{
			auto res = Solve(i, j);
			Check(res, i, j );
		}
	}
	return 0;*/

	const string inputFilename = "B-small-attempt0.in";
	const string outputFilename = inputFilename + ".out";
	ifstream ifs( inputFilename.c_str() );
	ofstream file( outputFilename.c_str());
	int nbTest = 0;

	ifs >> nbTest;
	string line;
	getline(ifs, line);

	for( int test = 1; test <= nbTest; ++test )
	{
		ostringstream ostr;
		int64_t x, y;
				
		ifs >> x >> y;		
		getline(ifs, line);
		ostr.precision(15);
		ostr << "Case #" << test << ": ";

		ostr << Solve(x, y);		
		ostr << endl;

		cout << ostr.str();
		file << ostr.str();
	}

	cout << "Finish" << endl;
	return 0;
}



