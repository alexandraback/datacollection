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
static const DWORD MaxScore = 30;
static BYTE MaxMap[MaxScore + 1];
static BYTE MaxSurMap[MaxScore + 1];

//--------------------------------------------------------------------------------------------------
void ProcessTask(int in_id)
{
	int n, s, p;
	cin >> n;
	cin >> s;
	cin >> p;

	int low = 0;
	int gt = 0;
	int sur_gt = 0;
	int max_gt = 0;
	vector<int> scores;
	for(int i = 0; i < n; ++i)
	{
		int score;
		cin >> score;
		Assert((score >= 0) && (score <= MaxScore));
		BYTE mmax = MaxMap[score];
		BYTE msur = MaxSurMap[score];
		if (mmax < p)
		{
			if (msur < p)
				++low;
			else
				++sur_gt;
		}
		else
		{
			if (msur >= p)
				++gt;
			else
				++max_gt;
		}
	}

	Assert((low + gt + sur_gt + max_gt) == n);

	int res = gt;
	if (sur_gt >= s)
	{
		res += s + max_gt;
	}
	else
	{
		int ds = s - sur_gt;
		res += sur_gt;
		if (ds > gt)
		{
			ds -= gt;
			if (max_gt > ds)
			{
				res += max_gt - ds;
			}
		}
		else
		{
			res += max_gt;
		}
	}
	Assert(res <= n);

	printf("Case #%d: %d\n", in_id + 1, res);
}

//--------------------------------------------------------------------------------------------------
void MakeMap()
{
	for(DWORD i = 0; i <= MaxScore; ++i)
	{
		MaxMap[i] = 0;
		MaxSurMap[i] = 0;
	}

	for(DWORD a = 0; a <= 10; ++a)
		for(DWORD b = 0; b <= 10; ++b)
			for(DWORD c = 0; c <= 10; ++c)
			{
				int minn = min(min(a, b), c);
				int maxn = max(max(a, b), c);
				if (maxn - minn > 2) continue;

				int sum = a + b + c;
				Assert(sum <= MaxScore);

				if (maxn - minn == 2)
				{
					if (MaxSurMap[sum] < maxn)
						MaxSurMap[sum] = maxn;
				}
				else
				{
					if (MaxMap[sum] < maxn)
						MaxMap[sum] = maxn;
				}
			}
}

//--------------------------------------------------------------------------------------------------
int main()
{
	MakeMap();

	int numb;
	cin >> numb;

	for(int i = 0; i < numb; ++i)
	{
		ProcessTask(i);
	}

	return 0;
}
