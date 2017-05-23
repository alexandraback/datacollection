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

#define PB push_back  
#define MP make_pair  

#define REP(i,n) for(i=0;i<(n);++i)  
#define FOR(i,l,h) for(i=(l);i<=(h);++i)  
#define FORD(i,h,l) for(i=(h);i>=(l);--i)  
#define CLOCK cout << "Clock " << (double)clock()/CLOCKS_PER_SEC << endl
const int maxs = 102;

int main()
{
	freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int cases=1;cases<=t;cases++)
	{
		int n,s,p;
		int sum[maxs];
		scanf("%d %d %d",&n,&s,&p);
		for (int i=0;i<n;i++) scanf("%d",&sum[i]);
		int res = 0;
		for (int i=0;i<n;i++)
		{
			int tmp = sum[i]/3;
			if(sum[i]%3==0)
			{
				if(tmp >= p) res ++;
				else if(tmp>0 && tmp+1 >= p && s>0)
				{
					res ++;
					s--;
				}
			}
			else if(sum[i]%3==1)
			{
				if(tmp+1 >= p) res++;
			}
			else
			{
				if(tmp+1 >= p) res++;
				else if (tmp+2>=p && s>0)
				{
					res ++;
					s --;
				}
			}
		}
		printf("Case #%d: ",cases);
		cout << res << endl;
	}
	return 0;
}