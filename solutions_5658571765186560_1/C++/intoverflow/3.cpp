#include <iostream>
#include <stdio.h>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
int t;
cin>>t;

	for (int i=0;i<t;i++)
	{
	int x,r,c;
	cin>>x>>r>>c;
	bool result=1;
		
		if(x>=7) result=0;
		else if (x>c && x>r) result=0;
		else if (r*c%x!=0) result=0;
		else if ((x+1)/2 > min(r,c))  result=0;
		else if (x>=1 && x<=3) result=1;
		else if (x==4) result=min(r,c)>2;
		else if (x==5) result=!(min(r, c) == 3 && max(r,c) == 5);
		else if (x==6) result=min(r,c)>3;
		if (result)
		{
		cout<<"Case #"<<i+1<<": "<<"Gabriel\n";
		}
		else
		{
		cout<<"Case #"<<i+1<<": "<<"Richard\n";
		}
	}
	
}