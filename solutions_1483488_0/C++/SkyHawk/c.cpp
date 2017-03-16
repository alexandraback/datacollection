//SkyHawk, CMC MSU

#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <math.h>

using namespace std;

#define FOR(i,n) for(int i = 0;i < n;++i)

int ar[15];

inline int getNdig(int n)
{
	int ans = 0;
	while(n)
	{
		++ans;
		n/=10;
	}
	return ans;
}

inline int moveR(int a,int n)
{
	a = (a%10)*ar[n-1] + a/10;
	return a;
}

int br[110];

int main(int argc, char** argv)
{
	int t;
	ar[0] = 1;
	FOR(i,8)
		ar[i+1] = ar[i]*10;
	cin >> t;
	FOR(count,t)
	{
		cout << "Case #" << count+1 << ": ";
		int a,b;
		cin >> a >> b;
		int k = getNdig(a);
		int ans = 0;
		for(int i = a;i<=b;++i)
		{
			int x = i;
			int s = 0;
			FOR(j,k)
			{
				x = moveR(x,k);
				if(a<=x && x<=b && x!=i)
				{
					bool b = true;
					FOR(p,s)
						if(br[p] == x)
						{
							b = false;
							break;
						}
					if(b)
					{	
						++ans;
						br[s++] = x;
					}
				}
			}
		}
		cout << ans/2 << endl;
	}
}
