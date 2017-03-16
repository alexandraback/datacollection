#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <set>
#include <map>

using namespace std;
struct sit
{
	int d[40];
	double p;
};
vector<sit> cur;
vector<sit> adds;
void add(const sit& el, int ind, double p)
{
	int a,b,c;
	a = el.d[ind];
	b = el.d[ind-1];
	c = el.d[ind+1];
	if (a>b&&a>c)
	{
		add(el, ind-1,p/2);
		add(el, ind+1,p/2);
		return ;
	}
	if (a<b && a<c)
	{
		sit temp = el;
		temp.p = p;
		temp.d[ind]+=2;
		adds.push_back(temp);
		return ;
	}
	if (b==-1)
	{
		sit temp = el;
		temp.p = p;
		temp.d[ind-1]= 1;
		temp.d[ind-2]= 0;
		adds.push_back(temp);
		return ;
	}
	if (c==-1)
	{
		sit temp = el;
		temp.p = p;
		temp.d[ind+1]= 1;
		temp.d[ind+2]= 0;
		adds.push_back(temp);
		return ;
	}
	if (b<a && a<c)
	{
		add(el, ind-1, p);
		return ;
	}
	if (c<a && a<b)
	{
		add(el, ind+1, p);
		return ;
	}

}
int main()
{	
	freopen("B-small-attempt0.in","r",stdin);
	freopen("2.txt","w",stdout);
	int testcnt;
	cin>>testcnt;
	for (int curtest = 1; curtest<=testcnt;curtest++)
	{
		cur.clear();
		cout<<"Case #"<<curtest<<": ";
		int n,x,y;
		cin>>n>>x>>y;
		sit first;
		first.p=1;
		for (int i=0;i<40;i++)
		{
			first.d[i]=-1;
		}
		first.d[20]=1;
		first.d[19]= first.d[21] = 0;
		cur.push_back(first);
		for (int i=1;i<n;i++)
		{
			for (int j=0;j<cur.size();j++)
			{
				add(cur[j],20,cur[j].p);
			}
			cur = adds;
			adds.clear();
		}
		double res=0;
		for (int i=0;i<cur.size();i++)
		{
			for (int j=0;j<40;j++)
			{
				int curx = j - 20;
				int cury = cur[i].d[j] == -1 ? 0 : cur[i].d[j];
				if (curx == x && cury > y)
				{
					int diff = cury - y;
					if (diff&1)
						res +=cur[i].p;
				}
			}
		}
		printf("%.8lf",res);

		cout<<"\n";
	}
	return 0;
}
