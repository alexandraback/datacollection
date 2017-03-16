#include"iostream"
#include"stdio.h"
#include"vector"
#include"string.h"
#include"string"
#include"algorithm"
using namespace std;
int main()
	{
		int tc,t,x,y,i,j,n;
		string str;
		cin>>t;
		for(tc=1;tc<=t;tc++)
		{
			str.clear();
			cin>>x>>y;
			if(x>0)
			{
				while(x)
					{
						str.append("WE");
						x--;
					}
			}
			else
			{
				x=abs(x);
				while(x)
					{
						str.append("EW");
						x--;	
					}
			}
			if(y>0)
			{
				while(y)
					{
						str.append("SN");
						y--;
					}
			}
			else
			{
				y=abs(y);
				while(y)
					{
						str.append("NS");
						y--;	
					}
			}
			cout<<"Case #"<<tc<<": "<<str<<endl;
		}
		return 0;
	}