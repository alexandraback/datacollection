#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>
using namespace std;

int t, n, d[10], h[10];

int main(){
	ifstream fin("C.in");
	ofstream fout("out.out");
	fin >> t;
	for(int i = 1; i <= t; ++i){
		fin >> n;
		int ans = 0;
		int lol;
		for(int a = 0; a < n; ++a){
			fin >> d[a] >> lol >> h[a];
		}
			
		if(n > 1){
			if(d[0] > d[1]){
				d[0] -= d[1];
				d[1] = 0;
			}
			else{
				d[1] -= d[0];
				d[0] = 0;
			}
			if(h[1] < h[0]){
				swap(h[1], h[0]);
				swap(d[1], d[0]);
			}
			if(d[1] >= d[0]){
				double temp = (double)h[0] + (double)h[0]*(double)(d[1] - d[0])/360.0;
				double temp2 = (double)h[1]*(double)(360.0-d[1])/360.0;
				if(temp <= temp2) ans = 1;
				if(h[1] == h[0]) ans = 0;
			}
		}
		fout << "Case #" << i << ": " << ans << endl;
	}
	return 0;
}
