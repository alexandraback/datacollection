#include <stdio.h>
#include <assert.h>
#include <sstream>
#include <vector>
#include <iostream>
#include <math.h>
#include <queue>
#include <string>
#include <map>

using namespace std;

#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define fr(x,a,b) for( int x = a; x < b; ++x )
#define clr(x) memset(x,0,sizeof(x));
#define _clr(x) memset(x,-1,sizeof(x));

#define ll long long

int dir[8][2] = {0,1,0,-1, 1,0,-1,0};
char dirt[4] = {'N','S','E','W'};
map< pair<int,int>, int> st, path;

void dfs( int x, int y )
{
if( x == 0 && y == 0 )
return;

int i =  path[make_pair(x,y)];
int step = st[make_pair(x,y)] - 1;

int dx = x - dir[i][0]*step;
int dy = y - dir[i][1] * step;

dfs(dx,dy);
printf("%c",dirt[path[make_pair(x,y)]]);
return;
}

void bfs( int dx, int dy )
{

st.clear();
path.clear();

queue< pair<int,int> > q;
q.push( make_pair(0,0) );

st[make_pair(0,0)] = 0;
path[make_pair(0,0)] = -1;

while( !q.empty() )
{
pair<int,int> t = q.front();
q.pop();
int step = st[make_pair(t.first,t.second)] + 1;
if( step > 10 )continue;

for( int i = 0; i < 4; ++i )
{
int x = t.first + dir[i][0] * step;
int y = t.second + dir[i][1] * step;
map<pair<int,int>,int> :: iterator iter = st.find( make_pair( x, y ) );

if( iter == st.end() )
{
q.push( make_pair(x,y) );
st[make_pair(x,y)] = step;
path[make_pair(x,y)] = i;
}
else
{
if( step < iter->second )
{
q.push( make_pair(x,y) );
st[make_pair(x,y)] = step;
path[make_pair(x,y)] = i;
}
}
printf("(%d,%d) x = %d y = %d step = %d %c\n",
t.first,t.second, x,y, st[make_pair(t.first,t.second)], dirt[path[make_pair(x,y)]]);
}
}

pf("%d\n",st[make_pair(dx,dy)]);

//dfs(dx,dy);
}

int main()
{
int T;
sf("%d",&T);

fr(ca,0,T)
{
int x,y;
sf("%d%d",&x,&y);
bfs(x,y);
}
}