#include<iostream>	
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<cassert>
using namespace std;

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


int mov(int n,int k,int l)
{
	int t=k;
	k=pow(10,k);
	int x=n%k;
	n=n/k;
	x=x*(int)pow(10,l-t);
	return (x+n);
}



int main()
{
	int tc,i,n,j,k,l,count,a,b,res;
	inp(tc);
	set< pair<int,int> > s;
	for(i=0;i<tc;i++)
	{
		inp(a);inp(b);
		count=0;
		for(j=a;j<=b;j++)
		{
			n=j;
			l=log10(n)+1;
			for(k=1;k<l;k++)
			{
				res=mov(n,k,l);
				if(res>=a && res<=b && res!=n && res>n)
				{
					if(s.find(make_pair(n,res))==s.end())
					{	
						count++;
						s.insert(make_pair(n,res));
					}
				}
			}
		}
		printf("Case #%d: %d\n",i+1,count);
		s.clear();
	}
	return 0;
}
