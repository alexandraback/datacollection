// Round1B.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "iostream"
#include "vector"
#include "string.h"
#include "string"
#include "algorithm"
using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		string str;
		cin>>str;
		int g[100]={};
		for(int i=0;i<str.size();i++)
		{
			g[str[i]-'A']++;
		}
		char digits[][20]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
		int order []={0,2,6,7,5,4,3,8,1,9};
		string ans;
		for(int i=0;i<10;i++)
		{
			int c=order[i];
			int finish=0;
			while(1)
			{
				for(int j=0;digits[c][j]!=0;j++)
				{
					int ch = digits[c][j]-'A';
					g[ch]--;
					if(g[ch]<0) finish=1;
				}
				if(finish)
				{
					for(int j=0;digits[c][j]!=0;j++)
					{
						int ch = digits[c][j]-'A';
						g[ch]++;
					}
					break;
				}
				ans.push_back(c+'0');
			}
		}
		sort(ans.begin(),ans.end());
		cout<<"Case #"<<tc+1<<": "<<ans<<endl;
	}
	return 0;
}