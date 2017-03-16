#include<iostream>
#include<fstream>
#include <algorithm>
using namespace std;
ifstream fin("C-small-2-attempt1.in");
ofstream fout("C-small-2-attempt1.out");

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
		long long num;
		int na[10] = {0};
		for(int j = 1; j <= K; j++){
			fin >> num;
			for(int k = 2; k <= M; k++){
				long long t = k;
				int c = 0;
				while(!(num % t)){
					c++;
					t *= t;
				}
				if(na[k] < c){ na[k] = c;}
			}
		}
		
		int d = 0;
		for(int x = 5; x <= M; x++){
			for(int y = 0; y < na[x]; y++){
				fout << x;
				d++;
			}
		}
		if(0 == na[6]){
			for(int y = 0; y < na[3]; y++){
				fout << 3;
				d++;
			}
		}
		if(0 == na[8]){
			for(int y = 0; y < na[4]; y++){
				fout << 4;
				d++;
			}
		}
		if(0 == na[4]){
			for(int y = 0; y < na[2]; y++){
				fout << 2;
				d++;
			}
		}
		while(d < N){
			int co = 2 + (d%2);
			fout << co;
			d++;
		}

		if(r < R){ fout << endl; }
		}
	}
	return 0;
}