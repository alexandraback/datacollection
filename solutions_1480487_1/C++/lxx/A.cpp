#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>

using namespace std;

int a[1000];
double ans[1000];
int rank[1000];
int n, T, sum;

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d", &T);
	for (int casenum = 1; casenum <= T; casenum++)
	{
		sum = 0;
		scanf("%d", &n);
		for (int i=0; i<n; i++) 
		{
			scanf("%d", &a[i]);
			sum += a[i];
			rank[i] = i;
		}
		for (int i=0; i<n; i++)
			for (int j=i+1; j<n; j++)
				if (a[rank[i]] > a[rank[j]]) swap(rank[i], rank[j]);
		printf("Case #%d:", casenum);
		int s = 0;
		rank[n] = n;
		a[n] = 10000000;
		for (int i=0; i<n; i++)
		{
			int now = i, tot = i+1, temps = s;
			while (sum - s > tot * (a[rank[now+1]] - a[rank[now]]))
			{
				temps +=tot * (a[rank[now+1]] - a[rank[now]]);
				now++; 	tot++;
			}
			ans[rank[i]] = (double)(a[rank[now]] - a[rank[i]]) +(double)(sum - temps)/(double)tot;
			s+=(a[rank[i+1]] - a[rank[i]])*(i+1);
		}
		for (int i=0; i<n; i++) printf(" %.7lf", max(0.0, 100.0*ans[i]/(double)sum));
		printf("\n");
	} 
}
