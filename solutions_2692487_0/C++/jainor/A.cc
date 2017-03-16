#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <numeric>
#include <utility>
#include <deque>
#include <stack>
#include <bitset>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
  int t;
  cin >> t;
  unsigned long long a , num[1000005] ;
  long long n , ans , cur ;
  for( int caso  = 1 ; caso  <= t ; ++caso ){
    cout << "Case #"<<caso<<": ";
    cin >> a >> n ;
	ans = 1<<30;
	cur = 0;
	for(int i = 0 ; i < n; ++i){
		cin >> num[i];
	}
	sort(num,num+n);
	bool ok = true;
	for(int i = 0 ; i < n; ++i){
        ans = min( ans , cur + n - i );
		if( a == 1 ) {  ok = false ; break; }
        
		if( a <= num[i] ){

		   while( a <= num[i] )
			   a += a-1 , ++cur;
		}
		a += num[i];
   }
   if( ok ) ans = min( ans , cur );
   cout << ans <<endl;
  }

}
