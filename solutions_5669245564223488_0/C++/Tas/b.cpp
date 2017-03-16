#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <assert.h>     /* assert */
#include <limits>
#include <set>
#include <map>

using namespace std;


template <typename T>
T read()
{
  std::string line;
  getline(std::cin, line);
  std::istringstream iss(line);
  T i;
  iss >> i;
  return i;
}

template <typename T>
vector<T> readv()
{
  std::string line;
  getline(std::cin, line);
  std::istringstream iss(line);
  T tmp;
  vector<T> v;
  while (iss >> tmp)
  {
    v.push_back(tmp);
  }
  return v;
}

template <typename T>
void printv(const T& v)
{
  for (auto i : v)
    cout << i << " ";
  cout << endl;
}

void test( vector<string> sets)
{
  
//   for ( char c = 'a'; c <= 'z'; c++)
//   {
//     for 
//   }
}


long nways( long n)
{
  int r = 1;
  while (n > 1)
  {
    r*=n;
    n--;
  }
  return r;
}

void bump(map<char, int>& m, char c)
{
  if ( m.count(c))
    m[c]++;
  else
    m.insert( make_pair(c,1) );
}

bool is_good(string s)
{
  set<char> seen;
  char last = 0;
  for (char c : s) 
  {
    if (seen.count(c) && c != last)
      return false;
    seen.insert(c);
    last = c;
  }
  return true;
}

struct solver_t
{
  solver_t( vector<string>& sets) : sets(sets)
  {
    impossible = false;
    N = 0;
    
    for (auto& s : sets)
    {
      set<char> tmp( s.begin(), s.end());
      
      assert ( tmp.size() != 0);
      
      if (tmp.size() == 1) 
      {
	homogen.insert(s);
	bump(homo, s[0] );
	seen.insert( s[0] );
	continue;
      }
      
      if ( ! is_good(s) )
      {
	impossible = true;
	return;
      }
      
      char l = s[0];
      char r = s[ s.size() - 1];
     
      // left can only see rights
      if ( left.count(l) || center.count(l) ) {
	impossible = true;
	return;
      }
      lms[l] = s;
      bump(left, l );
     
      // right can only see lefts
      if ( right.count(r) || center.count(l)) {
	impossible = true;
	return;
      }
      bump (right, r );
      rms[r] = s;
      
      // center cannot see anything
      char last = 0;
      for ( char c : s)
      {
	if ( c != l && c != r) {
	  if (seen.count(c) && c != last) {
	    impossible = true;
	    return;
	  }
	  seen.insert(c);
	  bump(center, c);
	  last = c;
	}
      }
      
      for ( char c : s)
	seen.insert(c);
      
    }
  }
  
  void solve()
  {
    set<string> tomatch;
    int nblocks = 0;
    vector<long> bsizes;
    vector<string> blocks;
    
    
    
    for (auto s : sets)
    {
      if (homogen.count(s) == 0)
	tomatch.insert(s);
    }
    
    while ( ! tomatch.empty() )
    {
      long bsize = 1;
      string s = *tomatch.begin();
      tomatch.erase(s);

      while (true)
      {
	char l = s[0];
	char r = s[ s.size() - 1];
      
	if ( homo.count(l) ) {
	  bsize *= nways(homo[l]);
	  homo.erase(l);
	}
	
	if (homo.count(r) ) {
	  bsize *= nways(homo[r]);
	  homo.erase(r);
	}
	
	bool tobreak = true;
	
	if ( left.count(r) )
	{
	   s = s + lms[r];
	   left.erase(r);
	   tomatch.erase( lms[r] );
	   tobreak = false;
	}
	
	if ( right.count(l) )
	{
	  right.erase(l);
	  s = rms[l] + s;
	  tomatch.erase( rms[l] );
	  tobreak = false;
	}
	
	
	if (tobreak)
	  break;
      }
      
      //cout << ">>>";
      nblocks++;
      bsizes.push_back( bsize);
      //printv( tomatch);
      //cout << s << endl;
      //cout << "%%%";
      
    }
    
    for ( auto hopts : homo)
    {
      int n = hopts.second;
      int bsize = nways(n);
      nblocks++;
      bsizes.push_back(bsize);
    }
    
    assert ( nblocks == bsizes.size());
    
    int q = nblocks;
    unsigned long result = 1;
    
    for ( int bsize : bsizes)
    {
      result *= q*bsize;
      q--;
    }
    
    N = result;
    
  }
  
  map<char, string> lms, rms;
  map<char, int> left, right, center, homo;
  set<char> seen;
  vector<string> sets;
  set<string> homogen;
  bool impossible;
  unsigned long N;
};


void proc_case()
{
  int n = read<int>();
  vector<string> sets = readv<string>();
  assert (n == sets.size());
  //printv(sets);
  solver_t slv(sets);
  int r = -1;
  if ( slv.impossible )
    r=0;
  else {
    slv.solve();
    r = slv.N;
  }
    
  
  cout << r <<  endl;
  
}


int main()
{
  int t = read<int>();
  for (int i=0; i < t; i++)
  {
    cout << "Case #" << i+1 << ": " ;
    proc_case();
  }
}