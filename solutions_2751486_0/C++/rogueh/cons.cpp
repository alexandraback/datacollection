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
	int cases, t, n, j, i, size,s, lj;
	string str;
	
	cin>>cases;
	for(t=1; t<=cases; t++)
	{
		cin>>str;
		cin>>n;
		size=str.size();
		s=0;
		j=lj=-1;
		for(i=0; i<size; i++)
		{
			switch(str[i])
			{
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
					j=-1;
					break;
				default:
					if(j==-1)
					{
						j=i;
					}
			}
			if(i-j+1==n && j!=-1)
			{
				if(lj==-1)
				{
					s+=(size-i)*(j+1);
				}
				else
				{
					s+=(size-i)*(j-lj);
				}
				lj=j;
				j++;
			}
		}
		cout<<"Case #"<<t<<": "<<s<<endl;
	}
	return 0;
}

