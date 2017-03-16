#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int main(){
  int T;
  int A,B;
  double s1,s2,s3;
  double p2=1.0;
  double ret;

  cin >> T;
  for( int i=0; i<T; i++){
    cin >> A;
    cin >> B;
    vector<double> p(A);
    p2=1.0;

    for(int j=0; j<A; j++){
      cin >> p[j];
      p2 *= p[j];
    }

    //s1 = p2*(B-A+1)+(1.0-p2)*(B+1 + B-A+1);
    s1 = (B-A+1)+(1.0-p2)*(B+1);
    s3 = B+2;

    double p3=1.0;
    s2=(s1>s3?s1:s3);
    for(int j=0; j<A-1; j++){
      double tmp;
      p3*=p[j];
      //tmp = p3*(B - (A-1-(A-j) ) + 1)+(1-p3)*();
      tmp = ( B-j+(A-1-j) )+(1.0-p3)*(B+1);
      if(s2>tmp){
        s2=tmp;
      }
    }

    if( s1>s3 ){
      if(s3>s2){
        ret = s2;
      }else
        ret = s3;
    }else{
      if(s1>s2){
        ret = s2;
      }else
        ret = s1;
    }
    //cout << s1 << " " << s2 << " " << s3 << " " <<  endl;
    cout.precision(6);
    cout << setiosflags(ios::fixed);
    cout << "Case #" << i+1 << ": " << ret << endl;
  }

};
