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
    //#include <list>
    //#include <map>
	//#include <set>
	#include <iterator>
#endif
using namespace std;

//enum {MAX_LINE_LEN = 512};
//#include "InputUtils.h"

int A, N;
vector<int> mote;

int movesToNext(int s, int i)
{
	int moves=1;
	while (moves<N-i)
	{
		s += (s-1);
		if (s > mote[i])
			break;
		moves++;
	}
	return moves;
}

void runCase(int Case)
{
    cout << "Case #" << Case+1 << ": ";
	cerr << "Case #" << Case+1 << endl;

	if (A == 1)
	{
		cout << N << endl;
		return;
	}

	int s = A;
	int m = 0;
    for (int i=0; i<N; i++)
    {
		if (s > mote[i])
			s += mote[i];
		else // can't eat
		{
			if (s+s-1 > mote[i])
			{
				s += s-1+mote[i];
				m++;
			}
			else if (i == N-1)
				m++;
			else
			{
				int moves = movesToNext(s, i);
				if (moves >= N-i)	// remove
				{
					m += (N-i);
					break;
				}
				else // add
				{
					m += moves;
					for (int j=0; j<moves; ++j)
						s += (s-1);

					s += mote[i];
				}
			}
		}
    }

	if (m > N)
		m = N;

	assert(m<=N);
    cout << m << endl;
}

void Run()
{
    int T;
    cin >> T;
	cerr << T << " cases" << endl;

    for (int i=0; i < T; i++)
    {
		// Read input
		mote.clear();

        cin >> A >> N;
		for (int m=0; m<N; m++)
		{
			int mm;
			cin >> mm;
			mote.push_back(mm);
		}
		std::sort(mote.begin(), mote.end());

		// Solve
        runCase(i);
    }
}


void main()
{
    _chdir(".\\Archive_Google\\2013");

	#define FILE_NAME "A-large" 
    FILE* in = freopen(FILE_NAME ".in",  "r", stdin);
    FILE* out= freopen(FILE_NAME ".out", "w", stdout);
	assert(in!=NULL && out!=NULL);

    Run();

	cerr << endl;
    //system("pause");
}

