#include <iostream>
#include<iomanip>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <deque>
//#define SET(p) memset(p,-1,sizeof(p))
//#define CLR(p) memset(p,0,sizeof(p))
#define LL long long int
#define ULL unsigned long long int
#define S(n) scanf("%d",&n)
#define Sl(n) scanf("%lld",&n)
#define Sf(n) scanf("%lf",&n)
#define Ss(n) scanf("%s",n)
using namespace std;
int kmod=1000000007;

void fun(int k)
{
	int a,n;
	S(a);
	S(n);
	vector<int> mote(n);
	for(int i=0;i<n;i++)
	{
		S(mote[i]);
	}
	if(a==1)
	{
		printf("Case #%d: %d\n",k,n);
		return;
	}
	sort(mote.begin(),mote.end());

	vector<int> ash(n);
	int sum=a,count=0,mini=n;
	for(int i=0;i<n;i++)
	{
		if(mote[i]<sum)
		{
			sum+=mote[i];
			ash[i]=count;
		}
		else{
			while(sum<=mote[i])
			{
				count++;

				sum+=sum-1;

			}
			sum+=mote[i];
			ash[i]=count;

		}


	}

	for(int i=0;i<n;i++)
	{
		//cout<<mini<<endl;
		mini=min(mini,ash[i]+n-i-1);
		//cout<<ash[i]<<" ";
	}


printf("Case #%d: %d\n",k,mini);
}

int main()
{
	int t;
	S(t);
	for(int k=1;k<=t;k++)
	{
		fun(k);
		//cin>>s;
	}
	return 0;
}

