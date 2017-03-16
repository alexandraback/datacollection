#include <vector>
#include <map>
//#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

#define sz(a) (int)(a.size())
#define len(a) (int)(a.length())
#define pb push_back
#define mp make_pair
#define fi first
#define se second

int main()
{
	freopen("C-small-attempt1.in","r",stdin);
	freopen("o.txt","w",stdout);
	int t,cas=1;
	scanf("%d",&t);
	while(t--)
	{
		printf("Case #%d: ",cas++);
		int c,d,v;
		scanf("%d%d%d",&c,&d,&v);
		vector<bool> exists(31,false);
		exists[0]=true;
		for(int i=0;i<d;++i)
		{
			int x;
			scanf("%d",&x);
			exists[x]=true;
		}
		int ptr=0;
		int our_max=0,need=0;
		for(int i=0;i<=v;++i)
		{
			while(our_max<i)
			{
				if(!exists[ptr]) ++need;
				our_max+=ptr;
				++ptr;
			}
		}
		printf("%d\n",need);
	}
	return 0;
}