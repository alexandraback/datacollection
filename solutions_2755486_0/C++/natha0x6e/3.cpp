#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <list>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <list>

typedef long long ll;
typedef double dub;

using namespace std;


const int WALLSIZE = 1000000;
const int WALLMID = WALLSIZE / 2;
int WALL[WALLSIZE];
int LASTWALL[WALLSIZE];

struct Tribe 
{
	int d;
	int n;
	int w;
	int e;
	int s;
	int dd;
	int dp;
	int ds;
	
	int nextAttack;
};

class COMP
{
  bool reverse;
public:
  COMP(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const Tribe& lhs, const Tribe&rhs) const
  {
    if (reverse) return (lhs.d>rhs.d);
    else return (lhs.d<rhs.d);
  }
};

void runTest()
{
	cerr << "TEST" << endl;
	int numTribes;
	int result = 0;
	
	priority_queue<Tribe, vector<Tribe>, COMP> tribes;
	
	cin >> numTribes;
	
	for(int i = 0;i < numTribes;i++)
	{
		Tribe t;
		cin  >> t.d >> t.n >> t.w >> t.e >> t.s >> t.dd >> t.dp >> t.ds;
		tribes.push(t);
	}
	
	//reset wall
	//cerr << "RESET WALL" << endl;
	for(int i = 0;i < WALLSIZE;i++)
	{
		WALL[i] = 0;
	}
	//cerr << "END RESET WALL" << endl;
	
	int * wall = WALL;
	int * lastWall = LASTWALL;
	
	int day = 0;
	
	while(tribes.size() > 0)
	{
		Tribe t = tribes.top();
		tribes.pop();
		
		if(day != t.d)
		{
			for(int i = 0;i < WALLSIZE;i++)
			{
				lastWall[i] = wall[i];
			}
		}
		
		bool success = false;
		for(int i = t.w;i <= t.e;i++)
		{
			if(lastWall[WALLMID+i] < t.s) {
				success = true;
			}
			if(wall[WALLMID+i] < t.s)
			{
				wall[WALLMID+i] = t.s;
			}
		}
		if(success)
		{
			result++;
		}
		
		
		day = t.d;
		t.d += t.dd;
		t.n--;
		t.w += t.dp;
		t.e += t.dp;
		t.s += t.ds;
		if(t.n > 0)
		{
			tribes.push(t);
		}
	}
	
	
	
	cout << result << endl;
}


int main(int argc, const char * argv[])
{
	(void) argc;
	(void) argv;
	int numTests;
	cin >> numTests;
	srand(time(NULL));
	
	for(int i =0;i < numTests;i++)
	{
		cout << "Case #" << i + 1 << ": ";
		runTest();
	}
}
