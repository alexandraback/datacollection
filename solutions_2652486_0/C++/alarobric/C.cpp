//Google Codejam
//2013 Round 1A
//Alan Richards - alarobric

//Problem C
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

int R,N,M,K;

/*
Input 1:
3 numbers btw 2..5
2 2 2  8
2 2 3  12
2 2 4  16
2 2 5  20
2 3 3  18
2 3 4  24
2 3 5  30
2 4 4  32
2 4 5  40
2 5 5  50
3 3 3  27
3 3 4  36
3 3 5  45
3 4 4  48
3 4 5  60
3 5 5  75
4 4 4  64
4 4 5  80
4 5 5  100
5 5 5  125
*/

vi prod;

int FindDivisor()
{
    FOREACH(prod, iter)
	{   
	    if (*iter % 3 == 0)
	        return 3;
	    else if (*iter % 5 == 0)
	        return 5;
	    else if (*iter % 4 == 0)
	        return 4;
	}
	return 1;
}

void DivideProd(int ret)
{
    FOREACH(prod,iter)
    {
        if (*iter % ret == 0)
            *iter = *iter / ret;
    }
}

string Solve(int i_case)
{
	//pick N random numbers between 2 and M inclusive
	prod.clear();
	string output = "";
	FOR(i,K)
	{
	    int x;
	    cin >> x;
	    prod.push_back(x);
	}
	sort(prod.begin(), prod.end());
	int ret;
	while((ret = FindDivisor()) > 1)
	{  
	    DivideProd(ret);
	    output += (char)(((int)'0')+ret);
	}
	
	while (output.size() < N)
        output += '2';
    
	return output;
}

int main()
{
	std::cerr << "GCJ 2013 Round 1A-C" << std::endl;
	int numCases;
	std::cin >> numCases;
	std::cout << "Case #1:" << endl;
	std::cin >> R >> N >> M >> K;
	for (int i=0; i<R; i++)
	{
        cout << Solve(i) << std::endl;
	}
	return 0;
}
