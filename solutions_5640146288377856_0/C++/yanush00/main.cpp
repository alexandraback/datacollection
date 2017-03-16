#include <iostream>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <queue>
#include <string>

using namespace std;
 
int main() 
{ 
   // freopen("input.txt","r",stdin);
 //    freopen("output.txt","w",stdout); 
	  int t;
	  cin >> t;int j = 0;
	  while(t-- > 0)
	  {
		  j++;
		  int n,m,k,s = 0;
		  cin >> n >> m >> k;
		  for(int i(0);i<n;i++)
		  {
			  s += m / k;
		  }
		  if(k == m ) s = s + k - 1; else
		  if(k != 1) 
		  {
			  s = s + k; 
			  if(m % k == 0 ) s--;
		  }
		  cout <<"Case #" << j <<": " << s << endl;
	  }


} 