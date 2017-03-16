#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;

int noOfDigits(int b) {
  int ret = 0;
  while (b != 0) {
    ret++;
    b = b/10;
  }
  return ret;
}

int recycled(int a, int b){
  int mid = (a + b)/2;
  int count = 0;
  // int mark[b];
  // for (int i = 0; i < b; i++) {
  //   mark[i] = 0;
  // }
  int ndigits = noOfDigits(b);  
  int mFac = pow(10, ndigits - 1);
  bool flag = 0;
  //cout<<ndigits<<" "<<mFac<<endl;
  for (int i = a; i <= b; i++) {
    //if (mark[i] == 1) continue;
    //flag = 0;
    int orig = i;
    int temp = i;
    //int thiscnt = 0;
    temp = mFac*(temp%10) + temp/10;
    while (temp !=orig){
      if (temp <= b && temp >= a && temp > orig) {
	//cout<<orig<<" "<<flush;
	//flag = 1;
	//thiscnt++;
	count++;
	//mark[temp] = 1;
      }
      temp = mFac*(temp%10) + temp/10;
    }
    //if (flag) cout<<" "<<thiscnt<<endl;
  }
  return count;  
}

int main ()
{
  int T;
  cin>>T;
  int A, B;
  for (int i = 0; i < T; i++){
    cin>>A>>B;
    cout<<"Case #"<<i+1<<": "<<recycled(A, B)<<endl;
  }

}
