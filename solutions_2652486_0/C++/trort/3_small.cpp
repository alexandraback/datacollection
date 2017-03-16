#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<sstream>
#include<vector>
#include<cstdlib>

using namespace std;

const double PI=3.14159265358979323846264338327950288;
ifstream fin;
ofstream fout;

void _main(){
	int R,N,M,K;
	int product[20];
	int i,j,k;
	int digit[20];
	int possible[100];
	int count;
	
	fin>>R>>N>>M>>K;
	for(int line=0;line<R;line++){
		for(i=0; i<K; i++) fin>>product[i];
		for(int attempt = 0; attempt < 100; attempt ++){
			for(i=0; i<N; i++) digit[i]=(rand()%(M-1)) + 2;
			count = 0;
			for(j=0;j<(1<<N);j++){
				int p = 1;
				for(k=0;k<N;k++){
					if(j & (1<<k)) p*=digit[k];
				}
				possible[count++] = p;
			}
			bool all_good = true;
			for(i=0; i<K; i++){
				bool good = false;
				for(j=0; j<count; j++) if(possible[j]==product[i]) {
					good = true;
					break;
				}
				if(!good){
					all_good = false;
					break;
				}
			}
			if(all_good) break;
		}
		for(i=0; i<N; i++) fout<<digit[i];
		fout<<endl;
	}
}

int main(){
    fin.open("sample.in");
    fout.open("result.out");
    int T;
    fin>>T;
    for(int i=0;i<T;i++){
            fout<<"Case #"<<i+1<<":"<<endl;
            cout<<"Case #"<<i+1<<" is runing"<<endl;
            _main();
            fout<<endl;
    }
}
