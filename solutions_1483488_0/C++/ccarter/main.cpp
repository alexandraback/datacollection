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

int trans(int d,int wei)
{
	int mul = 1;
	for (int i=1;i<wei;i++)
		mul*=10;
	int tmp = d/10+(d%10)*mul;
	return tmp;

}
int state[2001000];
int main()
{
    int t;

    scanf("%d",&t);
    for (int tt = 1;tt<=t;tt++)
    {
		memset(state,0,sizeof(state));
		int a,b;
		scanf("%d %d",&a,&b);
		int cnt=0;
		for (int i=a;i<=b;i++)
		{


			if (state[i]==0)
			{
				state[i]=1;
				int tmp = i,cntw = 0,tmpcnt=1;
				while (tmp)
				{
					tmp/=10;
					cntw++;
				}
				tmp = i;
				for (int j=0;j<cntw;j++)
				{
					if (tmp%10==0)
						tmp = trans(tmp,cntw);
					else
					{
						tmp = trans(tmp,cntw);
						if (tmp <=b && tmp>=a && state[tmp]==0 ) {
							state[tmp]=1;
							tmpcnt++;
						}
					}

				}
				if (tmpcnt > 1)
				{
					cnt += tmpcnt * (tmpcnt-1) / 2;
				}
			}
		}
		printf("Case #%d: %d\n",tt,cnt);
    }

    return 0;
}
