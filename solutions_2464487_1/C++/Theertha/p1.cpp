#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <inttypes.h>
using namespace std;
int main()
{
  int T1;
  uint64_t t,r;
  uint64_t temp,i,j,max;
  uint64_t binmin,binmax;
  cin >> T1;
  for(i=0;i<T1;i++){
	cin >> r;
	cin >> t;
	temp =0;
	max = 0;
	if (max*r <=t){
		max = uint64_t(t/r);
	}
	if (2*max*max >=t){
		max = 5*uint64_t(sqrt(t));
	}
	j=1;
	binmin=1;
	binmax = max;
	while(binmin +1< binmax){
		j = uint64_t((binmin+binmax)/2);
		if(2*j*j+2*r*j <= t+j){
			binmin = j;
		}
		if(2*j*j+2*r*j >= t+j){
			binmax = j;
		}
	}
	j = binmax;
	if(2*j*j+2*r*j <= t+j){
	 cout << "Case #" << i+1 << ": " << j << endl;
	}else{
	 cout << "Case #" << i+1 << ": " << binmin << endl;
	}
		
  }
  return 0;
}
