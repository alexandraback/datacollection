//Nakul Krishna
//Computer Science Engineering
//Amrita Vishwa Vidyapeetham

#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<climits>
#include<algorithm>
#include<sstream>
#include<queue>
#include<stack>

#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

#define pb push_back
#define mp make_pair

using namespace std;

unsigned long long mod=1000000007;

int isvowel(char c)
{
	if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u')
		return 1;
	return 0;
}

int main()
{
	int t,nak=1;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		string str;
		cin>>str;
		scanf("%d",&n);
		int l=str.size(),ans=0;
		vector<string> v;
		for(int i=0;i<l;i++)
		{
			string str2;
			for(int j=i;j<l;j++)
				str2+=str[j],v.push_back(str2);
			
		}
		for(int i=0;i<(int)v.size();i++)
		{
			//cout<<v[i]<<"\n";
			for(int j=0;j<(int)v[i].size();j++)
			{
				int cnt=0;
				while(j<(int)v[i].size() and !isvowel(v[i][j]))
					j++,cnt++;
				if(cnt>=n)
				{
					ans++;
					break;
				}
				if(cnt>0)
					j--;
			}
		}
		printf("Case #%d: %d\n",nak,ans);
		nak++;
	}
    scanf("\n");
    return 0;
}

//Nakul © Copyright 2012 - All Rights Reserved

