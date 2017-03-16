#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <ctime>
#include <math.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <complex>
using namespace std;

#define X first
#define Y second
#define pb push_back
#define mp make_pair

const double PI = acos(-1.0);
const int INF = 1000000000;
long long MOD = 1000000007;
const int M = INF;
const double RRR = 180.0/PI;


typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;

vector<vector<int> > g;
vector<int> used;




int main()
{
	//double TIME_START = clock();
	#ifndef ONLINE_JUDGE
	freopen("INPUT.TXT","r",stdin);
	freopen("OUTPUT.TXT","w",stdout);
	#endif
	int t;
	cin>>t;
	for(int test=1; test<=t; test++)
	{
		cout<<"Case #"<<test<<": ";
		int x,y;
		cin>>x>>y;
		int n=0;
		while(1)
		{
			if(n*n+n>=abs(2*x))
			{
				break;
			}
			n++;
		}
		if(n*n+n==abs(2*x))
		{
			if(x>0)
			{
				for(int i=0; i<n; i++)
				{
					cout<<"E";
				}
			}
			else
			{
				for(int i=0; i<n; i++)
				{
					cout<<"W";
				}
			}
		}
		else
		{
			n--;
			if(x>0)
			{
				for(int i=0; i<n; i++)
				{
					cout<<"E";
				}
			}
			else
			{
				for(int i=0; i<n; i++)
				{
					cout<<"W";
				}
			}
			int zal=abs(x)-(n*n+n)/2;
			if(x>0)
			{
				for(int i=0; i<zal; i++)
				{
					cout<<"WE";
					n+=2;
				}
			}
			else
			{
				for(int i=0; i<zal; i++)
				{
					cout<<"EW";
					n+=2;
				}
			}
		}
		n++;
		int p=n;
		int sum=0;
		while(1)
		{
			sum+=n;
			if(sum>=abs(y))
			{
				break;
			}
			n++;
		}
		if(sum==abs(y))
		{
			if(y>0)
			{
				for(int i=0; i<n-p+1; i++)
				{
					cout<<"N";
				}
			}
			else
			{
				for(int i=0; i<n-p+1; i++)
				{
					cout<<"S";
				}
			}
		}
		else
		{
			n--;
			if(y>0)
			{
				for(int i=0; i<n-p+1; i++)
				{
					cout<<"N";
				}
			}
			else
			{
				for(int i=0; i<n-p+1; i++)
				{
					cout<<"S";
				}
			}
		}
		int zal=abs(y)-((n+p)*(n-p+1))/2;
		if(y>0)
		{
			for(int i=0; i<zal; i++)
			{
				cout<<"SN";
			}
		}
		else
		{
			for(int i=0; i<zal; i++)
			{
				cout<<"NS";
			}
		}
		cout<<endl;
	}

	return 0;
}