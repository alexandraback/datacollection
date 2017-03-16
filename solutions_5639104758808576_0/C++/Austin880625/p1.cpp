//
//  p1.cpp
//
//
//  Created by Mac on 4/3/15.
//
//

#include <stdio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<map>

#define MAX_L 105

using namespace std;

string s;
int S[MAX_L];
int sum;
int ans;

int main()
{
    freopen("A.in","r",stdin);
    freopen("p1.out","w",stdout);
    int T;
    cin>>T;
	for(int kase=1;kase<=T;kase++)
	{
		sum=0;
		ans=0;
		int l;
		cin>>l>>s;
		for(int i=0;i<=l;i++)
		{
			S[i]=s[i]-'0';
		}
		for(int i=0;i<l;i++)
		{
			sum+=S[i];
			if(i+1>sum)
			{
				int ad=i+1-sum;
				ans+=ad;
				sum+=ad;
			}
		}
		cout<<"Case #"<<kase<<": "<<ans<<endl;
	}
}
