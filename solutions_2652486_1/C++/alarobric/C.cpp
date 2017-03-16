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
Input 2:
12 numbers btw 2..8
2 3 4 5 6 7 8
5 and 7 are the only obvious ones
*/

vi prod;
int removed;
int guessed = 0;

int pow4(int exp)
{
    switch(exp) 
    {
        case 1: return 4;
        case 2: return 16;
        case 3: return 64;
        case 4: return 256;
        case 5: return 1024;
        case 6: return 4096;
        case 7: return 16384;
        case 8: return 65536;
        case 9: return 262144;
        case 10: return 1048576;
        case 11: return 1048576*4;
        case 12: return 1048576*16;
    }
}

int FindDivisor()
{
    FOREACH(prod, iter)
	{   
	    if (*iter % 5 == 0)
	        return 5;
	    else if (*iter % 7 == 0)
	        return 7;
	    else if (*iter % 3 == 0 && *iter % 2 != 0)
	        return 3;
	    else if (*iter % 2 == 0 && *iter % 4 != 0 && *iter % 6 != 0)
	        return 2;
	    else if (*iter > pow4(N-removed))
	    {
	        if (*iter % 3 == 0)
    	        return 6;
    	    else
    	        return 8;
    	}
    	else if (removed == N-1 && *iter > 1)
    	    return *iter;
    	
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
	removed = 0;
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
	    removed++;
	}

    if (output.size() < N)
        guessed++;	
	while (output.size() < N)
        output += '4';
    
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
    cerr << "Guessed: " << guessed << endl;
	return 0;
}
