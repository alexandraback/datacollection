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
#include <strstream>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

int main()
{
	int tt;
	scanf("%d",&tt);
	for (int ttt=1;ttt<=tt;ttt++)
	{
		int n,s,p,cnt=0;
		scanf("%d %d %d",&n,&s,&p);
		for (int i=0;i<n;i++)
		{
			int sc;
			scanf("%d",&sc);
			if (sc<3*p-4) continue;
			else if (sc > 3*p-3) cnt++;
			else if (s>0)
			{
				if (sc >= 2 && (sc == 3*p-4 || sc == 3*p-3)) {s--;cnt++;}
			}

		}
		printf("Case #%d: %d\n",ttt,cnt);
	}
	return 0;
}

