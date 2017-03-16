#include<iostream>
#include<vector>
#include<cstring>
#include<list>
#include<map>
#include<iomanip>

using namespace std;

string ans;
int graph[1010][1010];
int vis[1010];
int coun[1010];
int n;
void dfs( int c )
{
     
    
     vis[c] = 1;
     
     if( ans == "Yes" )
         return;

     for ( int i = 0; i < n; i++ ) {
         if( graph[c][i] ) {
             if( coun[i]  ) {
                 ans = "Yes";
                 return;
             } else {
                    coun[i] = 1;
                    dfs( i );
             }
         }
     }
}
int main()
{
    int t;
    cin >> t;
    int  k; 
    int c;   

    int st = 1;
    while( t )
    {
     
           t--;
           cin >> n;
           ans = "No";
           memset( graph ,  0 , sizeof( graph ) ); 
           memset( vis ,  0 , sizeof( vis) );            
           for ( int i = 0; i < n; i++ ) {
               cin >> c;
               
               for (int j = 0; j < c; j++ ){
                        cin >> k;
                        graph[k-1][i] = 1;
               }     
           }
           for ( int i = 0; i < n; i++ ) {
               if( !vis[i] && ans == "No" ) {
                   memset(coun ,  0 , sizeof( coun ) );            
                   dfs( i );
               }
           }
           
           cout << "Case #" << st << ": " << ans;
           
           if( t != 0 )
            cout << "\n";
           
           st++;
     
    }
    
    return 0;
}
