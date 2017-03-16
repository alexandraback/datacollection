#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
  int T;
  double A,B;
  vector <double> prob;
  int i,j,k;
  double temp;
  double minimum;
  double product;
  double temp2;
  
  cin >> T;
  for(i=0;i<T;i++){
    cin >> A;
    cin >> B;
    for(j=0;j<A;j++){
      cin >> temp;
      prob.push_back(temp);
    }
    minimum = B+2;
    product =1;
    for(j=0;j<A;j++){
      product = product*prob[j];
      temp2 =2*B+A-2*j-product*(B+1);
   //   cout << temp2<< endl;
      if(temp2 < minimum){
	minimum = temp2;
      }
    }
  //  cout << A << B << endl;
    cout << fixed;
    cout.precision(6);
    cout << "Case #" << i+1 << ": "<< minimum << endl;
    prob.clear();
  }
  return 0;
}