#define mset(a) memset(a,0,sizeof(a))

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
#include <ctime>

using namespace std;
double s[1000],ans[1000];
int main()
{
	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++)
	{
		int n;
		cin>>n;
		double sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>s[i];
			sum+=s[i];
			ans[i]=0;
		}
		printf("Case #%d:",tt);
		double L=0,R=sum*2;
		while(R-L>0.000000001)
		{
			double M=(L+R)/2;
			double m=sum;
			for(int i=0;i<n;i++)
			{
				if(s[i]>M)continue;
				m-=M-s[i];
				if(m<0)
				{
					R=M;
					goto l1;
				}
			}
			L=M;
l1:;
		}
		for(int i=0;i<n;i++)
		{
			if(s[i]>=L)printf(" 0.000000");
			else printf(" %.6f",(L-s[i])/sum*100);
		}


		printf("\n");
	}
    return 0;
}
