/******************************************************************************
 * Directives
 *****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

/******************************************************************************
 * Header Files
 *****************************************************************************/
#include <cstdlib>
#include <cstdio>
#include <cstring>

#include <string>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

/******************************************************************************
 * Constants, Macros, Typedefs, Enums & Structures
 *****************************************************************************/
#define MAXD 1000
#define MAXP 1000

/******************************************************************************
 * Global & Static Variables
 *****************************************************************************/
int D;

/******************************************************************************
 * Global & Static Function Prototypes
 *****************************************************************************/
void runCase();

/******************************************************************************
 * Function Implementations
 *****************************************************************************/
int main(int argc, char *argv[])
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		printf("Case #%d: ", t);
		runCase();
	}
	return 0;
}

int getTimes(priority_queue<int>& q)
{
	int t = q.top();
	if (t < 4) {
		return t;
	}

	int minTime = t;
	q.pop();
	for (int i = 2; i <= t / 2; ++i) {
		priority_queue<int> tmpq = q;
		tmpq.push(t - i);
		tmpq.push(i);

		int splitTime = 1 + getTimes(tmpq);
		if (splitTime < minTime) {
			minTime = splitTime;
		}
	}

	return minTime;
}

void runCase() 
{
	scanf("%d", &D);

	priority_queue<int> q;
	for (int i = 0; i < D; ++i) {
		int p;
		scanf("%d", &p);
		q.push(p);
	}

	printf("%d\n", getTimes(q));
}
