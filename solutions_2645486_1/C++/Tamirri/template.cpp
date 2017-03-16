#include <iostream>
#include <direct.h>
#include <time.h>
//#include <cmath>
#include <assert.h>

#define STL
#ifdef STL
	#include <string>
	#include <sstream>
    #include <algorithm>
    #include <vector>
    #include <list>
    #include <map>
	#include <set>
	#include <iterator>
#endif
using namespace std;

enum {MAX_LINE_LEN = 512};
#include "InputUtils.h"

int E, R, N;
vector<int> v;

int stepsToNextBigger(int pos, int maxSteps)
{
	int steps = 0;
	int vp = v[pos];
	for (int i=pos+1; i < N; ++i)
	{
		++steps;
		if (v[i] > vp)
			return steps;

		//if (steps == maxSteps)
		//	return maxSteps;
	}

	return 0;
}

void runCase(int Case)
{
    cout << "Case #" << Case+1 << ": ";
	cerr << "Case #" << Case+1 << ": ";

	__int64 gain = 0;
	__int64 rem = E;

    for (int i=0; i<N; i++)
    {
		int vi = v[i];

		if (i == N-1)
		{
			gain += vi*rem;
			break;
		}

		int maxSteps = E - rem/2 + 1;
		int stepsToBigger = stepsToNextBigger(i, maxSteps);
		if (stepsToBigger == 0)	// Take it all
		{
			gain += vi*rem;
			rem = R;
			continue;
		}

		__int64 use = rem + R*stepsToBigger - E; 
		if (use < 0)
			use = 0;
		if (use > E)
			use = E;

		gain += vi*use;
		rem += (R - use);
    }

    cout << gain << endl;
	cerr << gain << endl;
}

void Run()
{
    int T;
    cin >> T;
	cerr << T << " cases" << endl;

    for (int i=0; i < T; i++)
    {
		v.clear();

		// Read input
		cin >> E;
		cin >> R;
        cin >> N;
		for (int n=0; n<N; ++n)
		{
			int vi;
			cin >> vi;
			v.push_back(vi);
		}

		// Solve
        runCase(i);
    }
}


void main()
{
    _chdir(".\\Archive_Google\\2013");

	//#define FILE_NAME "B-small-attempt2" 
	#define FILE_NAME "B-large"
    setStdinFromFile(FILE_NAME ".in");
    setStdoutToFile (FILE_NAME ".out");

	time_t start;
	start = time(NULL);

    Run();

	cerr << difftime(time(NULL), start) << " seconds" << endl;
    system("pause");
}

