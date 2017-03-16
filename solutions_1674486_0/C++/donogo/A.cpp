#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <stdio.h>

using namespace std;

void dbgset(set <int> S)
{
  set <int> :: iterator it;

  for (it = S.begin(); it != S.end(); it++) {
    cout << *it << ", " ;
  }
  cout << endl;
}


set <int> prev(int N, vector < set <int> > From, int me)
{
  set <int> P;
  set <int> PP, S;
  set <int>::iterator it, jt;
  
  if (From[me].size() == 0) {
    return P;
  }
  PP = P = From[me];
  for (it = P.begin(); it != P.end(); it++) {
    S = prev(N, From, *it);
    for (jt = S.begin(); jt != S.end(); jt++) {
      PP.insert(*jt);
    }
  }
  return PP;
}

int isdiamond(int N, vector < set <int> > From)
{
  int me, fa, mo;

  for (me = 1; me <= N; me++) {
    if (From[me].size() < 2) {
      continue;
    }
    set <int>::iterator it;
    set <int>::iterator jt;
    set <int>::iterator kt;

    for (it = From[me].begin();
	 it != From[me].end(); it++) {
      set <int> FA;
      FA = prev(N, From, *it);
      FA.insert(*it);
      //      cout << "*fathers*of*" << me << endl;
      //      dbgset(FA);

      jt = it;
      jt++;
      while (jt != From[me].end()) {
	set <int> MO;
	MO = prev(N, From, *jt);
	MO.insert(*jt);
	for (kt = MO.begin(); kt != MO.end(); kt++) {
	  if (FA.find(*kt) != FA.end()) {
	    return 1;
	  }
	}
	jt++;
      }
    }
  }
  return 0;

}




int main(void)
{
  int T, c;
  int N;
  int m, x;
  int i, j;
  int r;

  cin >> T;

  for (c = 1; c <= T; c++)  {
    vector < set <int> > From;
    set <int> S;
    From.push_back(S);

    cin >> N;
    for (i = 0; i < N; i++) {
      set <int> T;
      cin >> m;
      for (j = 0; j < m; j++) {
	cin >> x;
	T.insert(x);
      }
      From.push_back(T);
    }

    //    for (i = 1; i <= N; i++) {
      //      cout << "i=" << i << endl;
    //      dbgset(From[i]);
    //    }

    r = isdiamond(N, From);

    cout << "Case #" << c << ": ";
    cout << (r ? "Yes" : "No") << endl;

  }
  

  return 0;

}


