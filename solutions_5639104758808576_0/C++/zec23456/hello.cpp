#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include <iomanip>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<stack>
#include<cstring>
#include<map>
#include<set>
using namespace std;
#define MOD 1000000007
int main()
{
	int t,T;
	int re,x;
	string s;
	int i,n;
	freopen("A-small-attempt0.in","rt",stdin);
	freopen("A.out","wt",stdout);
	cin>>T;
	for(t=1;t<=T;t++)
	{
		cin>>n;
		cin>>s;
		re=0;
		x=s[0]-'0';
		for(i=1;i<=n;i++)
		{
			if(x>=i)
				x+=s[i]-'0';
			else
			{
				re+=i-x;
				x=i;
				x+=s[i]-'0';
			}
		}
		cout<<"Case #"<<t<<": "<<re<<endl;
	}
    return 0;
}