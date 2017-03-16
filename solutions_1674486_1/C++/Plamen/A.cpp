#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int N;
vector <int> v[1000];

bool used[1000], f;

void dfs( int x, int y )
{ 
  if( x == y )  { f = 1; return; }
  used[x] = 1;
  
  for( int i = 0; i < v[x].size(); i++ )
  { 
    if( !used[v[x][i]] )  dfs(v[x][i], y);
    if( f )  return;
   }
}


void dfs2( int x, int y, int br )
{ 
  if( x == y && br > 1 )  { f = 1; return; }
  if( x == y && br == 1 ) return;
  used[x] = 1;
  
  for( int i = 0; i < v[x].size(); i++ )
  { 
    if( !used[v[x][i]] )  dfs2(v[x][i], y, br+1);
    if( f )  return;
   }
}


int main()
{ 
  //freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  
  int T;
  scanf("%d", &T);
  
  for( int i = 1; i <= T; i++ )
  { 
    
    scanf("%d", &N);
    for( int j = 0; j < N; j++ )
    { 
      int n, d;
      scanf("%d", &n);
      for( int p = 0; p < n; p++ )
      { 
        scanf("%d", &d);
        v[j].push_back(d-1);
       }
     }
    
    bool ans = 0;
    int br = 0;
    for( int x = 0; x < N; x++ )
    { 
      if( ans )  break;
      for( int y = 0; y < N; y++ )
      { 

        if( x != y )
        { 
          int t;
          for( t = 0; t < v[x].size(); t++ )
          if( v[x][t] == y )  break;
          
          if( t < v[x].size() )  
          { 
            br = 0;
            f = 0;
            dfs2(x, y, br);
            if( f )  { ans = 1; break; }
           }
          
          else
          { 
            
            f = 0;
            dfs(x, y);
            
            if( f )
            {
              used[y] = 0;
              f = 0;
              dfs(x, y);
              if( f )  { ans = 1; break; }
             }
           }
          
          memset(used, 0, sizeof(used));
         }
       }
     }
   
    if( ans )  printf("Case #%d: Yes\n", i);
    else       printf("Case #%d: No\n", i);
    
    for( int t = 0; t < N; t++ )
    v[t].clear();
   }
  
  //scanf("%d", &T);
  return 0;
}

/*
3
3
1 2
1 3
0
5
2 2 3
1 4
1 5
1 5
0
3
2 2 3
1 3
0
*/
