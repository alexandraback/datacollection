// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <tr1/unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
// so much chocolate
#define ff first
#define ss second
#define uint unsigned int
// mylittlepony
using namespace std;
using namespace std::tr1;

int abs(int x) {return (x < 0)?(-x):x;}

int main() {
	int T,N,X,Y;
	cin >> T;
	cout << fixed << setprecision(8);
	
	vector< vector<double> > C(2000);
	for(int i =0; i < 2000; i++) C[i].resize(2000);
	for(int i =0; i < 2000; i++) {
		C[0][i] =0, C[0][0] =1;
		if(i > 0) C[i][0] =C[i-1][0]*0.5;}
	for(int i =1; i < 2000; i++) for(int j =1; j < 2000; j++) 
		C[i][j] =(C[i-1][j-1]+C[i-1][j])*0.5;
	
	for(int t =0; t < T; t++) {
		cout << "Case #" << t+1 << ": ";
		cin >> N >> X >> Y;
		int a =1;
		while(2*a-1 <= N) {
			N -=2*a-1;
			a +=2;}
//		cout << a << " " << N << endl;

		// all diamonds at dist. up to a
		if(abs(X)+Y <= a-3) {
			cout << 1.0 << "\n";
			continue;}
		if(abs(X)+Y > a-1) {
			cout << 0.0 << "\n";
			continue;}
			
		// prob. that num. of diamonds at correct side is >= Y+1
		// sum(C[N][i])/2^N
		// Y+1 <= i <= a-1
		double ans =0.0, ansD =0.0;
		int b =1;
		for(int i =0; i < N; i++) b *=2;
		for(int i =0; i < b; i++) {
			int c =i, x =0, y =0;
			double p =1;
			for(int j =0; j < N; j++) {
				if(c%2 == 1) {
					x++;
					if(x >= a) p =0;
					if(y < a-1) p *=0.5;}
				else {
					y++;
					if(y >= a) p =0;
					if(x < a-1) p *=0.5;}
				c /=2;}
			if(x >= Y+1) ans +=p;
//			cout << x << " " << y << " " << p << endl;
			ansD +=p;}
		cout << ans/ansD << endl;}
    return 0;}
        
// look at my code
// my code is amazing
