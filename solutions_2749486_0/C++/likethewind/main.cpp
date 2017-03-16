#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<vector>
#include<string>

using namespace std;




int modify(int x)
{
	if(x<0)
	return x*-1;
	else
	return x;
}


const char NORTH='N',SOUTH='S',WEST='W',EAST='E';



int main()
{

    freopen("C:/stream/B-small-t.in", "r", stdin);
	freopen("C:/stream/B-small-t.out", "w", stdout);

	int T;
	cin>>T;
	for(int q=0 ; q<T ; q++)
	{
		string moved[500];
		int zi = -1;
		int x, y;
		cin>>x>>y;
		int curx=0,cury=0;
		int ss = 1;

		if(modify(x)>modify(y))
		{
			if(x<0)
			ss=-1;
			while(((curx+ss<x)&&(x>0))||((curx+ss>x)&&(x<0)))
			{
				if(x>0)
				{
					curx+=ss;
					moved[++zi] = EAST;
					ss++;
				}
				else
				{
					curx+=ss;
					moved[++zi] = WEST;
					ss--;
				}
			}
		}
		else
		{
			if(y<0)
			ss=-1;
			while(((cury+ss<y)&&(y>0))||((cury+ss>y)&&(y<0)))
			{
				if(y>0)
				{
					cury+=ss;
					moved[++zi] = NORTH;
					ss++;
				}
				else
				{
					cury+=ss;
					moved[++zi] = SOUTH;
					ss--;
				}
			}
		}
		if(modify(x)>modify(y))
			//juggle"

			while(x!=curx)
			{
				if(ss>0)
				ss=ss*-1-1;
				else
				ss=ss*-1+1;
				curx+=ss;
				if(ss>0)
				moved[++zi] = EAST;
				else
				moved[++zi] = WEST;
			}
		else
		{
			while(y!=cury)
			{
				if(ss>0)
				ss=ss*-1-1;
				else
				ss=ss*-1+1;
				cury+=ss;
				if(ss>0)
				moved[++zi] = NORTH;
				else
				moved[++zi] = SOUTH;
			}
		}


		if(modify(x)<=modify(y))
		{
			//juggle
			if((x*ss<0))
			ss*=-1;

			while(x!=curx)
			{
				if(ss>0)
				ss=ss*-1-1;
				else
				ss=ss*-1+1;
				curx+=ss;
				if(ss>0)
				moved[++zi] = EAST;
				else
				moved[++zi] = WEST;
			}
		}
		else
		{
			if((y*ss<0))
			ss*=-1;

			while(y!=cury)
			{
				if(ss>0)
				ss=ss*-1-1;
				else
				ss=ss*-1+1;
				cury+=ss;
				if(ss>0)
				moved[++zi] = NORTH;
				else
				moved[++zi] = SOUTH;
			}
		}



		cout<<"Case #"<<q+1<<": ";
		for(int i=0 ; i<=zi ; i++)
		cout<<moved[i];
		cout<<"\n";
	}


// edof

}
