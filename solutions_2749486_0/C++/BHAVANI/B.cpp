#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
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

using namespace std;
#define all(c) c.begin(), c.end() 
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define sz size()
//#define tr(container, it) \
#define gcd __gcd
#define oo  (int)13e7
string moves= "NSEW";
string makeMove(bool X,int val)
{
	int offset = X?2:0;
	if ( val < 0 )
	{
	  int curr = 0;
	 string ret;
	  while ( curr != val )
	  {
		curr--;
		ret.pb(moves[offset]);
		ret.pb(moves[offset+1]); 
          }
	return ret;
	}
	else
	{
	int curr = 0;
         string ret;
          while ( curr != val )
          {
                curr++;
                ret.pb(moves[offset+1]);
                ret.pb(moves[offset]);
          }
		return ret;
	}
} 
int main()
{
	int T;
	cin >> T;
	for ( int tt = 0 ; tt < T; tt++ )
	{
		int X,Y;
		cin >> X>> Y;
		string ret = makeMove(true,X);
		ret += makeMove(false,Y);
		cout << "Case #"<<(tt+1)<<": "<<ret<<endl;
	}
}
