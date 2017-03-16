#include <iostream>
#include <cstdio>
#include <string>
#include <stdlib.h>
using namespace std;

int main()
{
	freopen("pogo.in","r",stdin);
	int t,a;
	cin>>t;
	for(a = 1;a <= t;a++)
	{
		string moves = "";
		int x,y,p = 0,q = 0,turn  = 1;
		cin>>x>>y;
		while(p != x || q != y)
		{
			if((abs(x) > abs(y) && q != y) || p == x)
			{
				if(y > 0)
				{
					if(q + turn <= y)
					{
						q += turn;
						moves += "N";
					}
					else
					{
						q -=  turn;
						moves += "S";
					}
				}
				else
				{
					if(q - turn >= y)
					{
						q -= turn;
						moves += "S";
					}
					else
					{
						q +=  turn;
						moves += "N";
					}
				}
				turn++;
			}
			else
			{
				if(x > 0)
				{
					if(p + turn <= x)
					{
						p += turn;
						moves += "E";
					}
					else
					{
						p -=  turn;
						moves += "W";
					}
				}
				else
				{
					if(p - turn >= x)
					{
						p -= turn;
						moves += "W";
					}
					else
					{
						p +=  turn;
						moves += "E";
					}
				}
				turn++;
			}
		}
		cout<<"Case #"<<a<<": "<<moves<<endl;
	}
}

