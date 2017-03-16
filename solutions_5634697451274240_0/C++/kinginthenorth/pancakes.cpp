#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	for(int cno=1;cno<=t;cno++)
	{
		char s[101];
		cin>>s;
		int i=1,count=0;
		while(s[i])
		{
			if(s[i]!=s[i-1])
				count++;
			i++;
		}
		if(s[i-1]=='-')
			count++;
		cout<<"Case #"<<cno<<": "<<count<<endl;
	}
	return 0;
}
