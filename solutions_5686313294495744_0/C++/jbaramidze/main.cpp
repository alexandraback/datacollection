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


int main(int argc, char **argv) {
  
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);

  int T;
  cin >> T;


  FOR(t, 0, T)
  {
  	int N;
  	cin >> N;

  	vector<pair<string, string> > A;
  	string t1, t2;

    FOR(i, 0, N)
    {
    	cin >> t1 >> t2;
    	A.pb(mp(t1, t2));
    }

  	vector<pair<string, string> > B;

  	vi marked(67, 0);

  	FOR(i, 0, A.size())
  	{
      bool f = false;
      FOR(j, 0, A.size())
        if (i != j && A[i].first == A[j].first) f = true;

      if(!f)
      {
      	B.pb(A[i]);
      	marked[i] = 1;
    //  	printf("Marking %d since not found1.\n", i);
      }
  	}

  	FOR(i, 0, A.size())
  	{
      if (marked[i]) continue;

      bool f = false;
      FOR(j, 0, A.size())
        if (i != j && A[i].second == A[j].second) f = true;

      if(!f)
      {
      	B.pb(A[i]);
      	marked[i] = 1;
      //	printf("Marking %d since not found2.\n", i);
      }
  	}
    int i = 0;
  	for(vector<pair<string, string> >::iterator it = A.begin(); it != A.end();)
  	{
  		if (marked[i])
  		{
  			A.erase(it);
  		}
  		else
  		{
  			it++;
  		}
  		i++;
  	}
    printf("Case #%d: %lu\n", t+1, A.size());
  }
}
