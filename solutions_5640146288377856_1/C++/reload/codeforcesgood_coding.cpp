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

long long int n,ans,r,c,w;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	for (int i = 0; i < t; ++i)
	{
		cin>>r>>c>>w;

		if(c%w>0)
		{
			ans=r * c/w + 1 + (w-1);
		}
		else
		{
			ans=r *  c/w + w-1;
		}
		cout<<"Case #"<<i+1<<": "<<ans<<endl;
	}
	return 0;
}