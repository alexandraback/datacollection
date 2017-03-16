#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std ;
typedef unsigned long long ull ;
typedef long long ll ;
int main(int argc, char *argv[]) {
   int K ;
   cin >> K ;
   for (int kase=1; kase<=K; kase++) {
     int n ;
     cin >> n ;
     int cnts[10000] ;
     for (int i=0; i<10000; i++)
       cnts[i] = 0 ;
     for (int i=0; i<2*n*n-n; i++) {
       int v ;
       cin >> v ;
       cnts[v]++ ;
     }
     cout << "Case #" << kase << ":" ;
     for (int i=0; i<10000; i++)
       if (cnts[i] & 1)
	 cout << " " << i ;
     cout << endl ;
   }
}
