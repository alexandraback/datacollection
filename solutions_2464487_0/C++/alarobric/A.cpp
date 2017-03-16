//Google Codejam
//2013 Round 1A
//Alan Richards - alarobric

//Problem A
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <limits.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<n; i++)
#define FOREACH(c, iter) for(auto iter=c.begin(); iter!=c.end(); iter++)

#ifdef DEBUG
#define Debug(x) std::cerr << x
#else
#define Debug(x)
#endif

typedef unsigned long long ull;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

ull Solve(int i_case)
{
	ull R, T;
	std::cin >> R >> T;
	//area of disk with radius 1cm is pi cm^2
	//area of disk spanning r1-r2 = pi*r2*r2-pi*r1*r1=pi(r2*r2-r1*r1)
	//r2=r1+1 always    so area = pi(2*r1+1)
	//1ml paint covers pi cm^2
	ull rInner = R;
	ull remainingPaint = T;
    ull nextArea = (2*rInner+1); //ml of paint
	while (nextArea <= remainingPaint)
	{
	    remainingPaint -= nextArea;
	    rInner += 2;
	    nextArea = (2*rInner+1);
	}
		
	return (rInner-R)/2;
}

int main()
{
	std::cerr << "GCJ 2013 Round 1A-A" << std::endl;
	int numCases;
	std::cin >> numCases;
	for (int i=1; i<=numCases; i++)
	{
		std::cout << "Case #" << i << ": " << Solve(i) << std::endl;
	}
	return 0;
}
