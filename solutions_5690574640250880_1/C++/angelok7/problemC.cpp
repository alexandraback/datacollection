#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int n,N;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	fin>>N;

	for(n=0;n<N;n++){
		int R,C,M;
		fin>>R>>C>>M;
		int i,j;
		char map[51][51];
		memset(map,0,51*51*sizeof(char));
		
		map[0][0] = 'c';
		int P = R*C - M;
		fout<<"Case #"<<n+1<<":"<<endl;
		if(M == 0){
			for(i=0;i<R;i++){
				for(j=0;j<C;j++){
					if(map[i][j] == 0)
						fout<<'.';
					else
						fout<<map[i][j];
				}
				fout<<endl;
			}
			continue;
		}
		if(P == 1){
			for(i=0;i<R;i++){
				for(j=0;j<C;j++){
					if(map[i][j] == 0)
						fout<<'*';
					else
						fout<<map[i][j];
				}
				fout<<endl;
			}
			continue;
		}

		if(C == 1 || R == 1){
			if(P>=1){
				for(i=R-1;i>=0;i--){
					for(j=C-1;j>=0;j--){
						if(M-- > 0)
							map[i][j] = '*';
					}
				}
				for(i=0;i<R;i++){
					for(j=0;j<C;j++){
						if(map[i][j] == 0)
							fout<<'.';
						else
							fout<<map[i][j];
					}
					fout<<endl;
				}
			}
			else{
				fout<<"Impossible"<<endl;
			}
			continue;
		}
		int p,k;
		for(i=R;i>1;i--){
			for(j=C;j>1;j--){
				if(i*j <= P && i*j + i + j >= P){
					int t = P-i*j;
					if(t == 0)
						break;
					if(t == 1)
						continue;
					if(t<=i && j+1 <= C)
						break;
					if(t<=j && i+1 <= R)
						break;
					if(i+1 > R || j+1 > C)
						continue;
					for(p=2;p<=i;p++){
						for(k=2;k<=j;k++){
							if(p+k == t)
								break;
						}
						if(k<=j)
							break;
					}
					if(p<=i)
						break;
				}
			}
			if(j!=1)
				break;
		}
		if(i==1){
			fout<<"Impossible"<<endl;
			continue;
		}
		
		for(int pp=0;pp<i;pp++)
			for(int kk=0;kk<j;kk++)
				map[pp][kk] = '.';

		if(P == i*j){

		}
		else if(P-i*j <= i && j+1<=C){
			for(int pp=0;pp<P-i*j;pp++)
				map[pp][j] = '.';
		}
		else if(P-i*j <= j && i+1<=R){
			for(int pp=0;pp<P-i*j;pp++)
				map[i][pp] = '.';
		}
		else{
			for(int pp=0;pp<k;pp++)
				map[pp][j] = '.';
			for(int pp=0;pp<p;pp++)
				map[i][pp] = '.';
		}

		map[0][0] = 'c';
		for(i=0;i<R;i++){
			for(j=0;j<C;j++){
				if(map[i][j] == 0)
					fout<<'*';
				else
					fout<<map[i][j];
			}
			fout<<endl;
		}
	
	}


	return 0;
}
