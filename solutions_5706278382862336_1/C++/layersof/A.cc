#include <iostream>

using namespace std;

void euclid(long long int& P, long long int& Q){
  long long P_=P, Q_=Q, R_;
  while((R_ = (P_ % Q_)) != 0){
	P_ = Q_;
	Q_ = R_;
  }
  Q = Q/Q_;
  P = P/Q_;
}
int main(){
  int T;
  long long int P, Q;
  char slash = '/';
  cin >> T;
  for(int i=0;i<T;++i){
	cin >> P >> slash >> Q;
    cerr << P << " " << Q << " -> ";
	euclid(P,Q);
    cerr << P << " " << Q << endl;
	const long long int one = 1;
	int count = 0;
	int last = 0;
	for(int k = 0;k<=40;++k){
	  if(((one << k) & Q) != 0){
		count++;
		last=k;
	  }
	}
	if(count!=1){
	  cerr << "cant normalized" << endl;
	  cout << "Case #" << i+1 << ": " << "impossible" << endl;
	  continue;
	}
	int j=41;
	for(;j>=-1;j--){
	  if(j==-1)break;
	  if(((one << j) & P) != 0)break;
	}
	if(j==-1 || last-j>40){
	  cout << "Case #" << i+1 << ": " << "impossible" << endl;
	}else{
	  cout << "Case #" << i+1 << ": " << last-j << endl;
	}
  }
  return 0;
}
