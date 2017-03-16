//#pragma comment(linker,"/STACK:16777216") /*16Mb*/
//#pragma comment(linker,"/STACK:33554432") /*32Mb*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <cmath>
#include <list>
#include <iomanip>
#include <set>
#include <map>
using namespace std;

typedef  long long LL;
typedef  unsigned long long ULL;
typedef  long double LD;
typedef  pair<int,int> PII;

#define FOR(i,a,b) for(int (i)=(a);i<(b);++(i))
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i)) 
#define MP make_pair
#define MOD 1000000007
#define INF 1000000000
#define PB push_back

int main()
{
	//ios_base::sync_with_stdio(0);
	freopen("B-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	cin>>T;
	int x,y;
	FOR(tt,0,T)
	{
		cin>>x>>y;
		char l='W',r='E',u='N',d='S';
		int step=1;
		if(x<0)swap(l,r);
		if(y<0)swap(u,d);
		x=abs(x);
		y=abs(y);
		cout<<"Case #"<<tt+1<<": ";
		int px=0,py=0;
		while(px+step<=x)
		{
			px+=step;
			step++;
			cout<<r;
		}
		while(py+step<=y)
		{
			py+=step;
			step++;
			cout<<u;
		}
		while(px!=x)
		{
			cout<<l<<r;
			px++;
		}
		while(py!=y)
		{
			cout<<d<<u;
			py++;
		}
		cout<<'\n';
	}
	return 0;
}