//Google Codejam
//2013 Round 1B
//Alan Richards - alarobric

//Problem A
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
using namespace std;

#define FOR(i, n) for(ull i=0; i<n; i++)
#define FOREACH(c, iter) for(auto iter=c.begin(); iter!=c.end(); iter++)

#ifdef DEBUG
#define Debug(x) std::cerr << x << endl
#else
#define Debug(x)
#endif

typedef unsigned long long ull;
typedef vector<vector<ull>> vvi;
typedef vector<ull> vi;

template <class T>
string ContainerPrint(T a)
{
	stringstream ss;
	FOREACH(a, iter)
		ss << *iter << " ";
	return ss.str();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vi motes;
ull A, N;

int recurse(int index, ull mo, int numOper)
{
    if (numOper > N)
        return N;
    
    while (index != N)
    {
	    if (mo > motes[index])
        {
            mo = mo + motes[index];
            index++;
        }
        else
        {
            //need to add or remove a mote
            //if we delete one then we delete all remaining
            return min( recurse(index, mo*2-1, numOper+1), recurse(N, mo, numOper + N-index));
        }
    }
    return numOper;
}

int Solve(int i_case)
{	
	std::cin >> A >> N;
	motes.clear();
	FOR(i,N)
	{
	    ull x;
	    cin >> x;
	    motes.push_back(x);
	}
	sort(motes.begin(), motes.end());
	auto iter = motes.begin();
	
	return recurse(0, A, 0);
}

int main()
{
	std::cerr << "GCJ 2013 Round 1B-A" << std::endl;
	int numCases;
	std::cin >> numCases;
	for (int i=1; i<=numCases; i++)
	{
		std::cout << "Case #" << i << ": " << Solve(i) << std::endl;
	}
	return 0;
}
