#include<iostream>
#include<fstream>
#include <algorithm>
using namespace std;
ifstream fin("C-small-1-attempt0.in");
ofstream fout("C-small-1-attempt0.out");

int T=1;


int main()
{
	fout << "Case #" << 1 << ": " << endl;
	fin >> T;
	for(int i = 1; i <= T; i++)
	{
		int R, N, M, K;
		fin >> R >> N >> M >> K;

		for(int r = 1; r <= R; r++){
		int num;
		int na[10] = {0};
		for(int j = 1; j <= K; j++){
			fin >> num;
			for(int k = 2; k <= M; k++){
				int t = k;
				int c = 0;
				while(!(num % t)){
					c++;
					t *= t;
				}
				if(na[k] < c){ na[k] = c;}
			}
		}
		
		int d = 0;
		for(int x = 3; x <= M; x++){
			for(int y = 0; y < na[x]; y++){
				fout << x;
				d++;
			}
		}
		while(d < N){
			fout << 2;
			d++;
		}
		if(r < R){ fout << endl; }
		}
	}
	return 0;
}