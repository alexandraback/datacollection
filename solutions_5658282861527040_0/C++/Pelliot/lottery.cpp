#include<iostream>
#include<vector>
#include<algorithm>



using namespace std;

int main() {
  int min1,min2,to_win;
  int i,j;
  int n_testcase;
  int t;
  int tot;
  cin >> n_testcase;
  for(t=0;t<n_testcase;t++) {
    tot=0;
    cin >> min1 >> min2 >> to_win;
    for(i=0;i<min1;i++) 
      for(j=0;j<min2;j++) 
	if((i&j)<to_win) 
	  tot++;
    cout << "Case #" << t+1 << ": " << tot << endl;
  }
}
    
