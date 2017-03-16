#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
  int T1;
  long t,r;
  long temp,i,j;
  cin >> T1;
  for(i=0;i<T1;i++){
	cin >> r;
	cin >> t;
	temp =0;
	for(j=1;j<150;j++){
		if(2*j*j+2*r*j <= t+j){
			temp =j;
		}
	}
	 cout << "Case #" << i+1 << ": " << temp << endl;
  }
  return 0;
}
