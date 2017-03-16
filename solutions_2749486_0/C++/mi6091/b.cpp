#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
int dx[] = { +1, -1, 0, 0};
int dy[] = { 0, 0, +1, -1};
string cool[] = {"E", "W", "N", "S" };

map < pair<int, int>, int > prev;
map < pair<int, int>, int > used;

queue < pair<int, int> > q;
#define mp make_pair

string bfs (pair <int, int> dest)
{
   prev.clear ();
   used.clear ();
   used[mp(0, 0)] = 1;
   prev[mp(0, 0)] = -1;
   q.push(mp(0, 0));
   int i, found = 0;
   while (!q.empty())
   {
     pair <int, int> temp = q.front();
     q.pop();
     int ss = used[temp];
     for (i = 0; i <4; i ++)
     {
        pair <int, int> next = mp (temp.first + ss*dx[i], temp.second + ss*dy[i]);
        if (used.find (next) != used.end ())
           continue;
        
        used[next] = ss + 1;
        prev[next] = i;
        q.push(next);
        if(next == dest)
          found = 1;
           
     }
     if (found)
       break;
     
   }
   
   string res = "";
   int start; 
   while(prev[dest] != -1)
   {
     int o = prev[dest];
     int rr = used[dest] - 1;
     
     res = (string)cool[o] + res;
     dest.first += dx[o] * -1 * rr ;
     dest.second += dy[o] * -1 * rr ;
 
  }
  if (dest.first != 0 || dest.second != 0)
     cout << "bad!" << endl;
  while (!q.empty())
      q.pop();
  return res;
  
}
string solve ()
{
  int x, y;
  scanf ("%d%d", &x, &y);
  
  return bfs (mp(x, y));
    
}
int main ()
{

  int t;
    scanf ("%d", &t);
  for (int i= 1; i <=t; i ++)
    printf ("Case #%d: %s\n", i, solve ().c_str());
  
}
