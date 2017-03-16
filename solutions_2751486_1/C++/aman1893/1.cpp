#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define s(n) scanf("%d",&n)
#define p(n) printf("%d",n)
#define ll long long
#define ld long double
#define D (double)
#define LD (long double)
int fun(char a)
{
    if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u')return 0;
    return 1;
}
int arr[1000001];
int main()
{
	freopen("ip.in","r",stdin);
	freopen("op.in","w",stdout);
	int t,c=0;cin>>t;
	while(t--)
	{
		c++;
		int n;
		string str;
		cin>>str;
		cin>>n;
		for(int i=0;i<str.size();i++){arr[i]=0;}
		for(int i=0;i<str.size();i++)
		{
		    if(!fun(str[i]))break;
		    else arr[0]++;
		}
		for(int i=1;i<str.size();i++)
		{
		    if(arr[i-1]>=1)
		    {
		        arr[i]=arr[i-1]-1;
		    }
		    else
		    {
		        for(int j=i;j<str.size();j++)
		        {
		            if(!fun(str[j]))break;
		            else arr[i]++;
		        }
		    }

		}
		long long  ans=0;int left=0;
		int right=str.size()-n;
		for(int i=0;i<str.size();i++)
		{
		    if(arr[i]>=n){ans+=(1+((long long)left*right)+left+right);left=0;}
		    else left++;
		    right--;

		}












		printf("Case #%d: ",c);
		cout<<ans<<endl;
	}
}
