//source here
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <climits>
#include <cstring>
#include <ctime>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <vector>
#include <list>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <sstream>
//C++11
//#include <array>
//#include <forward_list>
//#include <unordered_map>
//#include <unordered_set>
using namespace std;

int main()
{
	freopen("out","w",stdout);
	int T;
	double c,f,x;
	//x target
	//c farm cost
	//f extra gain/s/farm
	scanf("%d",&T);
	for (int t=1;t<=T;++t)
	{
		scanf("%lf%lf%lf",&c,&f,&x);
		double vel=2.0,tTotal=0.0;
		while (true)
		{
			if (x<c)
			{
				tTotal+=x/vel;
				break;
			}
			else
			{
				tTotal+=c/vel;
				if (x/(vel+f)<(x-c)/vel)
					vel+=f;
				else
				{
					x-=c;
					tTotal+=x/vel;
					break;
				}
			}
		}
		printf("Case #%d: %.7lf\n",t,tTotal);
	}
	return 0;
}