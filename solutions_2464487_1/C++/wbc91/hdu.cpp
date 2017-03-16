#include<iostream>
#include<fstream>
#include<cmath>
#include<cstdio>
using namespace std;
void main(){
	ifstream cin("A-small-attempt0.in");
	ofstream cout("2013gcj_RA_A.out");
	int T,r,t;
	cin >> T;
	for(int i = 0; i < T; i++){
		cin >> r >> t;
		int a = 2*r+1;
		double rings = (sqrt((double)((a-2)*(a-2)+8*t))-(double)(a-2))/4;
		cout << "Case #" << i+1 << ": " << floor(rings)<<endl;
	}
	system("pause");
}