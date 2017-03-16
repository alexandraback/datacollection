#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include <iomanip>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<stack>
#include<cstring>
#include<map>
#include<set>
using namespace std;
#define MOD 1000000007
int a[1111];
int b[1111];
int main()
{
	int t,T;
	int i,n,j,m;
	int re;
	int x;
	freopen("B-small-attempt3.in","rt",stdin);
	freopen("B.out","wt",stdout);
	cin>>T;
	for(t=1;t<=T;t++)
	{
		cin>>n;
		m=0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			m=max(m,a[i]);
		}
		re=m;
		for(i=1;i<=m;i++)
		{
			x=i;
			for(j=0;j<n;j++)
			{
				if(a[j]>i)
				{
					if(a[j]%i==0)
						x+=a[j]/i-1;
					else
						x+=a[j]/i;
				}
			}
			re=min(re,x);
		}
		cout<<"Case #"<<t<<": "<<re<<endl;
	}
    return 0;
}