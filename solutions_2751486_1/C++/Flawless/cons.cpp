// Shashank Jain
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#define LL long long int
using namespace std;
int main()
{
	LL t,a,i,j,k,n,ans,c,last;
	cin>>t;
	a=1;
	string str;
	while(a<=t)
	{
        	ans=0;
        	cin>>str;
        	cin>>n;
		int arr[1000001]={0};
        	for(i=0;i<str.length();i++)
		{
            		if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
				arr[i]=0;
			else
			{
				if(i==0)
					arr[i]=1;
				else
					arr[i]=arr[i-1]+1;
			}	
		}
		ans=0;
		last=0;
		for(i=0;i<str.length();i++)
		{
			if(arr[i]>=n)
			{
				ans+=((str.length()-i)*(i-n-last+2));
				last=i-n+2;

			}
		}
		printf("Case #%lld: %lld\n",a,ans);
		a++;
	}
	return 0;
}
