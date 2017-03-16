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
	int n;
	cin >> n;

	vector<int> s1;
	vector<int> s2;
	s1.resize(n);
	s2.resize(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> s1[i];
		cin >> s2[i];
	}

	int step = 0;
	int stars = 0;
	int reserve_stars = 0;
	for(int ns2 = 0; ns2 < n;)
	{
		++step;

		int best_i = -1;
		int best_star = 0;
		int max_s2 = -1;
		for(int i = 0; i < n; ++i)
		{
			if (s2[i] == 0x7FFFFFFF) continue;
			if (s2[i] <= stars)
			{
				best_i = i;
				++ns2;
				if (s1[i] != 0x7FFFFFFF)
				{
					best_star = 2;
				}
				else
				{
					best_star = 1;
				}
				s2[i] = 0x7FFFFFFF;
				break;
			}
			else if (s1[i] <= stars)
			{
				if (s2[i] > max_s2)
				{
					max_s2 = s2[i];
					best_i = i;
					best_star = 1;
				}
			}
		}

		if (!best_star)
		{
			{
				printf("Case #%d: Too Bad\n", in_id + 1);
				return;
			}
/*			else
			{
				--reserve_stars;
				++stars;
				continue;
			}*/
		}

		stars += best_star;
		if (max_s2 >= 0)
			s1[best_i] = 0x7FFFFFFF;
	}

	printf("Case #%d: %d\n", in_id + 1, step);
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
