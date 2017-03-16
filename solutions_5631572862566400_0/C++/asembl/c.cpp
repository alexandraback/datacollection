#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector> 
using namespace std ;
int a[1001];
bool circle[1001];
bool two[1001];
int visit[1001];
int calc[1001];

int len_cir[1001];
int len_two[1001], go_two[1001];

bool cir(int st, int now) {
     visit[now]++;
     if ( visit[now] == 2 ) {
        if (now == st) {
           len_cir[st]=0;
           return true ;
        }
        return false; 
     }
     if ( cir(st, a[now]) ) {
          len_cir[st]++;
          return true ;
     }
     else
         return false ;
     
}
bool tw(int st, int now) {
     visit[now]++;
     if ( visit[now] == 2 ) {
        if (a[a[now]] == now) {
           len_two[st] =0;
           go_two[st] = now;
           return true;
        }
        return false; 
     }
     if ( tw(st, a[now]) ) {
          len_two[st]++;
          return true;
     }
     else
         return false;
}

void work() {
     int n ;
     cin >> n ;
     memset(len_cir,0,sizeof len_cir);
     memset(len_two,0,sizeof len_cir);
     memset(go_two,0,sizeof len_cir);
     
     for ( int i = 1 ; i <= n ; ++i ) {
         cin >> a[i] ;
     }
     
     for ( int i = 1 ; i <= n ; ++i ) {
         memset(visit,0,sizeof visit);
         circle[i] = cir(i,i);
         memset(visit,0,sizeof visit);
         two[i] = tw(i,i);
     }
     
     int ans = 0 ;
     for ( int i = 1 ; i <= n ; ++i ) {
         if ( circle[i] ) {
            ans = max( ans, len_cir[i] ); 
            //cout << '!' << ans << endl;
         }
     }
     memset(calc,0,sizeof calc);
     for ( int i = 1 ; i <= n ; ++i ) {
         memset(visit,0,sizeof visit);
         tw(i,i);
         int s1,s2;
         
         s1 = go_two[i];
         s2 = a[s1];
         
         calc[s1] = max(calc[s1], len_two[i]);
         calc[s2] = max(calc[s2], len_two[i]);
         
         for ( int j = i+1 ; j <= n ; ++j ) {
             if(visit[j]==0)
             if ( two[i] && two[j] ) { 
                 
                 s1 = go_two[i];
                 s2 = go_two[j];
                 if ( s1 == a[s2] ) {
                      calc[s1] = max( calc[s1], len_two[i] + len_two[j] - 2 );
                      calc[s2] = max( calc[s2], len_two[i] + len_two[j] - 2 );
//                      cout << '!' << ans << endl ;
                 }
             }
         } 
     }
     int sum = 0 ;
     for ( int i = 1 ; i <= n ; ++i ) {
         sum += calc[i];
     } 
     ans = max( ans, sum/2);
     
     cout << ans << endl;
     
}

int main() {
    
    int T ;
    cin >> T ;
    for ( int cases = 1 ; cases <= T ; ++cases ) {
        cout << "Case #" << cases << ": "; 
        work();
    }
    
    return 0;
} 
