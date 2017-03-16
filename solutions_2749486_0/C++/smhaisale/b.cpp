#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stdio.h>

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
	freopen("C:/Downloads/B-Sm.in", "r", stdin);
	freopen("C:/Downloads/B-Sm.out", "w+", stdout);
	int c;
	cin>>c;
	for(int t=0 ; t<c ; t++)
	{
		string moves[500];
		int index = -1; 
		int x, y;
		cin>>x>>y;
		int current_x=0,current_y=0;
		int steps = 1;
		
		if(mod(x)>mod(y))
		{
			if(x<0)
			steps=-1;
			while(((current_x+steps<x)&&(x>0))||((current_x+steps>x)&&(x<0)))
			{
				if(x>0)
				{
					current_x+=steps;
					moves[++index] = EAST;
					steps++;
				}
				else
				{
					current_x+=steps;
					moves[++index] = WEST;
					steps--;
				}
			}
		}
		else
		{
			if(y<0)
			steps=-1;
			while(((current_y+steps<y)&&(y>0))||((current_y+steps>y)&&(y<0)))
			{
				if(y>0)
				{
					current_y+=steps;
					moves[++index] = NORTH;
					steps++;
				}
				else
				{
					current_y+=steps;
					moves[++index] = SOUTH;
					steps--;
				}
			}
		}
		if(mod(x)>mod(y))
			//juggle"
			
			while(x!=current_x)
			{		
				if(steps>0)
				steps=steps*-1-1;
				else
				steps=steps*-1+1;
				current_x+=steps;
				if(steps>0)
				moves[++index] = EAST;
				else
				moves[++index] = WEST;
			}
		else
		{
			while(y!=current_y)
			{		
				if(steps>0)
				steps=steps*-1-1;
				else
				steps=steps*-1+1;
				current_y+=steps;
				if(steps>0)
				moves[++index] = NORTH;
				else
				moves[++index] = SOUTH;
			}
		}
		if(mod(x)<=mod(y))
		{
			//juggle
			if((x*steps<0))
			steps*=-1;
			
			while(x!=current_x)
			{		
				if(steps>0)
				steps=steps*-1-1;
				else
				steps=steps*-1+1;
				current_x+=steps;
				if(steps>0)
				moves[++index] = EAST;
				else
				moves[++index] = WEST;
			}
		}
		else
		{
			if((y*steps<0))
			steps*=-1;
			
			while(y!=current_y)
			{		
				if(steps>0)
				steps=steps*-1-1;
				else
				steps=steps*-1+1;
				current_y+=steps;
				if(steps>0)
				moves[++index] = NORTH;
				else
				moves[++index] = SOUTH;
			}
		}
		
		
		
		cout<<"Case #"<<t+1<<": ";
		for(int i=0 ; i<=index ; i++)
		cout<<moves[i];
		cout<<"\n";
	}
	
}
