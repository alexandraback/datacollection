#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<stack>
#include<cmath>
#include<iomanip>
#include<cstdlib>
#include<sstream>
#include<climits>
#include<cassert>
#include<time.h>
using namespace std;


int main()
{
	int i, j, k = 0, t, x, r, c, temp;
	
	cin>>t;
	
	while(t--)
	{
		cin>>x>>r>>c;
		k++;
		
		if(x == 1)
		{
			cout<<"Case #"<<k<<": "<<"GABRIEL\n";
			continue;
		}		
		
		if(x == 2)
		{
			if((r*c)%2 == 0)
			{
				cout<<"Case #"<<k<<": "<<"GABRIEL\n";
			}
			
			else
			{
				cout<<"Case #"<<k<<": "<<"RICHARD\n";
			}
			
			continue;
		}
		
		if(x == 3)
		{
			if((r*c)%3 !=0)
			{
				cout<<"Case #"<<k<<": "<<"RICHARD\n";
			}
			
			else
			{
				if(r != 3)
				{
					temp = r;
					r = c;
					c = temp;
				}
				
				if(c == 1)
				{
					cout<<"Case #"<<k<<": "<<"RICHARD\n";
				}
				
				else
				{
					cout<<"Case #"<<k<<": "<<"GABRIEL\n";
				}
			}
			
			continue;
		}
		
		if(x == 4)
		{
			if((r*c)%4 !=0)
			{
				cout<<"Case #"<<k<<": "<<"RICHARD\n";
			}
			
			else
			{
				if(r==2 && c ==2)
				{
					cout<<"Case #"<<k<<": "<<"RICHARD\n";
				}
				
				else
				{
					if(r != 4)
					{
						temp = r;
						r = c;
						c = temp;
					}		
					
					if(c<=2)
					{
						cout<<"Case #"<<k<<": "<<"RICHARD\n";
					}			
					
					else
					{
						cout<<"Case #"<<k<<": "<<"GABRIEL\n";
					}
				}
			}			
		}
	}
	
	return 0;
}
