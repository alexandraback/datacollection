//Google Codejam
//2013 Round 1A
//Alan Richards - alarobric

//Problem B
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
#define Debug(x) std::cerr << x << endl
#else
#define Debug(x)
#endif

typedef unsigned long long ull;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

int E, R, N;
vi V;
int maxGain;

void DoActivity(int index, int energy, int gain)
{
    if (index <3) Debug(index << " " << energy << " " << gain);
    if (index == N)
    {
        if (gain > maxGain)
            maxGain = gain;
        return;
    }
    if (energy > E)
        energy = E;
    for(int i=0; i<= energy; i++)
    {
        if(index<3)Debug(i);
        DoActivity(index+1,energy-i+R,gain+V[index] * i);
    }
}

int Solve(int i_case)
{
    maxGain = 0;
	std::cin >> E >> R >> N;
	V.clear();
	FOR(i,N)
	{
	    int x;
	    cin >> x;
	    V.push_back(x);
	}
	//start with E joules of energy, can never go over that
	//spend non-negative integer amount of energy on each activity
	//regain R after each
	//gain = energy spent on activity * value of activity
	DoActivity(0, E, 0);
	
	Debug(maxGain);
	return maxGain;
}

int main()
{
	std::cerr << "GCJ 2013 Round 1A-B" << std::endl;
	int numCases;
	std::cin >> numCases;
	for (int i=1; i<=numCases; i++)
	{
		std::cout << "Case #" << i << ": " << Solve(i) << std::endl;
	}
	return 0;
}
