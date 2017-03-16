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
void ProcessTask(int in_id)
{
	int a, b;
	cin >> a;
	cin >> b;

	int am = 1;
	int an = 0;
	for(int i = a; i; i /= 10)
	{
		++an;
		am *= 10;
	}

	int bn = 0;
	for(int i = b; i; i /= 10)
		++bn;

	Assert(an == bn);

	std::vector<BYTE> testm;
	testm.assign(b + 1, 0);
	std::vector<int> usedm;

	int res = 0;
	for(int n = a; n <= b; ++n)
	{
		for(int r = 10; r < am; r *= 10)
		{
			int m = (n / r) + (n % r) * (am / r);
			if (m <= n) continue;
			if (m > b) continue;

			if (testm[m]) continue;
			testm[m] = 1;
			usedm.push_back(m);
			++res;
		}

		for(DWORD j = 0; j < usedm.size(); ++j)
			testm[usedm[j]] = 0;
		usedm.clear();
	}

	printf("Case #%d: %d\n", in_id + 1, res);
}

//--------------------------------------------------------------------------------------------------
int main()
{
	int numb;
	cin >> numb;

	for(int i = 0; i < numb; ++i)
	{
		ProcessTask(i);
	}

	return 0;
}
