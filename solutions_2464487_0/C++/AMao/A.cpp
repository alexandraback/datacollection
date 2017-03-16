#include<iostream>
#include<cmath>
#define PI 3.1415926

using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i = 0;i<t;i++){
		long long r,t;
		cin >> r >> t;
		cout << "Case #" << i+1 << ": " ;
		if(r > 60000) {
			long long cnt = 0;
			while(t>0) {
				t -= (r+cnt);
				cnt ++;
			}
			cout << (cnt-1)/2 << endl;
		}
		else {
			long long sqrtDelta = sqrt(r*r*4 - 4*r+1 + 8 * t);
			long long cnt = sqrtDelta - 2*r +1;
			cout << cnt/4 << endl;
		}
	}
}
