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
#define tr(container, it) \
      for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define oo  (int)13e7

int main()
{
	int T;
	cin >> T;
	for ( int tt = 0 ; tt < T; tt++ )
	{
		int N;
		// N
		int di, ni, wi, ei, si, delta_di, delta_pi, delta_si;
		cin >> N;
		set <pair < int, pair <pair<int,int> , int > > > s1; // day, w,e,s
                //pair < pair <int,int>, int> s1[676060 
		REP(i,N)
		{
		  cin >> di>> ni>> wi>> ei>> si>> delta_di>> delta_pi>> delta_si;
		  int iDay = di;
		  int iW = wi;
		  int iE = ei;
                  int iS = si;  
		  REP(j,ni)
		  {
			s1.insert(make_pair(iDay,make_pair( make_pair(iW,iE),iS)));
			iS += delta_si;
			iW += delta_pi;
			iE += delta_pi;
			iDay += delta_di;
		  }
		   
		}
		int currWalls[1000];
		memset(currWalls,0,sizeof(currWalls));
		int ret = 0;
		set <int> mp;
		int *wallsP = currWalls;
		int prevWalls[1000];
		memset(prevWalls,0,sizeof(prevWalls)); 
		tr(s1,it)
		{
			pair < int, pair <pair<int,int> , int > > p1 = (*it);
			int days = p1.first;
			int wend = p1.second.first.first+500;
			int eend = p1.second.first.second+500;
			int stre = p1.second.second;
			//cout << days<< " "<<wend<< " "<<eend << " "<<stre <<endl;
					
			
			if ( mp.count(days) == 0)
			{
				REP(i,1000)
				{
					currWalls[i] = prevWalls[i];
				}
			}
	FOR(i,wend,eend)
			{
				if ( currWalls[i] < stre)
				{
					ret++;
					break;
				}
			}

			FOR(i,wend,eend)
				{
					prevWalls[i] = max(prevWalls[i],stre); 
				}
		
			mp.insert(days);
		}
		
		cout << "Case #"<<(tt+1)<<": "<<ret<<endl;
	}
}
