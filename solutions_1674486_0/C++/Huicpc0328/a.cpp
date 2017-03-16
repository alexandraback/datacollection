#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

const int N = 1005;
int que[N] , vis[N];
vector<int>adj[N];


int main() {
    int test, i , j, n;
    scanf("%d",&test);
    for( int tc = 1; tc <= test; tc++) {
         scanf("%d",&n);
         
         for( i = 0 ; i <= n;i++ ) adj[i].clear();
         
         for( i = 1 ; i <= n;i++ ) {
              int  m , pre;
              scanf("%d",&m);
              for( j = 0 ; j < m;j++ ) {
                   scanf("%d",&pre);
                   adj[pre].push_back( i );
              }     
         }
         
         int flag = 0;
         for( i = 1; i <= n;i++ ) {
              int head = 0 ,tail = 0;
              memset( vis , 0, sizeof( vis ));
              que[tail++] = i; vis[i] = 1;
              while( head < tail ) {
                     int cur = que[head++];
                     if( flag ) break;
                     for( j = 0 ; j < adj[cur].size();j++ ) {
                          int next = adj[cur][j];
                          if( vis[next] == 1 ) {
                              flag = 1;break;
                          } else {
                            vis[next] = 1;
                            que[tail++] = next;       
                          }
                     }                     
              }
              if( flag ) break; 
         }
         printf("Case #%d: %s\n",tc,(flag==1)?"Yes":"No");
    }
    //while(1);
    return 0;
}

