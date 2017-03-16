#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	vector<string> ans;
	int t;
	cin>>t;
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		string str;
		int X = abs(x);
		int Y = abs(y);
		if(x>0)
		{
			for(int i=0;i<X;i++)
				str += "WE";
		}
		else
		{
			for(int i=0;i<X;i++)
				str += "EW";
		}
		if(y>0)
		{
			for(int i=0;i<Y;i++)
				str += "SN";
		}
		else
		{
			for(int i=0;i<Y;i++)
				str += "NS";
		}
		ans.push_back(str);	
	}
	for(int i=0; i<ans.size();i++)
	{
		cout<<"Case #"<<i+1<<": "<<ans[i]<<endl;
	}
}