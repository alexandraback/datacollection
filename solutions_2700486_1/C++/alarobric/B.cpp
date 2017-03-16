//Google Codejam
//2013 Round 1B
//Alan Richards - alarobric

//Problem B
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <array>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include <iomanip>
using namespace std;

#define FOR(i, n) for(ll i=0; i<n; i++)
#define FOREACH(c, iter) for(auto iter=c.begin(); iter!=c.end(); iter++)

#ifdef DEBUG
#define Debug(x) std::cerr << x << endl
#else
#define Debug(x)
#endif

typedef long long ll;

template <class T>
string ContainerPrint(T a)
{
	stringstream ss;
	FOREACH(a, iter)
		ss << *iter << " ";
	return ss.str();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ll N, X, Y;
ll chooseArray[1450][1450];

ll choose(ll n, ll k)
{
    if (k == 0)
        return 1;
    if (n == 0)
        return 0;
    if (chooseArray[n][k] != -1)
        return chooseArray[n][k];
        
    ll ret = choose(n-1, k-1) + choose(n-1, k);
    chooseArray[n][k] = ret;
    return ret;
}

double Solve(int i_case)
{
	std::cin >> N >> X >> Y;
	
	//find biggest base
	ll i=1;
	while ((i+1)/2*i <= N)
	    i+=2;
	i-=2;
	Debug(endl << N << " " << X << " " << Y << " " << i);
	
	//if x,y lies inside inner triangle or outside outer row, we already know the answer
	if (abs(X) + abs(Y) <= i-1)
	{
	    Debug("done " << 1.0);
	    return 1.0;
	}
	else if (abs(X)+abs(Y) > i+1)
	{
	    Debug("done1 " << 0.0);
	    return 0.0;
	}
	else if (Y == i+1)
	{
	    Debug("done3 " << 0.0);
	    return 0.0;
	}
	    
	//so now it's just do enough diamonds fall on the side we need
	ll remaining = N - ((i+1)/2*i);
	Debug("remain " << remaining);
	
	//x is irrelevant, the problem is mirrored
	//we need y+1 to fall on this side
    if (remaining < Y+1)
    {
        Debug("done " << 0.0);
        return 0.0;
    }
    
    if (remaining <= i+1)
    {
        //k or more successes in n trials
        //n choose i for all i >= k
        ll numsuccess = 0;
        for (ll j = Y+1; j<=remaining; j++)
        {
            numsuccess = numsuccess + choose(remaining, j);
        }
            
        double p = numsuccess / pow((double)2.0,remaining);
        Debug("done " << p);
	    return p;
	}
	else
	{
	    //guaranteed at least one on each side
        ll guaranteed = remaining - (i+1);
        if (Y+1 <= guaranteed)
            return 1.0;
        
        //k or more successes in n trials
        //n choose i for all i >= k
        ll numsuccess = 0;
        for (ll j = Y+1; j<=remaining; j++)
        {
            numsuccess = numsuccess + choose(remaining, j);
        }
            
        double p = numsuccess / pow((double)2.0,remaining);
        Debug("done " << p);
	    return p;
	}
}

int main()
{
    FOR(i,1450)
        FOR(j,1450)
            chooseArray[i][j] = -1;
    Debug(choose(18,15));
            
	std::cerr << "GCJ 2013 Round 1B-B" << std::endl;
	int numCases;
	std::cin >> numCases;
	for (int i=1; i<=numCases; i++)
	{
		std::cout << "Case #" << i << ": " << std::setprecision(9) << fixed << Solve(i) << std::endl;
	}
	return 0;
}
