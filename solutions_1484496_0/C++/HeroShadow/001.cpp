#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<math.h>
#include<string>
#include<string.h>
#include<math.h>
#include<queue>
//#include<unordered_map>
using namespace std;

#define li long long
#define db double
#define mp make_pair
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define vi vector<int>
long long INF =1000000007;
const int mod =31;
db eps=0.0000000001;

void solve();

int main ()
{
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#else
	//freopen("necklace.in","r",stdin);
	//freopen("necklace.out","w",stdout);
#endif
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		printf("Case #%d:\n",i+1);
		solve();
		printf("\n");
	}
	return 0;
}
//#define int li
void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	vector<int> b(INF/200,0);
	for(int i=0;i<(1<<n);i++)
	{
		int sum=0;
		for(int q=0;q<n;q++)
		{
			if(i&(1<<q))
				sum+=a[q];
		}
		if(b[sum]==0)
			b[sum]=i;
		else
		{
			vector<int> res1,res2;
			int mask1=b[sum],mask2=i;
			int mask=mask1^mask2;
			for(int q=0;q<n;q++)
			{
				if((mask>>q)&1)
				{
					if((mask1>>q)&1)
						res1.push_back(q);
					if((mask2>>q)&1)
						res2.push_back(q);
				}
			}
			for(int q=0;q<res1.size();q++)
				printf("%d ",a[res1[q]]);
			printf("\n");
			for(int q=0;q<res2.size();q++)
				printf("%d ",a[res2[q]]);
			return;
		}
	}
}