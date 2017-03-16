#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;


int main(int argc, char **argv) {
    int T, P, Q;
    double fraction, ancestors, *dummy;
    cin>>T;
    for(int c=1; c<=T; c++) {
      scanf("%d/%d", &P, &Q);
      fraction = (double)P / (double)Q;
      ancestors = pow(2.0,40.0);
      if( modf(ancestors*fraction, dummy) != 0 )
	cout<<"Case #"<<c<<": impossible"<<endl;
      else {
	for(int gen=39; gen>=0; gen--) {
	  ancestors = pow(2.0,(double)gen);
	  if( 1.0/ancestors > fraction ) {
	    cout<<"Case #"<<c<<": "<<gen+1<<endl;
	    break;
	  }	
	}
      }
    }
    return 0;
}
