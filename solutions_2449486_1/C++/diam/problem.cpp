
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <unordered_map>


using namespace std;


int a[500][500];
int usedi[500];
int usedj[500];
int main()
{
	freopen("input.txt","rt", stdin);
	freopen("output.txt","wt", stdout);			
	int tests;
	scanf("%d", &tests);
	for (int test = 1; test <= tests; test++)
	{		
		bool ok = false;
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				scanf("%d", &a[i][j]);
		for (int i = 0; i < n; i++)
			usedi[i] = 1;
		for (int j = 0; j < m; j++)
			usedj[j] = 1;
		while (1)
		{
			int min = 1000;
			int mini = -1;
			int minj = -1;
			for (int i = 0; i < n; i++)
				for(int j = 0; j < m; j++)
					if (usedi[i] && usedj[j])
						if (a[i][j] < min)
						{
							min = a[i][j];
							mini = i;
							minj = j;
						}
			//printf("%d %d \n", mini, minj);
			if (mini == -1)
			{
				ok = true;
				break;
			}
			int bad = false;
			for (int i = 0; i < n; i++)
				if (usedi[i])
					if (a[i][minj] > min)
						bad = true;
			if (bad == false)
			{
				usedj[minj] = 0;
				continue;
			}

			bad = false;
			for (int j = 0; j < m; j++)
				if (usedj[j])
					if (a[mini][j] > min)
						bad = true;
			if (bad == false)
			{
				usedi[mini] = 0;
				continue;
			}
			ok = false;
			break;

		}

		if (ok)	
			printf("Case #%d: YES\n",test);
		else
			printf("Case #%d: NO\n",test);
	}
	return 0;			
}     
