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

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("outA.txt","w",stdout);
	int A,B,T;
	double pi[5];
	double ans;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		scanf("%d %d",&A,&B);
		for(int j=0;j<A;j++)
		{
			scanf("%lf",pi+j);
		}
		ans = 1e100;		
		// 1
		double t_p;
		int t_step;
		double ep = 0;
		for(int p=-1;p<=A;p++)
		{
			t_p = 0;
			ep = 0;
			for(int j=0;j<(1<<A);j++)
			{
				t_p = 1;
				for(int k=0;k<A;k++)
				{
					if( (1<<k)&j )
					{
						t_p *= 1.0 - pi[k];
					}
					else
					{
						t_p *= pi[k];	
					}
				}
				
				bool f = false;
				if(p!=-1) for(int k=0;k<A-p;k++)
				{
					if( (1<<k)&j )
					{
						f=true;break;
					}
				}
				if(p==-1)
				{
					t_step = 1+B+1;
				}
				else
				{
					if(f) t_step = p+p+B-A+1+B+1;
					else t_step = p+p+B-A+1;
				}
				
				ep += t_step*t_p;
			}
			
			ans = min(ep,ans);
		}

		printf("Case #%d: %.6f\n",i,ans);
	}
	return 0;
}