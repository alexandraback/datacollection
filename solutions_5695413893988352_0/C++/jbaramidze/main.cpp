#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stack>
#include <string.h>
#include <climits>
#include <limits>

using namespace std;

typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;

#define FOR(i, a, b) for(int i=a; i<b; i++)
#define FORE(i, a, b) for(int i=a; i<=b; i++)
#define ll long long
#define pii pair<ll, ll>
#define mp make_pair
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define ceil(a, b) ((a)/(b) + ((a)%(b)!=0))
#define square(a) ((a)*(a))
#define PI 3.14159265359
#define INF 1000000000000LL;
#define mod 1000000009LL

int diff;
int gjammers;
int gcoders;

string sgcoders;
string sgjammers;

void start (string coders, string jammers)
{
	FOR(i, 0, coders.size()) if(coders[i] == '?') 
	{
		FORE(j, 0, 9)
		{
		  string coders2 = coders;
		  coders2[i] = j + '0';

		  start(coders2, jammers);
		}
		return;
	}


	FOR(i, 0, jammers.size()) if(jammers[i] == '?') 
	{
		FORE(j, 0, 9)
		{
		  string jammers2 = jammers;
		  jammers2[i] = j + '0';

		  start(coders, jammers2);
		}
		return;
	}

	int cods = atoi(coders.c_str());
	int jams = atoi(jammers.c_str());

	//printf("case %d and %d, diff = %d, abs = %d, comparison=%d\n", 
	//	cods, jams, diff, abs(cods - jams), abs(cods - jams) < diff);

	if(diff == -1 || abs(cods - jams) < diff)
	{
      diff = abs(cods - jams);
      gcoders = cods;
      gjammers = jams;

      sgcoders = coders;
      sgjammers = jammers;
  //    printf("entering 1\n");
	}
	else if (diff == abs(cods - jams) && cods < gcoders)
	{
      gcoders = cods;
      gjammers = jams;
      sgcoders = coders;
      sgjammers = jammers;
	}
	else if (diff == abs(cods - jams) && gcoders == cods && jams < gjammers)
	{
		gjammers = jams;
      sgcoders = coders;
      sgjammers = jammers;
	}
}

int main(int argc, char **argv) {
  
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);

  int T;
  cin >> T;


  FOR(t, 0, T)
  {
  diff = -1;
  gjammers = 0;
  gcoders = 0;
    string coders, jammers;
    cin >> coders >> jammers;
    start(coders, jammers);
    printf("Case #%d: %s %s\n", t+1, sgcoders.c_str(), sgjammers.c_str());	
  }
}
