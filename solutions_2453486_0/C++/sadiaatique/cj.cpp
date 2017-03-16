#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

vector<string>v;

string s;

int main()
{
	//freopen("0.in","r",stdin);
	//freopen("/home/fahimzubaer/Desktop/A-small-attempt0.in","r",stdin);
	//freopen("/home/fahimzubaer/Desktop/0.out","w",stdout);
	
	int t;
	
	scanf("%d",&t);
	
	int a,b,c,d,e,x,y,z,o;
	
    for(int i=1;i<=t;i++)
    {
		getchar();
		
		v.clear();
		
		x=0;
		o=0;
		
		d=0;
		e=0;
		
		c=0;
		for(a=0;a<4;a++)
		{
			cin>>s;
			v.push_back(s);
	    }
		
		for(a=0;a<4;a++)
		{
			x=0;
			o=0;
			z=0;
			
			for(b=0;b<4;b++)
			{
				if(v[a][b]=='X') x++;
				if(v[a][b]=='O') o++;
				if(v[a][b]=='T') z++;
				if(v[a][b]=='.') c++;
			}
			if(x+z==4)
			{
				d=1;
			}
			if(o+z==4)
			{
				e=1;
			}
			
			x=0;
			o=0;
			z=0;
			
			for(b=0;b<4;b++)
			{
				if(v[b][a]=='X') x++;
				if(v[b][a]=='O') o++;
				if(v[b][a]=='T') z++;
			}
			if(x+z==4)
			{
				d=1;
			}
			if(o+z==4)
			{
				e=1;
			}
		}
		
		x=0; o=0; z=0;
		for(a=0;a<4;a++)
		{
			if(v[a][a]=='X') x++;
			if(v[a][a]=='O') o++;
			if(v[a][a]=='T') z++;
		}
		if(x+z==4) d=1;
		if(o+z==4) e=1;
		
		x=0; o=0; z=0;
		for(a=0;a<4;a++)
		{
			if(v[a][3-a]=='X') x++;
			if(v[a][3-a]=='O') o++;
			if(v[a][3-a]=='T') z++;
		}
		if(x+z==4) d=1;
		if(o+z==4) e=1;
		
		if(d)
		{
			printf("Case #%d: X won\n",i);
			continue;
		}
		if(e)
		{
			printf("Case #%d: O won\n",i);
			continue;
		}
		if(c)
		{
			printf("Case #%d: Game has not completed\n",i);
			continue;
		}
		else
		{
			printf("Case #%d: Draw\n",i);
		}
	}
	
	return 0;
	
}
