#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

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
void refresh(int &res, int newres){
  res = min(res, newres);
}
int main(){
  int T;
  int N, M, K;
  cin >> T;
  for(int i=0;i<T;++i){
	cin >> N >> M >> K;
	int solution = N*M;
	if(N<=2 || M<=2 || K<=5){
	  cout << "Case #" << i+1 << ": " << K << endl;
	  continue;
	}
	for(int r=0; r<=4; ++r){
	  int prod = K + 4 - r;		//  == N_ * M_;
	  if(prod > N*M-r)break;
	  for(int N_ = prod/M; N_<=N; ++N_){
		int M_ = prod / N_;
		for(int M_ = M; M_>=prod/N_;--M_){
		  if(prod == M_*N_){
			refresh(solution, 2*(N_+M_)-8+r);
		  }else if(prod < M_*N_){
			// cerr << N_ << M_ << endl;
			for(int d=1;d<=min(N_,M_)-3;++d){
			  if(K == // M_*N_ - (d*(d+1))/2
				 N_*M_-4+r-(d*(d+1))/2-d
				 ){
				refresh(solution, 2*(N_+M_)-8+r - d);
				// cerr << "kezuri:" << solution << ',' << d << ',' << N_ << ',' << M_ << ',' << r << ',' << endl;
			  }else{
				int l = max(M_,N_) - 3 -d;
				if(N_*M_-4+r-(d*(d+1))/2-d - l<= K && K < N_*M_-4+r-(d*(d+1))/2-d){
				  refresh(solution, 2*(N_+M_)-8+r - d);
				}
			  }
			}
		  }
		}
	  }
	}
	cout << "Case #" << i+1 << ": " << solution << endl;
  }
  return 0;
}
