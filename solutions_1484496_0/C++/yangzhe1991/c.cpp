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
int a[1000];
bool bb;
int tt;
int n;

vector<int>s1,s2;
int sum1,sum2;
void dfs(int p)
{
	if(bb)return;
	if(sum1==sum2)
	{
		bb=1;
		for(int i=0;i<s1.size();i++)
		{
			if(i>0)printf(" ");
			printf("%d",s1[i]);
		}
		printf("\n");
		for(int i=0;i<s2.size();i++)
		{
			if(i>0)printf(" ");
			printf("%d",s2[i]);
		}
		printf("\n");
		return;
	}
	if(p>=n)return;
	s1.push_back(a[p]);
	sum1+=a[p];
	dfs(p+1);
	sum1-=a[p];
	s1.pop_back();
	s2.push_back(a[p]);
	sum2+=a[p];
	dfs(p+1);
	sum2-=a[p];
	s2.pop_back();
	dfs(p+1);

}

int main()
{
	int t;
	cin>>t;
	for(tt=1;tt<=t;tt++)
	{
		cin>>n;
		s1.clear();
		s2.clear();
		bb=0;
		printf("Case #%d:\n",tt);
		sum1=sum2=0;
		for(int i=0;i<n;i++)
		cin>>a[i];
		vector<int> st=s1;
		s1.push_back(a[0]);
		sum1+=a[0];
		dfs(1);
		if(bb)continue;
		s1=st;
		sum1-=a[0];
		st=s2;
		s2.push_back(a[0]);
		sum2+=a[0];
		dfs(1);
		if(bb)continue;
		sum2-=a[0];
		s2=st;
		dfs(1);
		if(!bb)printf("Impossible\n");
	}
    return 0;
}
