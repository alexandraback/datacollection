/*    SHUBHAM SINHA    */



#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <math.h>

#define ll long long int
#define maxN 100000
#define maxVal 100000000
#define minVal -100000000
#define mod 1000000007LL

#define gcd(a,b) __gcd(a,b)

using namespace std;

string a,b;
int n;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef LOCAL_SYS
        freopen("B-large.in","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int t,i,j,z;
    cin>>t;
    for(i=1;i<=t;i++)
    {
    	cin>>a>>b;
    	n=a.length();
    	z=0;
		for(j=0;j<n;j++)
		{
			if(z==0)
			{
				if(a[j]=='?'&&b[j]=='?')
				{
					a[j]='0';
					b[j]='0';
				}
				else
				{
					if(a[j]!='?'&&b[j]!='?')
					{
						if((a[j]-'0')<(b[j]-'0'))
							z=1;
						else if((a[j]-'0')>(b[j]-'0'))
							z=2;
					}
					else
					{
						if(a[j]!='?')
							b[j]=a[j];
						else
							a[j]=b[j];
					}
				}
			}
			else if(z==1)
			{
				if(a[j]=='?')
					a[j]='9';
				if(b[j]=='?')
					b[j]='0';
			}
			else
			{
				if(a[j]=='?')
					a[j]='0';
				if(b[j]=='?')
					b[j]='9';
			}
		}
		cout<<"Case #"<<i<<": "<<a<<" "<<b<<"\n";
    }
    return 0;
}