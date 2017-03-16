#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>

#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <bitset>
#include <complex>

#include <vector>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <deque>

#include <cstdio>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>

using namespace std;

//===========================================================================================
//#define LOG_DEBUG
//===========================================================================================

#define ALL(a) ((a).begin(),(a).end())
#define SORT(a) (sort(ALL(a)))
#define REVERSE(a) (reverse(ALL(a)))

//													Rockoder: memset
#define FILL(a, d) (memset(&a, d, sizeof(a)))

//													Rockoder: int64
typedef long long int64;

//													Rockoder: uint64
typedef unsigned long long uint64;

//													Rockoder: GCD
template<class T>
inline T gcd(T n1, T n2)
{
	if(n1 < 0)
		return gcd(-n1, n2);

	if(n2 < 0)
		return gcd(n1, -n2);

	return (n2 == 0) ? n1 : gcd(n2, n1 % n2);
}

//													Rockoder: LCM
template<class T> 
inline T lcm(T n1, T n2)
{
	if(n1 < 0)
		return lcm(-n1, n2);

	if(n2 < 0)
		return lcm(n1, -n2);

	return n1 * (n2 / gcd(n1, n2));
}

//													Rockoder: PRIME NO
template<class T> inline 
bool isPrime(T n)
{
	if(n <= 1)
		return false;

	for (T i = 2; i * i <= n; ++i) 
		if (n % i == 0) 
			return false;

	return true;
}

//													Rockoder: STRING 2 VECTOR
template<class T>
void stov(string s, vector<T> &v)
{
	v.clear();
	istringstream istrm(s);

	for(T i; istrm >> i; v.push_back(i))
		;
}

//													Rockoder: VECTOR 2 STRING
template<class T> 
void vtos(vector<T> v, string &s)
{
	ostringstream ostrm;

	for (int i = 0; i < v.size(); ++i)
	{
		if(i > 0)
			ostrm << ' ';

		ostrm << v[i];
	}

	s = ostrm.str();
}

//													Rockoder: IS UPPER
bool isUpper(char ch)
{
	return ch >= 'A' && ch <= 'Z';
}

//													Rockoder: IS LOWER
bool isLower(char ch)
{
	return ch >= 'a' && ch <= 'z';
}

//													Rockoder: IS ALPHABET
bool isAlpha(char ch)
{
	return isUpper(ch) || isLower(ch);
}

//													Rockoder: IS NUMBER
bool isNum(char ch)
{
	return ch >= '0' && ch <= '9';
}

//													Rockoder: IS ALPHANUMERIC
bool isAlphaNum(char ch)
{
	return isAlpha(ch) || isNum(ch);
}

//													Rockoder: CONVERT TO LOWER CASE
char toLower(char ch)
{
	return (isUpper(ch)) ? (ch + 32) : ch;
}

//													Rockoder: CONVERT TO UPPER CASE
char toUpper(char ch)
{
	return (isLower(ch)) ? (ch - 32) : ch;
}

//													Rockoder: MAX MATIX SIZE
const int MAX_MAT_SIZE = 50;

//													Rockoder: DISPLAY MATIX
template<class T>
inline void displayMat(int r, int c, T A[MAX_MAT_SIZE][MAX_MAT_SIZE])
{
#ifdef LOG_DEBUG
	cout << "		Rockoder: displayMat: row: " << r << "  col: " << c << endl;
#endif

	for (int i = 0; i < r; ++i)
	{
		cout << "		";

		for (int j = 0; j < c; ++j)
			cout << A[i][j] << " ";

		cout << endl;
	}
}

//													Rockoder: GET IDENTITY MATIX
template<class T> 
inline void identityMat(int n, T A[MAX_MAT_SIZE][MAX_MAT_SIZE])
{
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < n; ++j) 
			A[i][j] = (i == j) ? 1 : 0;
}

template<class T> inline void addMat(int r, int c, 
									 T A[MAX_MAT_SIZE][MAX_MAT_SIZE], 
									 T B[MAX_MAT_SIZE][MAX_MAT_SIZE], 
									 T C[MAX_MAT_SIZE][MAX_MAT_SIZE])
{
	for (int i = 0; i < r; ++i) 
		for (int j = 0; j < c; ++j) 
			C[i][j] = A[i][j] + B[i][j];
}

