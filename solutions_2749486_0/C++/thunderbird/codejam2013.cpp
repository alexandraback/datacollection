#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long ll;

 int main()
{
	freopen("B-small-attempt1.in","r",stdin);freopen("B-small-attempt1.out","w",stdout);
	//freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
	//freopen("BB.in","r",stdin);freopen("BB.out","w",stdout);
	int testcase;
	
	int ans=0;
	
	scanf("%d",&testcase);
	for (int case_id=1;case_id<=testcase;case_id++)
	{
		ans=0;
		printf("Case #%d: ",case_id);

		int x=0,y=0,X,Y;
		cin>>x>>y;
		int step=1;
		/*while(x!=X)
		{
			if(x<0)
			{
				cout<<"E";
				x+=step;
				step++;
			}
			else
			{
				cout<<"W";
				x-=step;
				step++;
			}
		}
		while(y!=Y)
		{
			if(y<0)
			{
				cout<<"N";
				y+=step;
				step++;
			}
			else
			{
				cout<<"S";
				y-=step;
				step++;
			}
		}*/

		if(x>0)
		{
			for(int i=0;i<x;i++)
				cout<<"WE";
		}
		if(x<0)
		{
			for(int i=x;i<0;i++)
				cout<<"EW";
		}
		if(y>0)
		{
			for(int i=0;i<y;i++)
				cout<<"SN";
		}
		if(y<0)
		{
			for(int i=y;i<0;i++)
				cout<<"NS";
		}



		//printf("%d",ans);
		printf("\n");
	}
	return 0;
}

