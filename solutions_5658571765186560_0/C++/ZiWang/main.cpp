#define _CRT_SECURE_NO_DEPRECATE
#include <cstring>
#include <fstream>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>

using namespace std;

#define pushback push_back
#define all_iters(v) v.begin(),v.end()
#define all_reverse_iters(v) v.rbegin(),v.rend()
#define sz size()
#define for_each_iter(it,c) for(auto it=c.begin();it!=c.end();++it)
#define for_each(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define for_each_reverse(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define for_each_default(i, j) for_each(i, 0, j, 1)
#define for_each_reverse_default(i, j) for_each_reverse(i, j, 0, 1)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define dot(a,b) ((conj(a)*(b)).X)
#define Y imag()
#define length(V) (hypot((V).X,(V).Y))
#define vect(a,b) ((b)-(a))
#define cross(a,b) ((conj(a)*(b)).imag())
#define normalize(v) ((v)/length(v))
#define rotate(p,about,theta) ((p-about)*exp(point(0,theta))+about)
#define pointEqual(a,b) (comp(a.X,b.X)==0 && comp(a.Y,b.Y)==0)
#define read(type) readInt<type>()

typedef stringstream ss;
typedef pair<int, int> PairInts;
typedef vector<PairInts> VecPairInts;
typedef vector<string> VecStr;
typedef vector<int> VecInt;
typedef vector<double> VecDouble;
typedef vector<vector<int>> VecVecInts;
typedef long long ll;
typedef long double ld;
typedef complex<double> Point;
typedef pair<Point, Point> Segment;
typedef pair<double, Point> Circle;
typedef vector<Point> Polygon;
typedef map<int, int> MapInts;
typedef set<int> SetInt;

const int oo = (int) 1e9;
const double PI = 2 * acos(0);
const double eps = 1e-9;

/****** Template of some basic operations *****/
template<typename T, typename U> inline void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if (x < y) x = y; }

inline int comp(const double &a, const double &b) {
	if (fabs(a - b) < eps)
		return 0;
	return a > b ? 1 : -1;
}
/**********************************************/


int di[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dj[] = { 0, 0, 1, -1, 1, -1, -1, 1 };
int diK[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
int djK[] = { -1, 1, 2, 2, 1, -1, -2, -2 };

int I, J;

inline bool val(const int &i, const int &j) {
	if (i < 0 || j < 0 || i >= I || j >= J)
		return false;
	return true;
}

/****** Template of Fast I/O Methods *********/
template <typename T> inline void write(T x)
{
	int i = 20;
	char buf[21];
	// buf[10] = 0;
	buf[20] = '\n';

	do
	{
		buf[--i] = x % 10 + '0';
		x /= 10;
	} while (x);
	do
	{
		putchar(buf[i]);
	} while (buf[i++] != '\n');
}

template <typename T> inline T readInt()
{
	T n = 0, s = 1;
	char p = getchar();
	if (p == '-')
		s = -1;
	while ((p<'0' || p>'9') && p != EOF&&p != '-')
		p = getchar();
	if (p == '-')
		s = -1, p = getchar();
	while (p >= '0'&&p <= '9') {
		n = (n << 3) + (n << 1) + (p - '0');
		p = getchar();
	}

	return n*s;
}
/************************************/

/******** User-defined Function *******/

void f()
{

}

/**************************************/

/********** Main()  function *******/
int main(int argc, char *args[]) {
#ifndef _FILE_OP_
	//freopen("input.in", "r", stdin);
	std::ifstream infile("input.in");
	freopen("output.out", "w", stdout);
#endif
	int t;

	string line;
	std::getline(infile, line);
	t = std::stoi(line);

	for_each_default(k, t){
		// write here your code

		int X, R, C;
		infile >> X >> R >> C;

		bool res = true;

		if (X >= 7)
			res = false;
		else if (X > R && X > C)
			res = false;
		else if (R * C % X != 0)
			res = false;
		else if ((X + 1) / 2 > min(R, C))
			res = false;
		else if (X == 1 || X == 2 || X == 3)
			res = true;
		else if (X == 4)
			res = min(R, C) > 2;
		else if (X == 5)
			res = !(min(R, C) == 3 && max(R, C) == 5);
		else if (X == 6)
			res = min(R, C) > 3;


		printf("Case #%d: %s\n", k + 1, res ? "GABRIEL" : "RICHARD");
	}

	return 0;
}