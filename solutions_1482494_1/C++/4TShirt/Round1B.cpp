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
const int maxs = 1010;
struct node
{
	int a,b;
	int cnt;
};
struct node star[maxs];
int n;

int getAC()
{
	int res = 0;
	int curStar = 0;
	int maxt = 2*n + 100;
	for (int t=0;t<maxt;t++)
	{
		int index = -1;
		int setLevel = 0;
		int added = 0;
		for (int i=0;i<n;i++)
		{
			if (star[i].cnt == 2)  continue;
			else{
				if (curStar >= star[i].a && star[i].cnt<1)
				{
					int tmpAdd = 1 - star[i].cnt;
					if(tmpAdd == 0) continue;
					if(tmpAdd > added)
					{
						added = tmpAdd;
						index = i;
						setLevel = 1;
					}
					else if(tmpAdd == added)
					{
						if(setLevel == 1)
						{
							if(star[i].b > star[index].b)
							{
								added = tmpAdd;
								index = i;
								setLevel = 1;
							}
						}
					}
				}
				if (curStar >= star[i].b)
				{
					int tmpAdd = 2 - star[i].cnt;
					if (tmpAdd > added)
					{
						added = tmpAdd;
						index = i;
						setLevel = 2;
					}
					else if(tmpAdd==1 && setLevel==1)
					{
						added = tmpAdd;
						index = i;
						setLevel = 2;
					}
				}
			}
		}
		if (added == 0) break;
		else
		{
			star[index].cnt = setLevel;
			res ++;
			curStar += added;
		}
	}
	bool flag = true;
	for (int i=0;i<n;i++)
		if (star[i].cnt < 2)flag = false;
	if (!flag) return -1;
	return res;
}
int main()
{
	//freopen("B-small-attempt1.in","r",stdin);freopen("B-small-attempt1.out","w",stdout);
	freopen("B-large.in","r",stdin);freopen("B-large.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int cases=1;cases<=t;cases++)
	{
		cin >> n;
		for (int i=0;i<n;i++) {cin >>star[i].a >> star[i].b; star[i].cnt = 0;}
		printf("Case #%d: ",cases);
		int res = getAC();
		if (res == -1)
			cout << "Too Bad" << endl;
		else cout << res << endl;
	}
	return 0;
}