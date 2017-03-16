
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<utility>
#include<cstdlib>
#include<string>
#include<sstream>
#include<fstream>
#include<set>
using namespace std;

#define MAX 1000
#define ll long long

int main()
{
//	freopen("A-large.in","r",stdin);
//	freopen("output.txt","w",stdout);
	int aray[MAX];
	int t;
	cin>>t;
	int a,n;
	for(int cas=0;cas<t;cas++)
	{
		cin>>a>>n;
		for(int i=0;i<n;i++)
		{
			cin>>aray[i];
		}
		sort(aray,aray+n);
		int res=0;
		int resmax=n;
		for(int i=0;i<n&&res<resmax;i++)
		{
			if(a>aray[i])
				a+=aray[i];
			else if(a+a-1>aray[i])
			{
				res++;
				a+=a-1+aray[i];
			}
			else
			{
			//	res+=n-i;
			//	break;
				resmax=min(resmax,res+n-i);
				res++;
				a+=a-1;
				i--;
			}
		}
		printf("Case #%d: %d\n",cas+1,res);
	}
    return 0;
}
