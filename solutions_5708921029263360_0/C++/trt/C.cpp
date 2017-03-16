#include <bits/stdc++.h>
#define int long long
using namespace std;
int const N = 12;
int jp[N][N] = {0};
int ps[N][N] = {0};
int js[N][N] = {0};
main (){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int z;
	cin >> z;
	for (int i = 0; i < z; ++i){
		
		int J, P, S ,K;
		cin >> J >> P >> S >> K;
		for (int j = 0; j < N; ++j)
		for (int x = 0; x < N; ++x){
			jp[j][x] = 0;
			ps[j][x] = 0;
			js[j][x] = 0;
		}
		vector <int > wyn;
		int wl = 0;
		for (int j = 0; j < J; ++j){
			for (int p = 0; p < P; ++p){
				for (int s = 0 ; s < S; ++s){
					if (jp[j][p] < K)if (ps[p][s] < K) if (js[j][s] < K){
						wyn.push_back(j);
						wyn.push_back(p);
						wyn.push_back(s);
						++jp[j][p];
						++ps[p][s];
						++js[j][s];
						++wl;
					}
				}
			}
		}
		cout <<"Case #" << i+1 << ": " << wl << '\n';
		for (int j = 0; j < wl; ++j){
			cout << wyn[3*j]+1 << ' ' << wyn[3*j+1]+1 << ' ' << wyn[3*j+2]+1 << '\n'; 
		} 
		
	}
}
