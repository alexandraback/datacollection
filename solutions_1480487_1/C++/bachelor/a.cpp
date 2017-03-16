#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

const double eps = 1e-9;
double s[300];
int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int T, N;
	cin>>T;
	double X;
	for(int tt = 1; tt <= T; ++tt){
		cin>>N;
		X = 0;
		for(int i = 0; i < N; ++i){
			cin>>s[i];
			X += s[i];
		}
		cout<<"Case #"<<tt<<":";
		for(int i = 0; i < N; ++i){
			double low = 0.0, high = 100, mid;
			while(fabs(low - high) > eps){
				//cout<<low<<' '<<high<<endl;
				mid = (low + high) / 2.0;
				double point = s[i] + mid * X / 100;
				double dl = 0;
				for(int j = 0; j < N; ++j){
					if(i == j || s[j] >= point)continue;
					dl += (point - s[j]) / X * 100;
				}
				if(dl + mid < 100)low = mid;
				else high = mid;
			}
			printf(" %.7f", high);
//			cout<<' '<<mid;
		}
		cout<<endl;
	}
	return 0;
}
