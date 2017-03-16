#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
int mod(int x)
{
	if(x<0)
	return x*-1;
	else
	return x;
}
const char NORTH='N',SOUTH='S',WEST='W',EAST='E';
int main()
{
	int cases;
	cin>>cases;
	for(int q=0 ; q<cases ; q++)
	{
		string movements[500];
		int index = -1; 
		int x, y;
		cin>>x>>y;
		int currx=0,curry=0;
		int steps = 1;
		
		if(mod(x)>mod(y))
		{
			if(x<0)
			steps=-1;
			while(((currx+steps<x)&&(x>0))||((currx+steps>x)&&(x<0)))
			{
				if(x>0)
				{
					currx+=steps;
					movements[++index] = EAST;
					steps++;
				}
				else
				{
					currx+=steps;
					movements[++index] = WEST;
					steps--;
				}
			}
		}
		else
		{
			if(y<0)
			steps=-1;
			while(((curry+steps<y)&&(y>0))||((curry+steps>y)&&(y<0)))
			{
				if(y>0)
				{
					curry+=steps;
					movements[++index] = NORTH;
					steps++;
				}
				else
				{
					curry+=steps;
					movements[++index] = SOUTH;
					steps--;
				}
			}
		}
		if(mod(x)>mod(y))
			//juggle"
			
			while(x!=currx)
			{		
				if(steps>0)
				steps=steps*-1-1;
				else
				steps=steps*-1+1;
				currx+=steps;
				if(steps>0)
				movements[++index] = EAST;
				else
				movements[++index] = WEST;
			}
		else
		{
			while(y!=curry)
			{		
				if(steps>0)
				steps=steps*-1-1;
				else
				steps=steps*-1+1;
				curry+=steps;
				if(steps>0)
				movements[++index] = NORTH;
				else
				movements[++index] = SOUTH;
			}
		}
		if(mod(x)<=mod(y))
		{
			//juggle
			if((x*steps<0))
			steps*=-1;
			
			while(x!=currx)
			{		
				if(steps>0)
				steps=steps*-1-1;
				else
				steps=steps*-1+1;
				currx+=steps;
				if(steps>0)
				movements[++index] = EAST;
				else
				movements[++index] = WEST;
			}
		}
		else
		{
			if((y*steps<0))
			steps*=-1;
			
			while(y!=curry)
			{		
				if(steps>0)
				steps=steps*-1-1;
				else
				steps=steps*-1+1;
				curry+=steps;
				if(steps>0)
				movements[++index] = NORTH;
				else
				movements[++index] = SOUTH;
			}
		}
		
		
		
		cout<<"Case #"<<q+1<<": ";
		for(int i=0 ; i<=index ; i++)
		cout<<movements[i];
		cout<<"\n";
	}
	
}
