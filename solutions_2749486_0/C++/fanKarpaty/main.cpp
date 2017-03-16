#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX(x,y) (x > y ? x : y)
#define MIN(x,y) (x > y ? y : x)

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	cin>>T;
	int tt=T;
	
	while(T--)
	{
		int X,Y;
		cin>>X>>Y;
		string res="";
		int x=0, y=0;
		int i=0;
		while(x!=X)
		{
			i++;
			if(x<X)
				{
					res+="WE";
					x++;
			}
			else
			{
				res+="EW";
				x--;
			}
		}
		while(y!=Y)
		{
			i++;
			if(y<Y)
				{
					res+="SN";
					y++;
			}
			else
			{
				res+="NS";
				y--;
			}
		}
		cout<<"Case #"<<(tt-T)<<": "<<res<<endl;
		
	}
	return 0;
}