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
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

#define FOR(i, n)		for(int i = 0; i < (int)(n); i++)
#define ALL(x)			(x).begin(),(x).end()
#define FOR_EACH(it, a)	for(typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define SZ(a)			(int)((a).size())
#define PB push_back
 
typedef pair<int,int> ii;

const double EPS = 1e-6;

int n;
int d[500+2];
double JJJ[1000];
double X;

bool canBeEliminated(int i, double Y)
{
	double f = JJJ[i] + Y;
	double rest = X - Y;
	FOR(j,n)
		if( j != i )
		{
			if( JJJ[j] <= f )
			{
				rest -= (f - JJJ[j]) + EPS;
			}
		}
	
	return rest >= 0;
}

void solve(int nTest)
{
	cin >> n;
	X = 0;
	for(int i = 0; i < n; i++)
	{
		//int tmp;
		cin >> JJJ[i];
		//cout << JJJ[i] << " ";
		X += JJJ[i];
	}
	//cout << endl;
	
	printf("Case #%d: ", nTest);
	
	FOR(i,n)
	{
		
		double minY = 0;
		double maxY = X;
		while( maxY - minY > EPS )
		{
			
			double middleY = (maxY + minY) / 2;
			
			if( !canBeEliminated(i, middleY) )
			{
				maxY = middleY;
			} else
			{
				minY = middleY;
			}
			
		}
		
		
		printf("%.7lf ", (maxY/X)*100);
	}
	cout << endl;
	
}

int main()
{	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	FOR(i,T)
	{
		solve(i+1);
	}
	return 0;
}
