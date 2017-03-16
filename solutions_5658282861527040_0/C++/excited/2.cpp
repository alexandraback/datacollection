#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<list>


using namespace std;	


#define PB push_back
#define X first
#define Y second
#define MOD 1000000009
#define MAX 100000
#define getcx getchar_unlocked


inline void inp( int &n )//fast input function
{
   n=0;
   int ch=getcx();int sign=1;
   while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}

   while(  ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
   n=n*sign;
}

int main()
{
	int t,a,b,k,p=1;
	inp(t);
	while(t--)
	{
		inp(a);inp(b);inp(k);
		int c=0;
		for(int i=0;i<a;i++)
			for(int j=0;j<b;j++)
				if((i & j) < k)
					c++;
		printf("Case #%d: %d\n",p++,c);
	}
	return 0;
}
