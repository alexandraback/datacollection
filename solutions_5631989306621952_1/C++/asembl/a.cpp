#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std ;
const int maxn = 100000;
char str[maxn];
char last[maxn], new1[maxn], new2[maxn];
 
void work() {
     cin >> str ;
     int l = strlen(str); 
     memset(last,0,sizeof last);
     memset(new1,0,sizeof new1);
     memset(new2,0,sizeof new2);
     for ( int i = 0 ; i < l ; ++i ) {
         new1[0] = str[i];
         for ( int j = 0 ; j < i ; ++j ) {
             new1[j+1] = last[j];
             new2[j] = last[j];
         }
         new2[i] = str[i];
         if ( strcmp(new1,new2) > 0 ) {
              for ( int j = 0 ; j <= i ; ++j )
                  last[j] = new1[j];
         }
         else
             for ( int j = 0 ; j <= i ; ++j )
                 last[j] = new2[j]; 
     }
     cout << last << endl ;
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
