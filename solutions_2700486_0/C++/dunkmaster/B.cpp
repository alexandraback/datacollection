#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>

#define PI 3.14159265358979323846
using namespace std;

double choose(int K,int N){
	if(K==N) return 1;
	if(K>N) return 0;
	if(K==0) return 1;
	if(N==0) return 0;
	return choose(K-1,N-1) + choose(K,N-1);
}

int main(){
	int T;
	cin >> T;
	for(int z=1;z<=T;z++){
		int N,X,Y;
		cin >> N >> X >> Y;

		if(X<0) X = -X;
		if(Y<0) Y = -Y;
		
		int layer = (X + Y)/2+1;
		int mountain = layer*(2*layer-1);

		double ans = -1;
		if(N>=mountain){
			ans = 1;
		} else {
			int innermountain = (layer-1)*(2*(layer-1)-1);
			if(N<=innermountain){
				ans = 0;
				goto end;
			}
			int sliding = N - innermountain;
			int height = Y+1;
			if(height>sliding){
				ans = 0;
				goto end;
			}
			if(sliding>=height+(mountain-innermountain)/2){
				ans = 1;
				goto end;
			}
			if(height-1==(layer-1)*2&&sliding<mountain-innermountain){
				ans = 0;
				goto end;
			}
			ans = 0;
			for(int i=height;i <= sliding;i++){
				ans += choose(i,sliding);
			}
			for(int i=0;i<sliding;i++){
				ans /= 2.;
			}
		}end:
		cout<<"Case #"<<z<<": "<<ans<<endl;
	}
}