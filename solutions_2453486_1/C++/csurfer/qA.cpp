#include <vector>
#include <stack>
#include <set>
#include <list>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iomanip>

using namespace std;

#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sf(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define INF (int)1e9
#define LINF (long long)1e18
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(x) ((x)<0?(-(x)):(x))
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define foreach(v,c) for( typeof((c).begin()) v = (c).begin();  v != (c).end(); ++v)

int main()
{
  int tc;s(tc);
  int tco = tc;
  while(tc--)
  {
    char arr[5][5];
    char garbage[4];
    REP(i,4)
    {
      cin>>arr[i];
      cin.getline(garbage,4);
    }

    int tcnt,ocnt,xcnt;
    int t,o,x;
    tcnt = ocnt = xcnt = 0;
    bool undecided = true;
    char mode = 'D';
    //Row wise check
    if(undecided)
    REP(i,4)
    {
      t = o = x = 0;
      REP(j,4)
      {
        switch(arr[i][j])
        {
          case 'T':t++;break;
          case 'O':o++;break;
          case 'X':x++;break;
          default:break;
        }
      }

      if(t+x == 4)
      {
        undecided = false;
        mode = 'X';
      }
      else if(t+o == 4)
      {
        undecided = false;
        mode = 'O';
      }
      else
      {
        tcnt += t;
        ocnt += o;
        xcnt += x;
      }
    }

    //Column Wise
    if(undecided)
    REP(j,4)
    {
      t = o = x = 0;
      REP(i,4)
      {
        switch(arr[i][j])
        {
          case 'T':t++;break;
          case 'O':o++;break;
          case 'X':x++;break;
          default:break;
        }
      }

      if(t+x == 4)
      {
        undecided = false;
        mode = 'X';
      }
      else if(t+o == 4)
      {
        undecided = false;
        mode = 'O';
      }
    }

    //Primary Diagonal wise
    if(undecided)
    {
      t = o = x = 0;
      for(int i=0,j=0;i<4 && j<4;i++,j++)
      {
        switch(arr[i][j])
        {
          case 'T':t++;break;
          case 'O':o++;break;
          case 'X':x++;break;
          default:break;
        }
      }
      if(t+x == 4)
      {
        undecided = false;
        mode = 'X';
      }
      else if(t+o == 4)
      {
        undecided = false;
        mode = 'O';
      }
    }

    //Secondary Diagonal Wise
    if(undecided)
    {
      t = o = x = 0;
      for(int i=0,j=3;i<4 && j>=0;i++,j--)
      {
        switch(arr[i][j])
        {
          case 'T':t++;break;
          case 'O':o++;break;
          case 'X':x++;break;
          default:break;
        }
      }
      if(t+x == 4)
      {
        undecided = false;
        mode = 'X';
      }
      else if(t+o == 4)
      {
        undecided = false;
        mode = 'O';
      }
    }

    //Decision
    if(!undecided)
    {
      if(mode == 'X')
        cout<<"Case #"<<tco-tc<<": X won"<<endl;
      else
        cout<<"Case #"<<tco-tc<<": O won"<<endl;
    }
    else if(tcnt+ocnt+xcnt == 16)
      cout<<"Case #"<<tco-tc<<": Draw"<<endl;
    else
      cout<<"Case #"<<tco-tc<<": Game has not completed"<<endl;
  }
  return 0;
}

