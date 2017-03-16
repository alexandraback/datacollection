#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <ctime>
#include<iostream>
#include<cstring>
using namespace std;
const int maxint=214748364;
int times,n,num[1000],last[50];
void mem()
{
	
}
void cou()
{
	vector<int> ou;
	for (int a=1;a<=n;++a) if (last[a]>0) ou.push_back(num[a]);
	for (int a=0;a<ou.size();++a) 
	{
		if (a) printf(" ");
		printf("%d",ou[a]);
	}
	printf("\n");
	ou.clear();
	for (int a=1;a<=n;++a) if (last[a]<0) ou.push_back(num[a]);
	for (int a=0;a<ou.size();++a) 
	{
		if (a) printf(" ");
		printf("%d",ou[a]);
	}
	printf("\n");
}
bool search(int x,int y,int z)
{
	if ((z)&&(!y))
	{
		cou();
		return true;
	}
	if (x<=n)
	{
		last[x+1]=1;
		if (search(x+1,y+num[x+1],1)) return true;
		last[x+1]=-1;
		if (search(x+1,y-num[x+1],1)) return true;
		last[x+1]=0;
		if (search(x+1,y,z)) return true;
	}
	return false;
}
int main()
{
	freopen("B1.in","r",stdin);
	freopen("B1.out","w",stdout);
	scanf("%d",&times);
	for (int z=1;z<=times;++z)
	{
		mem();
		scanf("%d",&n);
		for (int a=1;a<=n;++a)
		{
			scanf("%d",&num[a]);
		}
		printf("Case #%d:\n",z);
		last[1]=1;
		if (search(1,num[1],1)) continue;
		last[1]=0;
		search(1,0,0);
	}
}