#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;
int n,m,k;
long long board;

int setBits(int x)
{
  int c = 0;
  while (x)
  {
    if (x%2==1)
      c++;
    x/=2;
  }
  return c;   
}

bool isSet(int x,int y)
{
  return bool(board&(1<<(x*n+y)));
}

long long visited = 0;
bool isOpen(int x,int y)
{
  if (visited&(1<<(x*n+y)))
    return false;
  visited |= 1<<(x*n+y);
  if (isSet(x,y))
    return false;
  if (x==0)
    return true;
  if (x==m-1)
    return true;
  if (y==0)
    return true;
  if (y==n-1)
    return true;
  if (isOpen(x-1,y)) return true;
  if (isOpen(x+1,y)) return true;
  if (isOpen(x,y-1)) return true;
  if (isOpen(x,y+1)) return true;
  return false;
}

int main()
{
  int T;
  cin>>T;
  for (int t = 1;t<T+1;t++)
  {
    cin>>n>>m>>k;
    board = 0;
    int minn=k;
    while ((board&(1<<(n*m))) == 0)
    {
      board++;
      int count = 0;
      //cout<<board<<endl;
      for (int x = 0;x<m;x++)
        for (int y = 0;y<n;y++)
        {
          visited = 0;  
          //cout<<x<<' '<<y<<' '<<isOpen(x,y)<<endl;
          if (not isOpen(x,y)) count ++;
          }
      if (count>=k)
      {
        //cout<<setBits(board)<<endl;
        minn = min(minn,setBits(board));
        //break;
      }
    }
    cout<<"Case #"<<t<<": "<<minn<<endl;
  }
   
}