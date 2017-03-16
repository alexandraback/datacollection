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
	int t,a,i,j,k,n,ans,c;
	cin>>t;
	a=1;
	string s;
	while(a<=t)
	{
        	ans=0;
        	cin>>s;
        	cin>>n;
        	for(i=0;i<s.length();i++)
		{
            		for(j=i+n;j<=s.length();j++)
			{
                		c=0;
                		for(k=i;k<j;k++)
				{
               				if(s[k]=='a' || s[k]=='e' || s[k]=='i'|| s[k]=='o' || s[k]=='u')
                        			c=0;
                    			else
                        			c++;
                    			if(c>=n)
					{
                        			ans++;
                        			break;
                    			}
                		}
			}
		}
		printf("Case #%d: %d\n",a,ans);
		a++;
	}
	return 0;
}
