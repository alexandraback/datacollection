
#include<malloc.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<cstring>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main()
{
	int t,a,b,ans;
	cin >>t;
	rep(x,t)
	{
		map<  pair<int , int> , int   > p;
		cin>>a>>b;
		ans=0;
		int len=0,temp=b,oop=1;
		while(temp>0)
		{
			temp/=10;
			len++;
			oop*=10;
		}
		oop/=10;

		for(int i=a;i<b;i++)
		{
			temp=i;
			rep(j,len-1)
			{
				temp=temp/10 + (temp%10)*oop;
				if( (temp>i) && (temp<=b) && ( p[make_pair(i,temp)] == 0 )) 
				{
					ans++;
					p[ make_pair(i,temp) ]=1;
					//cout<<i<<" " << temp<<endl;
				}
				
				
			}
		}
		cout<<"Case #"<<x+1<<": "<<ans<<endl;
	}
	return 0;
}
