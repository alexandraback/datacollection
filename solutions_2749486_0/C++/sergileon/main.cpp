#include <queue>
#include <iostream>
#include <set>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <string>
#include <sstream>
using namespace std;
int n;
string s;


int main()
{
	//#ifdef DEBUG
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
//#endif
	int t;
	scanf("%d",&t);
	
	for ( int i =  0 ; i < t; i ++)
	{
		string ans="";
		int x , y;
		vector<int> X,Y;
		scanf("%d%d",&x,&y);
		int t= 1;
			int pos = 0;
			while ( pos!=x)
			{
				if ( pos + t==x)
				{
					pos+=t;
					t++;
					X.push_back(1);
				}
				else
					if ( pos - t ==x)
					{
						pos-=t;
					t++;
					X.push_back(-1);
					}
					else if ( pos + t < x)
					{
						pos+=t;
					t++;
					X.push_back(1);
					}
					else
					{
						pos-=t;
					t++;
					X.push_back(-1);
					}
			}
		pos = 0;
		while ( pos!=y)
			{
				if ( pos + t==y)
				{
					pos+=t;
					t++;
					Y.push_back(1);
				}
				else
					if ( pos - t ==y)
					{
						pos-=t;
					t++;
					Y.push_back(-1);
					}
					else if ( pos + t < y)
					{
						pos+=t;
					t++;
					Y.push_back(1);
					}
					else
					{
						pos-=t;
					t++;
					Y.push_back(-1);
					}
			}
		for ( int i = 0 ; i < X.size() ; i ++)
		{
			if ( X[i]>0)
			{
				ans+='E';
			}
			else
				ans+='W';
		}
		for ( int i = 0 ; i < Y.size() ; i ++)
		{
			if ( Y[i]>0)
			{
				ans+='N';
			}
			else
				ans+='S';
		}
		printf("Case #%d: ",i+1);
		cout << ans << endl; 
	}
	return 0;
}
