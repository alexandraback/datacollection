#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <bitset>
#include <utility>
#include <functional>
#include <string>
#include <algorithm>

#include <cstring>
#include <cstdio>
#include <memory.h>
#include <ctime>
#include <cassert>
#include <cmath>

using namespace std;

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define ford(i,n) for(int i = int(n) - 1; i >= 0; i--)
#define fore(i,a,b) for(int i = int(a); i <= int(b); i++)
#define foreach(it,a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)

#define sz(a) int((a).size())
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define ft first
#define sc second

template<typename X> inline X abs(const X& a) { return (a < 0 ? -a : a); }
template<typename X> inline X sqr(const X& a) { return (a * a); }

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pr;
typedef pair<ld, ld> ptd;

#define PI 3.14159265
#define EPS 1E-4

void solveB()
{
	int T;
	cin >> T;
	forn(t, T)
	{
		double c, f, x;
		cin >> c; cin >> f; cin >> x;
		double curD = 2.0;
		double curT = 0.0;
		double curC = 0;
		while (true)
		{
			double wait, bwait;
			wait = (x - curC) / curD;
			if (curC > c)
				bwait = (x - curC + c) / (curD + f);
			else
				bwait = (c - curC) / curD + x / (curD + f);
			if (wait < bwait)
			{
				curT += wait;
				break;
			}
			else {
				if (curC > c)
				{
					curC -= c;
					curD += f;
				}
				else {
					curT += (c - curC) / curD;
					curC = 0;
					curD += f;
				}
			}
			
		}
		std::cout.setf(std::ios::fixed, std::ios::floatfield);
		cout << "Case #" << t + 1 << ": " << setprecision(8) << curT << endl;
	}
}

int main() {
#ifdef diametralis
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	solveB();
	cout << "done";
#ifdef diametralis
	//cerr << "Time == " << clock() << endl;
#endif
}