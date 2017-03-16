#include <algorithm>
#include <numeric>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
#include <stack>
using namespace std;

double prob[10002][10002];
int A,N;

void solveCase(int t)
{
	int n,x,y;
	cin>>n>>x>>y;
	int lay=0;
	int cur=0;
	while (n>=0)
	{
		cur=lay*4+1;
		if (n<cur)
			break;
		else
		{
			n-=cur;
			lay++;
		}
	}
	if (abs(x)+abs(y)<lay*2)
		printf("Case #%d: %.7lf\n",t+1,1.0);
	else if (abs(x)+abs(y)>lay*2)
		printf("Case #%d: %.7lf\n",t+1,0.0);
	else
	{
		int al=lay*4;
		int need=y+1;
		double res=0;
		for (int i=0;i<=n;i++)
		{
			int lft=i;
			int rgt=n-i;
			if (lft>al/2)
			{
				rgt+=(lft-al/2);
				lft=al/2;
			}
			if (rgt>al/2)
			{
				lft+=(rgt-al/2);
				rgt=al/2;
			}
			if (lft>=need)
				res+=prob[n][i];
		}
		printf("Case #%d: %.7lf\n",t+1,res);
	}
}

int main()
{
	freopen("in.in","rt",stdin);
	freopen("out.out","wt",stdout);
	prob[0][0]=1;
	for (int i=1;i<=10001;i++)
	{
		for (int j=0;j<=i;j++)
		{
			if (j==0)
				prob[i][j]=prob[i-1][j]/2;
			else
				prob[i][j]=(prob[i-1][j]+prob[i-1][j-1])/2;
		}
	}
	int t;
	cin>>t;
	for (int i=0;i<t;i++)
		solveCase(i);
	return 0;
}