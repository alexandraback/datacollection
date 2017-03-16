
#include <iostream>
#include <time.h>
#include "tttt.h"
#include "lawnmower.h"

using namespace std;

void main()
{
	time_t start = clock();

	//SolveTTTT();
	SolveLawnMower();

	time_t stop = clock();
	cout << "Time taken: " << (stop - start) << " milliseconds" << endl;

	cin.get();
	return;
}