template<class T> inline void subMat(int r, int c,
									 T A[MAX_MAT_SIZE][MAX_MAT_SIZE],
									 T B[MAX_MAT_SIZE][MAX_MAT_SIZE],
									 T C[MAX_MAT_SIZE][MAX_MAT_SIZE])
{
	for (int i = 0; i < r ; ++i) 
		for (int j = 0; j < c; ++j) 
			C[i][j] = A[i][j] - B[i][j];
}

template<class T> inline void mulMat(int r1, int c1, int r2, int c2, 
									 T A[MAX_MAT_SIZE][MAX_MAT_SIZE],
									 T B[MAX_MAT_SIZE][MAX_MAT_SIZE],
									 T C[MAX_MAT_SIZE][MAX_MAT_SIZE])
{
	if (c1 != r2)
	{
#ifdef LOG_DEBUG
		cout << "		Rockoder: mulMat: row1: " << r1 << "  col1: " << c1 << endl;
		cout << "		Rockoder: mulMat: row2: " << r2 << "  col:2 " << c2 << endl;
#endif
		return;
	}

	for (int i = 0; i < r1; ++i) 
		for (int j = 0; j < c2; ++j) 
		{
			C[i][j] = 0;
			for (int k = 0; k < c1; ++k) 
				C[i][j] += A[i][k] * B[k][j];
		}
}

//===========================================================================================
//===========================================================================================

template<typename T, typename S> 
T myCast(S src)
{
	stringstream strm;
	strm << src;

	T trg;
	strm >> trg;

#ifdef LOG_DEBUG
	cout << "		Rockoder: myCast: src: " << src << "  trg: " << trg << endl;
#endif

	return trg;
}

int readInt()
{
	string str;
	getline(cin, str);
	istringstream strm(str);

	int no;
	strm >> no;

#ifdef LOG_DEBUG
	cout << "		Rockoder: readInt   :		" << no << endl;
#endif

	return no;
}

string readString_whitespace()
{
	string str;
	getline(cin, str);

#ifdef LOG_DEBUG
	cout << "		Rockoder: readString_whitespace:		" << str << endl;
#endif

	return str;
}

string readString_noWhitespace()
{
	string str;

	cin >> str;

#ifdef LOG_DEBUG
	cout << "		Rockoder: readString_noWhitespace:		" << str << endl;
#endif

	return str;
}

int a[1002][1002];

int mycount;

int d1(int c, int p, int n)
{
	for (int i = 1; i <= n; ++i)
	{
		if (c == i)
			continue;

		if (a[c][i] == 1)
		{
			if (i == p)
				++mycount;
			else
				d1(i,p,n);
		}
	}

	return 0;
}

bool diamond(int n)
{
	int i = 1;

	while (i <= n)
	{
		while (i <= n && a[i][n+1] <= 1) ++i;	// more parents

		if (i == n + 1)
			continue;

		int j = 1;
		while (j <= n)
		{
			while (j <= n && a[n+1][j] <= 1) ++j;	// more child

			if (j == n + 1)
				continue;

			d1(i,j, n);

			if (mycount > 1)
				return true;

			mycount = 0;
			++j;
		}
		++i;
	}
	return false;
}

void clear_a()
{
	for (int i = 1; i <= 1001; ++i)
		for (int j = 1; j <= 1001; ++j)
			a[i][j] = 0;
}

int main()
{
	int t;
	cin >> t;	

	int n;
	for (int i = 0; i < t; ++i)
	{
		mycount = 0;

		clear_a();

		cin >> n;
		bool req = false;

		for (int j = 1; j <= n; ++j)
		{
			int c;
			cin >> c;

			for (int k = 0; k < c; ++k)
			{
				int temp;
				cin >> temp;

				a[j][temp] = 1;
			}

			a[j][n + 1] = c;

			if (c > 1)
				req = true;
		}

		for (int j = 1; j <= n; ++j)
		{
			int total = 0;

			for (int k = 1; k <= n; ++k)
			{
				total += a[k][j];
			}

			a[n + 1][j] = total;

			if (total > 1)
				req = true;
		}

		if (!req)
			cout << "Case #" << i + 1 << ": No" << endl;
		else if (diamond(n))
			cout << "Case #" << i + 1 << ": Yes" << endl;
		else 
			cout << "Case #" << i + 1 << ": No" << endl;
	}

	return 0;
}
