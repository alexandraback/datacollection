#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <stack>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
#define FOR(x,b,e) for(long long x=b;x<e;x++)
#define FORD (x,b,e) for(int x=b-1;x>=e;x--)
typedef long long LL;
void wczytaj(LL *z)
{
		register char c=0;
		while(c<33) c=getc_unlocked(stdin);
		(*z)=0;
		while(c>32) {(*z)=(*z) *10LL+(c-'0');c=getc_unlocked(stdin);}
}
using namespace std;
struct ulamek{
	LL licznik;
	LL mianownik;
};
	LL tab[1100000];

int main()
{
	queue<LL> Q;
	LL t,a,b,x,y,step=1;
	cin>>t;
	FOR(i,0,t)
	{
		x=0;y=0;
		step=1;
		cin>>a>>b;
		while(true)
		{
			if(x==a && y==b)
			{
				break;
			}
			if(x!=a)
			{
				if(x>a)
				{
					if(x-step >=a){x=x-step;Q.push(int('W'));}
					else {x=x+step;Q.push(int('E'));}
				}
				else if(x<a) 
				{
					if(x+step<=a) {x=x+step;Q.push('E');}
					else {x=x-step;Q.push('W');}
				}
			}
			else if(y!=b)
			{
				if(y>b)
				{
					if(y-step >= b){y=y-step;Q.push('S');}
					else {y=y+step;Q.push('N');}
				}
				else if (y<b) 
				{
					if(y+step<=b) {y=y+step;Q.push('N');}
					else {y=y-step;Q.push('S');}
				}
			}
			step++;
		}
		cout<<"Case #"<<i+1<<": ";
		while(!Q.empty())
		{
			cout<<(char)Q.front();
			Q.pop();
		}
		cout<<endl;
		
	}
    return 0;
}
     
