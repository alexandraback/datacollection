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

unsigned int iterations;

struct chest
{
     unsigned int lock_type;
     unordered_multiset<unsigned int> keys;
};

bool is_plausible( unordered_multiset<unsigned int> keys,
		   vector<chest> &v,
		   vector<unsigned int> flags )
{
     unsigned int i;

     bool again;
     do
     {
	  again = false;

	  for (i=0; i<v.size(); i++)
	  {
	       if (flags.at(i) == 0)
	       {
		    if (keys.find(v.at(i).lock_type) != keys.end())
		    {
			 keys.insert( v.at(i).keys.begin(), v.at(i).keys.end());
			 flags.at(i) = 1;
			 again = true;
		    }
	       }
	  }
     } while(again);
	  
     for (i=0; i<v.size(); i++)
     {
	  if (flags.at(i) == 0)
	  {
	       return false;
	  }
     }

     return true;
}

vector<unsigned int> search( unsigned int target,
			     unordered_multiset<unsigned int> keys,
			     vector<chest> &v,
			     vector<unsigned int> flags )
{
     iterations++;
     vector<unsigned int> e;
     if (keys.find( v.at(target).lock_type) == keys.end())
     {
	  return e;
     }

     flags.at(target) = 1;

     keys.erase( keys.find(v.at(target).lock_type) );

     keys.insert( v.at(target).keys.begin(), v.at(target).keys.end());
 
     if (!is_plausible(keys,v,flags))
     {
	  //cout << "Not plausible" << endl;
	  return e;
     }
    
     bool searched = false;
     for (auto i=0u; i<v.size(); i++)
     {
	  if (flags.at(i) == 0)
	  {
	       searched = true;
	       auto a = search( i, keys, v, flags );
	       if (a.size())
	       {
		    vector<unsigned int> b;
		    b.push_back(target);
		    for (auto x : a) b.push_back(x);
		    
		    return b;
	       }
	  }
     }

     if (searched)
     {
     }
     else
     {
	  e.push_back(target);
     }
     return e;
}

vector<unsigned int> solve( unordered_multiset<unsigned int> keys,
			    vector<chest> v )
{
     vector<unsigned int> e;
     iterations=0;

     auto keys1 = keys;
     for (auto &x : v )
     {
	  keys1.insert(x.keys.begin(), x.keys.end());
     }

     for (auto &x : v )
     {
	  if (keys1.find(x.lock_type)== keys1.end())
	  {
	       return e;
	  }
	  keys1.erase(keys1.find(x.lock_type));
     }

     vector<unsigned int> flags(v.size());
     for (auto &x: flags) x=0;

     for (auto t=0u; t<v.size(); t++)
     {
	  auto a = search( t, keys, v, flags );
	  if (a.size()) return a;
     }

     return e;
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

