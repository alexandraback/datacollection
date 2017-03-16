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
		printf("Case #%d: ",i+1);
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
	vector<db > a(n);
	db sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sum*=(db)2;
	bool b=true;
	db val=(db)sum/(db)n;
	vector<db> res(n,0);
	vector<int> ans(n,0);
	while(b)
	{
		b=false;
		for(int i=0;i<n;i++)
		{
			if(a[i]+eps>val)
			{
				if(res[i]+eps<(db)1)
					b=true;
				res[i]=(db)1;
				ans[i]=1;
			}
		}
		int q=0;
		db sum1=0;
		for(int i=0;i<n;i++)
		{
			if(res[i]+eps>(db)1)
			{
				q++;
				sum1+=a[i];
			}
		}
		val=(sum-sum1)/(db)(n-q);
	}
	for(int i=0;i<n;i++)
	{
		if(res[i]+eps<(db)1)
		{
			res[i]=(db)2*(val-a[i])/sum;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(ans[i])
			printf("0.0000000 ");
		else
			printf("%.7lf ",res[i]*(db)100);
	}
}