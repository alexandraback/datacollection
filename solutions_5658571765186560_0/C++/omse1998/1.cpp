#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <iomanip>
#include <vector>
#include <map>
#include <ctime>
#include <functional>
#include <utility>

#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double

using namespace std;

int t,x,r,c,i;

void print(int x)
{
	cout<<"Case #"<<i<<": "<<(x==1 ? "RICHARD" : "GABRIEL")<<endl;
	return;
}

int main()
{
	//ios_base::sync_with_stdio(false);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>t;
	for (i=1; i<=t; i++)
	{
		cin>>x>>r>>c;
		if (x==1)
		{
			print(0);
		}
		if (x==2)
		{
			print((r*c)%2);	
		}
		if (x==3)
		{
			if ((r*c)%3==0)
			{
				if (r*c==3)
					print(1);
				else
					print(0);
			}
			else
				print(1);
		}
		if (x==4)
		{
			if ((r*c)%4==0)
			{
				if (r*c>=12)
					print(0);
				else
					print(1);
			}
			else
				print(1);
		}
	}

	return 0;
}


    