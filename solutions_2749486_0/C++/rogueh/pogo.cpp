/**
Coded by:-   Rogue
**/
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <sstream>

#define LL long long int
#define SF second.first
#define SS second.second
#define mp(a,b) make_pair((a),(b))

using namespace std;

int main()
{
	int cases, t, tx, ty, jm,x,y;
	string str;
	cin>>cases;
	for(t=1; t<=cases; t++)
	{
		cin>>x>>y;
		tx=ty=0;
		jm=1;
		str="";
		if(x<0)
		{
			while(tx!=x)
			{
				if(tx-jm<x)
				{
					tx+=jm;
					str+="E";
				}
				else
				{
					tx-=jm;
					str+="W";
				}
				jm++;
			}
		}
		else if(x>0)
		{
			while(tx!=x)
			{
				if(tx+jm>x)
				{
					tx-=jm;
					str+="W";
				}
				else
				{
					tx+=jm;
					str+="E";
				}
				jm++;
			}
		}
		if(y<0)
		{
			while(ty!=y)
			{
				if(ty-jm<y)
				{
					ty+=jm;
					str+="N";
				}
				else
				{
					ty-=jm;
					str+="S";
				}
				jm++;
			}
		}
		else if(y>0)
		{
			while(ty!=y)
			{
				if(ty+jm>y)
				{
					ty-=jm;
					str+="S";
				}
				else
				{
					ty+=jm;
					str+="N";
				}
				jm++;
			}
		}
		cout<<"Case #"<<t<<": "<<str<<endl;
	}
	
	return 0;
}

