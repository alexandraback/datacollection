#define _SECURE_SCL 0

#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#ifdef _DEBUG
#define	Assert(E)		do { if (!(E)) {  __asm {int 3}; } } while (false)
#else// _DEBUG
#define	Assert(E)		do { if (!(E)) {  __asm {int 3}; } } while (false)
//#define	Assert(E)		do { if (!(E)) { } } while (false)
#endif//_DEBUG

typedef unsigned long DWORD;
typedef unsigned char BYTE;
typedef unsigned __int64 QWORD;

//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
void ProcessTask(int in_id)
{
	int a, b;
	cin >> a;
	cin >> b;

	vector<double> p;

	p.resize(a);
	for(int i = 0; i < a; ++i)
	{
		cin >> p[i];
	}

	double best = (b + 1) * 10;
	double s = 1.0;
	for(int i = 0; i < a; ++i)
	{
		int n = (a - i);
		double m = (n * 2 + (b - a + 1)) + (1.0 - s) * (b + 1);
		if (m < best) best = m;
		s *= p[i];
	}

	double keep = (b - a + 1) + (1.0 - s) * (b + 1);
	double enter = b + 2;
	if (keep < best) best = keep;
	if (enter < best) best = enter;

	printf("Case #%d: %.8f\n", in_id + 1, best);
}

//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
int main()
{
	int numb;
	cin >> numb;
	cin.get();

	for(int i = 0; i < numb; ++i)
	{
		ProcessTask(i);
	}

	return 0;
}
