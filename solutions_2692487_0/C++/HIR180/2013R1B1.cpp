//Waai GCJR1B Akari GCJ1B Daisuki
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
int main(){
	int t;
	scanf("%d",&t);
	for(int c=1;c<=t;c++)
	{
		int a;
		int n;
		scanf("%d %d",&a,&n);
		vector<int>mote(0);
		for(int i=0;i<n;i++)
		{
			int m;
			scanf("%d",&m);
			mote.pb(m);
		}
		sort(mote.begin(),mote.end());
		if(a==1)
		{
			printf("Case #%d: %d\n",c,n);
			continue;
		}
		int ret=0;
		int cur=a;
		vector<int>add(0);
		for(int i=0;i<n;i++)
		{
			if(cur>mote[i])
			{
				cur+=mote[i];
			}
			else
			{
				while(cur<=mote[i])
				{
					ret++;
					cur=cur*2-1;
				}
				cur+=mote[i];
			}
			add.pb(ret);
		}
		int ans=n;
		for(int i=0;i<n;i++)
		{
			ans=min(ans,add[i]+n-1-i);
		}
		printf("Case #%d: %d\n",c,ans);
	}
}