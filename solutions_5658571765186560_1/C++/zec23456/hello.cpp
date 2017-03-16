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
	int x,r,c;
	int temp;
	bool flag;
	freopen("D-large.in","rt",stdin);
	freopen("D.out","wt",stdout);
	cin>>T;
	for(t=1;t<=T;t++)
	{
		flag=true;
		cin>>x>>r>>c;
		if((r*c)%x!=0)
			flag=false;
		if(r<c)
		{
			temp=c;
			c=r;
			r=temp;
		}
		if(x>r)
			flag=false;
		if(x>=c+2)
			flag=false;
		if((x+1)/2>r)
			flag=false;
		if(flag)
			cout<<"Case #"<<t<<": "<<"GABRIEL"<<endl;
		else
			cout<<"Case #"<<t<<": "<<"RICHARD"<<endl;
	}
    return 0;
}