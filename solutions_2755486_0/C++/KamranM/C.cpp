#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
using namespace std;
struct Process
{
	int day;
	int guc;
	int w, e;
	Process(int _day, int _guc, int _w, int _e)
		: day(_day),
			guc(_guc),
			w(_w),
			e(_e)
	{
	}

	bool operator < (const Process& rhs)
	{
		return day < rhs.day;
	}
};
vector<Process> A;
const int zero = 500;
int H[1000];
int CH[1000];

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream cin("C-small-attempt0.in");
	ofstream cout("C-small-attempt0.out");

	int T;


	cin >> T;


	for (int ts = 1; ts <= T; ++ts)
	{
		int N;
		cin >> N;

		A.clear();

		while (N--)
		{
			int d, n, w, e;
			cin >> d >> n >> w >> e;
			int s, dd, dp, ds;
			cin >> s >> dd >> dp >> ds;


			for (int i = 1; i <= n; ++i)
			{
				int cur_day = d + (i-1) * dd;
				int cur_guc = s + (i-1) * ds;
				int cur_w = w + (i-1) * dp;
				int cur_e = e + (i-1) * dp;
				A.push_back(Process(cur_day, cur_guc, cur_w+zero, cur_e+zero));
			}

		}
		//cout << A.size() << endl;
		sort(A.begin(), A.end());
		//cout << A.size() << endl;

		memset(H, 0, sizeof(H));
		
		size_t i = 0;
		int ans = 0;

		for (; i < A.size(); )
		{
			
			size_t j = i;
			memset(CH, 0, sizeof(CH));

			while (j < A.size() && A[j].day == A[i].day)
			{

				//cout << A[j].day << " " << A[j].guc << " " << A[j].w - zero << " " << A[j].e - zero<< endl;

				bool attack = false;
				for (int x = A[j].w; x < A[j].e; ++x)
					if (A[j].guc > H[x])
					{
						attack = true;
						CH[x] = max(CH[x], A[j].guc);
					}
				if (attack)++ans;


				++j;
			}

			for (int x = 0; x < 1000; ++x)
				if (CH[x] > H[x])
					H[x] = CH[x];

			
			i = j;
		}

		cout << "Case #" << ts << ": " << ans << endl;
	}


	//system("PAUSE");
	cin.close(); cout.close();
	return 0;
}

