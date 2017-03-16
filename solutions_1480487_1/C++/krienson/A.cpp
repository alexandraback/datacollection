 /*
*  Javier Segovia
*  0.016
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair

int main(){
	int T;
	cin>>T;
	cout.setf(ios::fixed);
	cout.precision(6);
	for (int kases=1; kases<= T; kases++) {
		int N; cin>>N;
		int A[205], X=0;
		double alpha,beta,aux;
		for (int i=0; i<N ; i++) {
			cin>>A[i]; X+=A[i];
		}
		cout<<"Case #"<<kases<<":";
		for (int i=0; i<N ; i++) {
			alpha = 100.0;
			beta = 0.0;
			double maxi=1.0,mini=0.0,eps=1E-10;
			while (mini+eps<maxi) {
				alpha = (maxi + mini)/2.0;
				aux = 0;
				for (int j=0; j<N ; j++) {
					if(i == j) continue;
					beta = double(A[i] - A[j])/double(X) + alpha;
					if(beta>0.0) aux+=beta;
				}
				//cout<<"A["<<i<<"]: "<<alpha<<" "<<aux<<" -> "<<"("<<maxi<<","<<mini<<")"<<endl;
				if (alpha + aux >= 1.0) {
					maxi = alpha;
				}
				else {
					mini = alpha;
				}
			}
			cout<<" "<<alpha*100.0;
		}
		cout<<endl;
		//A[i] + X*alpha >= A[j] * X*beta ;
	}
}