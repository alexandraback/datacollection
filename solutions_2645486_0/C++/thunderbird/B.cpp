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

int V[10];
int R,N,E;

int maxv(int e,int s)
{
	if(s>N-1)
		return 0;
	if(e>E)
		e=E;
	int v[1000]={0};
	int ret=0;
	for(int i=0;i<=e;i++)
	{
		v[i]=i*V[s]+maxv(e-i+R,s+1);
	}
	for(int i=0;i<1000;i++)
	{
		ret=ret>v[i]?ret:v[i];
	}
	return ret;
}

 int main()
{
	freopen("B-small-attempt2.in","r",stdin);freopen("B-small-attempt2.out","w",stdout);
	//freopen("B.in","r",stdin);freopen("B.out","w",stdout);
	//freopen("B-large-attemp.in","r",stdin);freopen("B-large-attemp.out","w",stdout);
	int testcase;
	int ans=0;
	
	scanf("%d",&testcase);
	for (int case_id=1;case_id<=testcase;case_id++)
	{
		ans=0;
		printf("Case #%d: ",case_id);
		cin>>E>>R>>N;
		int max=0;
		for(int i=0;i<N;i++)
		{
			cin>>V[i];
			max=max>V[i]?max:V[i];
		}
		ans=maxv(E,0);
		for(int i=0;i<N;i++)
		{
		}
		
		printf("%d",ans);
		printf("\n");
	}
	return 0;
}

