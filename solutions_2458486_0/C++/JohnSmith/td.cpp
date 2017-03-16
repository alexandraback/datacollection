//
// Qualification round 2013  problem D
//
// Usually built with g++ 4.4.5 on Linux
//
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <unordered_set>
#include <gmpxx.h>

#include <cstdlib>
#include <math.h>

using namespace std;

typedef unsigned long long bigint;

set<vector<unsigned int> >failures;

struct chest
{
     unsigned int lock_type;
     unordered_multiset<unsigned int> keys;
};

vector<unsigned int> search( unsigned int depth,
			     unsigned int target,
			     unordered_multiset<unsigned int> keys,
			     vector<chest> &v,
			     vector<unsigned int> flags )
{
     if (keys.find( v.at(target).lock_type) == keys.end())
     {
	  vector<unsigned int> a;
	  return a;
     }

     flags.at(target) = 1;
     if (failures.find(flags) != failures.end())
     {
	  vector<unsigned int> a;
	  return a;
     }

     keys.erase( keys.find(v.at(target).lock_type) );

     keys.insert( v.at(target).keys.begin(), v.at(target).keys.end());
     
     bool searched = false;
     for (auto i=0u; i<v.size(); i++)
     {
	  if (flags.at(i) == 0)
	  {
	       searched = true;
	       auto a = search( depth+1, i, keys, v, flags );
	       if (a.size())
	       {
		    vector<unsigned int> b;
		    b.push_back(target);
		    for (auto x : a) b.push_back(x);
		    
		    return b;
	       }
	  }
     }

     vector<unsigned int> a;
     if (searched)
     {
	  failures.insert(flags);
     }
     else
     {
	  a.push_back(target);
     }
     return a;
}

vector<unsigned int> solve( unordered_multiset<unsigned int> keys,
			    vector<chest> v )
{
     failures.clear();

     vector<unsigned int> flags(v.size());
     for (auto &x: flags) x=0;

     for (auto t=0u; t<v.size(); t++)
     {
	  auto a = search( 0, t, keys, v, flags );
	  if (a.size()) return a;
     }

     //cerr << "failures.size() = " <<failures.size() << endl;
     vector<unsigned int> a;
     return a;
}

int main( int argc, char ** argv )
{
     unsigned int t;
     cin >> t;

     for (auto i=1u; i<=t; i++) 
     {
	  unsigned int k;
	  unsigned int n;
	  
	  cin >> k;
	  cin >> n;

	  vector<chest> chests;
	  chests.resize(n);
	  
	  unordered_multiset<unsigned int> keys;
	  for (auto j=0u; j<k; j++)
	  {
	       unsigned int key;
	       cin >> key;
	       keys.insert(key);
	  }

	  for (auto j=0u; j<n; j++)
	  {
	       unsigned int n_keys;
	       cin >> chests.at(j).lock_type;
	       cin >> n_keys;
	       for (auto r=0u; r<n_keys; r++)
	       {
		    unsigned int key;
		    cin >> key;
		    chests.at(j).keys.insert(key);		    
	       }
	  }

	  
	  auto a = solve( keys, chests );

	  cout << "Case #" << i << ": ";

	  if (a.size() == 0)
	  {
	       cout << "IMPOSSIBLE";
	  }
	  else
	  {
	       for (auto x : a )
	       {
		    cout << x+1 << " ";
	       }
	  }

	  cout << endl;
     }

     return 0;
}

