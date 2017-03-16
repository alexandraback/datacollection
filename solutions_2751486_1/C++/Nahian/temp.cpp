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

#define MAX 1000100
#define ll long long
int aray[MAX];

int main()
{
	//freopen("A-large.in","r",stdin);
	//freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	string str;
	int n;
	for(int cas=0;cas<t;cas++)
	{
		cin>>str>>n;
		aray[str.length()]=0;
		for(int i=str.length()-1;i>=0;i--)
		{
			if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
				aray[i]=0;
			else
				aray[i]=aray[i+1]+1;
		}
		int pre=0;
		ll ans=0;
		for(int i=0;i<str.length();i++)
		{
			if(aray[i]>=n)
			{
				ans+=(pre+1)*(str.length()-i-n+1);
				pre=0;
			}
			else
			{
				pre++;
			}
		}
		printf("Case #%d: ",cas+1);
		cout<<ans<<endl;
	}
    return 0;
}
