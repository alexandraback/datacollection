#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <cstring>
#include <string>
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
#define LL long long
#define pi 3.1415926535897932384626433 
#define sqr(a) ((a)*(a))

using namespace std;

double a[1010], b[1010];
int u[1010];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);	
#endif
	
	int T; cin >> T;
	for (int t = 1; t <= T; t ++)
	{
		cout << "Case #" << t << ": ";
		int N;
		cin >> N;
		for (int i = 1; i <= N; i ++)
			cin >> a[i];
		for (int i = 1; i <= N; i ++)
			cin >> b[i];
		
		sort(a + 1, a + 1 + N);
		sort(b + 1, b + 1 + N);
		
		int s = 0;
		
		int L = 1, R = N;
		for (int i = 1; i <= N; i ++)
			if (a[i] > b[L])		
				L ++, s ++;
			else R --;
		cout << s << " ";
		
		memset(u, 0, sizeof(u));
		s = 0;
		for (int i = 1; i <= N; i ++)
		{
			double mm = 2.0; int id = -1;
			for (int j = 1; j <= N; j ++)
				if (! u[j] && b[j] > a[i] && b[j] < mm)
					mm = b[j], id = j;
			if (id == -1)
			{
				mm = 2.0;
				for (int j = 1; j <= N; j ++)
					if (! u[j] && b[j] < mm)
						mm = b[j], id = j;
				u[id] = 1;
				s ++;
			}
			else
				u[id] = 1;
		}
		cout << s << endl;
		
		
	}
	return 0;
}
