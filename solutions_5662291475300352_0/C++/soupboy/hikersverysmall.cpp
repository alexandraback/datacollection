#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits.h>
#include <string.h>
 
#define repx(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repx(i,0,n)
#define pb push_back
#define full(v)  v.begin(),v.end()
#define np next_permutation
#define VI vector<int>
#define VS vector<string>
#define VC vector<char>
#define VD vector<double>
#define VF vector<float>
#define SI set<int>
#define SC set<char>
#define SS set<string>
#define MII map<int,int>
#define MSI map<string,int>
#define MIS map<int,string>
#define MIC map<int,char>
#define MCI map<char,int>
#define LL long long
using namespace std;
	
int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};
 
int main()
{
	int test;
	cin>>test;
	repx(tc,1,test+1)
	{
		int n;
		int apos,atime ,bpos,btime;
		double aspeed , bspeed;
		int ret = 0;
		
		cin>>n;
		if(n==2)
		{
			int tmp;
			cin>>apos>>tmp>>atime;
			cin>>bpos>>tmp>>btime;
		}
		else if(n==1)
		{
			int tmp;
			cin>>apos>>tmp>>atime;
			bpos = apos;
			btime = atime+1;
			
		}
		cout<<"Case #"<<tc<<": ";
		if(n==1)
		{
			cout<<"0\n";
			continue;
		}
		aspeed = (double)(360.0)/((double)atime*1.0);
		bspeed = (double)(360.0)/((double)btime*1.0);

	//	cout<<apos<<" "<<atime<<" "<<aspeed<<"\n";
	//	cout<<bpos<<" "<<btime<<" "<<bspeed<<"\n";

		if(apos == bpos)
		{
			apos += (atime/360);
			bpos += (btime/360);
		}


		double smallpos , smallspeed , bigpos,bigspeed;
		double smalltime, bigtime;
		if(apos < bpos)
		{
			smallpos = apos*1.0;
			smallspeed = aspeed;
			bigpos = bpos*1.0;
			bigspeed = bspeed;
		}
		else if(bpos < apos)
		{
			smallpos = bpos * 1.0;
			smallspeed = bspeed;
			
			bigpos = apos * 1.0;
			bigspeed = aspeed;
		}
		else
		{
			cout<<"0\n";
			continue;
		}

		smalltime  = (360.00-smallpos)/smallspeed;
		bigtime = (360.00-bigpos)/bigspeed;
		if(smalltime >= bigtime)
			ret = 1;
		else
			ret = 0;
	cout<<ret<<"\n";
	}
	return 0;
}