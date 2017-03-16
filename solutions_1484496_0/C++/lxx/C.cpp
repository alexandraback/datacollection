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

int a[22];
int f[22][4500000], from[22][4500000];
int n, T, sum = 0;

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	scanf("%d", &T);

	for (int casenum = 1; casenum <= T; casenum++)
	{
		memset(f, 255, sizeof(f));
		f[0][2100000] = 0;
		scanf("%d", &n);
		printf("Case #%d:\n", casenum);
		int find = -1;
		for (int i=1; i<=n; i++) 
		{
			scanf("%d", &a[i]);
			for (int k=0; k<i; k++) 
				for (int j = -2000000+2100000; j<2000000 + 2100000; j++)
					if (f[k][j] != -1) 
					{
						f[i][j+a[i]] = j;
						from[i][j+a[i]] = k;
						f[i][j-a[i]] = j;
						from[i][j-a[i]] = k;
						if (j+a[i] == 2100000 || j-a[i] == 2100000) find = i;
					}
		}
		if (find == -1) printf("Impossible\n");
		else
		{
			vector <int> p1, p2;
			p1.clear(); p2.clear();
			int key = 2100000;
			while (find!=0)
			{
				if (f[find][key] > key) p1.push_back(f[find][key] - key);
					else p2.push_back(key - f[find][key]);
				int temp = from[find][key];
				key  = f[find][key];
				find = temp;
			}
			for (int i=p1.size()-1; i>0; i--) printf("%d ",p1[i]);
			printf("%d\n",p1[0]);
			for (int i=p2.size()-1; i>0; i--) printf("%d ",p2[i]);
			printf("%d\n",p2[0]);
		}
	}

}
