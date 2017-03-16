#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <set>
using namespace std;
#define oo 1000000007
long long int gcd(long long int a,long long int b){
      if(b==0)return a;
      return gcd(b,a%b);
}

long long int c,d,v,cursum;
long long int a[500];
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	for (int j = 0; j < t; ++j)
	{
		cin>>c>>d>>v;
		for (int i = 0; i < d; ++i)
		{
			cin>>a[i];
		}
		map<int,int> mp;
		map<int,int>::iterator it;
		sort(a,a+d);
		long long int ans=0;
		cursum=1;

		if(a[0]!=1)
		{
			ans++;
			mp[1]=1;
		}
		for (int i = 0; i < d; ++i)
		{	
			if(cursum>=v)
			{
				break;
			}
			if(a[i]<=cursum && mp[a[i]]==1)
			{
				continue;
			}
			if(a[i]<=cursum && mp[a[i]] == 0)
			{
				cursum=cursum+a[i];
				mp[a[i]]=1;
			}
			else
			{	
				if( cursum+1==a[i] )
				{
					mp[cursum+1]=1;
					cursum=cursum + cursum + 1;
				}
				else{
					mp[cursum+1]=1;
					cursum=cursum+ cursum + 1;
					ans++;
					i--;
				}
			}
		}
		while(cursum<v)
		{
			cursum=cursum+cursum+1;
			ans++;	
		}
		cout<<"Case #"<<j+1<<": "<<ans<<endl;
	}
	return 0;
}