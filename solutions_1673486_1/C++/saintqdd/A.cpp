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
double nop[100000];
double pi[100000];
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("outA.txt","w",stdout);
	int A,B,T;
	
	double ans;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		scanf("%d %d",&A,&B);
		for(int j=0;j<A;j++)
		{
			scanf("%lf",pi+j);
		}
		nop[0] = pi[0];
		for(int j=1;j<A;j++)
		{
			nop[j] = nop[j-1]*pi[j];
		}
		ans = 1e100;		
		// 1
		double t_p;
		int t_step,t_step_no,t_step_yes;
		double ep = 0;
		
		for(int p=-1;p<=A;p++)
		{
			if(p==-1)
			{
				t_step = 1+B+1;
				ep = t_step+0.0;
			}
			else
			{
				double no;
				if(p!=A) no = nop[A-p-1];
				else no = 1;
				double yes = 1-no;
				t_step_no  = p+p+B-A+1;
				t_step_yes = p+p+B-A+1+B+1;
				ep = t_step_no*no+t_step_yes*yes;
			}
			ans = min(ep,ans);
		}

		printf("Case #%d: %.6f\n",i,ans);
	}
	return 0;
}