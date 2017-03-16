#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<sstream>
#include<climits>
#include<deque>
#include<cassert>
#include<stack>
#include<queue>
#include<ctime>
#include<iomanip>
#define F first
#define S second
#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define all(n) n.begin(),n.end()
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
int mincost;
int memo[1100000];

void rec(VI &vec,int p,int total,int A)
{
  if(p == vec.size())
    {
      //cout << "here" << endl;
      mincost = min(mincost,total);
      return;
    }
  if(memo[p] <= total)return;  

  if(vec[p] < A)
    {
      memo[p] = min(memo[p],total);
      rec(vec,p+1,total,A+vec[p]);
    }
  else
    {
      if(A != 1)
	rec(vec,p,total+1,A+A-1);
      memo[p] = min(memo[p],total+1);
      rec(vec,p+1,total+1,A);
    }
}

int main()
{
  int T;
  int Nari = 1;
  cin >> T;
  while(T-- > 0)
    {
      mincost = (1<<29);
      int A,N;
      cin >> A >> N;
      vector<int> vec(N);
      rep(i,N)memo[i] = (1<<29);
      rep(i,N)cin >> vec[i];
      sort(all(vec));

      rec(vec,0,0,A);
      cout << "Case #" << Nari++ << ": " << mincost << endl;

    }
  return 0;
}



/*
  int cnt = 0;
  rep(i,N)
  {
  if(vec[i] < A)
  {
  A += vec[i];
  continue;
  }

  if(A+(A-1) > vec[i])
  {
  cnt++;
  A += (A-1)+vec[i];
  }	 
  else 
  {
  cnt++;
  }

  }
*/
