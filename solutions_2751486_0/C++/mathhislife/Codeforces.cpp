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
	for(int yyy=1; yyy<=t; yyy++)
	{
		string str;
		int n;
		cin>>str;
		cin>>n;
		int ans=0;
		for(int i=0; i<str.size(); i++)
		{
			for(int j=i; j<str.size(); j++)
			{
				string buf;
				buf.clear();
				for(int k=i; k<=j; k++)
				{
					buf.push_back(str[k]);
				}
				int g=0;
				int mm=0;
				for(int k=0; k<buf.size(); k++)
				{
					if(buf[k]!='a' && buf[k]!='e' && buf[k]!='i' && buf[k]!='o' && buf[k]!='u')
					{
						g++;
					}
					else
					{
						if(g>mm)
						{
							mm=g;
							g=0;
						}
					}
				}
				if(g>mm)
				{
					mm=g;
					g=0;
				}
				if(mm>=n)
				{
					ans++;
				}
			}
		}
		cout<<"Case #"<<yyy<<": "<<ans<<endl;
	}

	return 0;
}