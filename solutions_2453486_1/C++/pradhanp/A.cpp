#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define FOR(i,n) for(int i=0;i<n;i++)
#define FOX(i,x) for(int i=0;i<x.size();i++)
#define FO(i,j,n) for(int i=j;i<n;i++)

typedef long long ll;
typedef long double ld;

#define X first
#define Y second
#define PB push_back
#define S(x) sort(x.begin(), x.end())
#define R(x) reverse(x.begin(), x.end())

typedef pair<ll,ll> PL;
typedef vector<int> VI;
typedef vector<PL> VP;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<string> VS;

bool won(VS board, char a)
{
  FOR(i,4)
    FOR(j,4)
    {
      if(board[i][j]=='T')
	board[i][j]=a;
    }

  FOR(i,4)
    {
      int cnt=0;
      FOR(j,4)
	cnt+=(board[i][j]==a);
      if(cnt==4)
	return true;
    }

  FOR(j,4)
    {
      int cnt=0;
      FOR(i,4)
	cnt+=(board[i][j]==a);
      if(cnt==4)
	return true;
    }

  int cnt=0;
  FOR(i,4)
    cnt+=(board[i][i]==a);
  if(cnt==4)
    return true;
  cnt=0;
  FOR(i,4)
    cnt+=(board[i][3-i]==a);
  if(cnt==4)
    return true;

  return false;
}

bool finished(VS a)
{
  FOR(i,4)
    FOR(j,4)
    {
      if(a[i][j]=='.')
	return false;
    }
  return true;
}

string result(VS a)
{
  if(won(a,'X'))
    return "X won";
  if(won(a,'O'))
    return "O won";
  if(not finished(a))
    return "Game has not completed";
  return "Draw";
}

int main()
{
  int t;
  cin>>t;
  FO(i,1,t+1)
    {
      VS inp(4);
      FOR(k,4)
	cin>>inp[k];
      printf("Case #%d: %s\n", i, result(inp).c_str());
    }
  return 0;
}
