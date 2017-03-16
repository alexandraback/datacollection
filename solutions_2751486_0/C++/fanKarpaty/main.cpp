#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX(x,y) (x > y ? x : y)
#define MIN(x,y) (x > y ? y : x)
bool isV(char c)
{
	if(c=='a' || c== 'e' || c=='i' || c=='o' || c=='u')return true;
	return false;
}
int fl[1000005];
int last[1000005];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	cin>>T;
	int tt=T;
	
	while(T--)
	{
		string s;
		int n;
		cin>>s>>n;
		int res=0;
		memset(fl,0,sizeof(fl));
		memset(last,-1,sizeof(last));
		int count=0;
		for(int i=0;i<s.length();i++)
		{
			if(isV(s[i]))
			{
				count=0;
				if(i)last[i]=last[i-1];
			}
			else
			{
				count++;
				if(i)last[i]=last[i-1];
				if(count>=n)last[i]=i;
			}
		}
		for(int i=n-1;i<s.length();i++)
		{
			if(last[i]>=0  && last[i]-n>=-1)res+=last[i]-n+2;
		}
		cout<<"Case #"<<(tt-T)<<": "<<res<<endl;
		
	}
	return 0;
}