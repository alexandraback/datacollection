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

__int64 r, t;


long double getSum(__int64 n)
{
	long double a1 = 2*r + 1;
	long double an = a1 + (n-1)*4;
	return (a1+an)*n/2;
}

void runCase(int Case)
{
    cout << "Case #" << Case+1 << ": ";
	cerr << "Case #" << Case+1 << endl;

	int l = 0;
	int h = sqrt((double)t);
	while (l != h)
	{
		int m = (l+h)/2;
		long double s = getSum(m);
		if (s > t)
			h = m;
		else
		{
			if (l == m)
				break;
			l = m;
		}
	}

    cout << l << endl;
}

void Run()
{
    int T;
    cin >> T;
	cerr << T << " cases" << endl;

    for (int i=0; i < T; i++)
    {
		// Read input
        cin >> r;
		cin >> t;

		// Solve
        runCase(i);
    }
}


void main()
{
    _chdir(".\\Archive_Google\\2013");

	#define FILE_NAME "A-small-attempt0" 
    setStdinFromFile(FILE_NAME ".in");
    setStdoutToFile (FILE_NAME ".out");

	time_t start;
	start = time(NULL);

    Run();

	cerr << difftime(time(NULL), start) << " seconds" << endl;
    system("pause");
}

